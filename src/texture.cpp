#include "texture.h"
#include "CGL/color.h"

#include <algorithm>
#include <cmath>

namespace CGL {

Color Texture::sample(const SampleParams &sp) {
  // TODO: Task 6: Fill this in.
  // return magenta for invalid level
  if (sp.lsm == L_ZERO) {
      if (sp.psm == P_NEAREST) {
          return sample_nearest(sp.p_uv, 0);
      } else {
          return sample_bilinear(sp.p_uv, 0);
      }
  }
  if (sp.lsm == L_NEAREST) {
      if (sp.psm == P_NEAREST) {
          return sample_nearest(sp.p_uv, floor(get_level(sp)));
      } else {
          return sample_bilinear(sp.p_uv, floor(get_level(sp)));
      }
  }
  if (sp.lsm == L_LINEAR) {
      float nearLevel = get_level(sp);
      int lower = floor(nearLevel);
      int upper  = lower + 1;
      if (sp.psm == P_NEAREST) {
          return (nearLevel - lower) * sample_nearest(sp.p_uv, lower) + (upper - nearLevel)* sample_nearest(sp.p_uv, upper);

      } else {
          return (nearLevel - lower) * sample_bilinear(sp.p_uv, lower) + (upper - nearLevel)* sample_bilinear(sp.p_uv, upper);
      }

  }

  //return Color(1, 0, 1);
}

float Texture::get_level(const SampleParams &sp) {
  // TODO: Task 6: Fill this in.
  Vector2D diff = sp.p_dx_uv - sp.p_uv;
  Vector2D diff1 = sp.p_dy_uv - sp.p_uv;
  diff.x = diff.x * width;
  diff.y = diff.y * height;
  diff1.x = diff1.x * width;
  diff1.y = diff1.y * height;
  if (diff.norm() > diff1.norm()) {
      return log2(diff.norm());
  } else {
      return log2(diff1.norm());
  }

}

Color MipLevel::get_texel(int tx, int ty) {
  return Color(&texels[tx * 3 + ty * width * 3]);
}

Color Texture::sample_nearest(Vector2D uv, int level) {
  // TODO: Task 5: Fill this in.
  // return magenta for invalid level
  if (level < 0 || level > kMaxMipLevels) {
      return Color(1, 0, 1);
  }
  return mipmap[level].get_texel(floor(uv.x * mipmap[level].width), floor(uv.y * mipmap[level].height));
  //return Color(1, 0, 1);
}

Color Texture::sample_bilinear(Vector2D uv, int level) {
  // TODO: Task 5: Fill this in.
  // return magenta for invalid level
  if (level < 0 || level > kMaxMipLevels) {
      return Color(1, 0, 1);
  }
  double xCenter = floor(uv.x * mipmap[level].width);
  double yCenter = floor(uv.y * mipmap[level].height);
  if (xCenter  == 0) {
        xCenter = xCenter + 1;
  }
  if (yCenter == 0) {
        yCenter = yCenter + 1;
  }
  Color u01 = mipmap[level].get_texel(xCenter - 0.5, yCenter + 0.5);
  Color u11 = mipmap[level].get_texel(xCenter + 0.5, yCenter + 0.5);
  Color u00 = mipmap[level].get_texel(xCenter - 0.5, yCenter - 0.5);
  Color u10 = mipmap[level].get_texel(xCenter + 0.5, yCenter - 0.5);
  //v0(1 - x) + xv1
  Color u0 = u00*(1 - (uv.x * mipmap[level].width - (xCenter - 0.5))) + (uv.x * mipmap[level].width - (xCenter - 0.5))*u10;
  Color u1 = u01*(1 - (uv.x * mipmap[level].width - (xCenter - 0.5))) + (uv.x * mipmap[level].width - (xCenter - 0.5))*u11;
  return u0 * (1 - ((uv.y * mipmap[level].height) - (yCenter - 0.5))) + ((uv.y * mipmap[level].height) - (yCenter - 0.5)) * u1;


}

/****************************************************************************/

// Helpers

inline void uint8_to_float(float dst[3], unsigned char *src) {
  uint8_t *src_uint8 = (uint8_t *)src;
  dst[0] = src_uint8[0] / 255.f;
  dst[1] = src_uint8[1] / 255.f;
  dst[2] = src_uint8[2] / 255.f;
}

inline void float_to_uint8(unsigned char *dst, float src[3]) {
  uint8_t *dst_uint8 = (uint8_t *)dst;
  dst_uint8[0] = (uint8_t)(255.f * max(0.0f, min(1.0f, src[0])));
  dst_uint8[1] = (uint8_t)(255.f * max(0.0f, min(1.0f, src[1])));
  dst_uint8[2] = (uint8_t)(255.f * max(0.0f, min(1.0f, src[2])));
}

void Texture::generate_mips(int startLevel) {

  // make sure there's a valid texture
  if (startLevel >= mipmap.size()) {
    std::cerr << "Invalid start level";
  }

  // allocate sublevels
  int baseWidth = mipmap[startLevel].width;
  int baseHeight = mipmap[startLevel].height;
  int numSubLevels = (int)(log2f((float)max(baseWidth, baseHeight)));

  numSubLevels = min(numSubLevels, kMaxMipLevels - startLevel - 1);
  mipmap.resize(startLevel + numSubLevels + 1);

  int width = baseWidth;
  int height = baseHeight;
  for (int i = 1; i <= numSubLevels; i++) {

    MipLevel &level = mipmap[startLevel + i];

    // handle odd size texture by rounding down
    width = max(1, width / 2);
    // assert (width > 0);
    height = max(1, height / 2);
    // assert (height > 0);

    level.width = width;
    level.height = height;
    level.texels = vector<unsigned char>(3 * width * height);
  }

  // create mips
  int subLevels = numSubLevels - (startLevel + 1);
  for (int mipLevel = startLevel + 1; mipLevel < startLevel + subLevels + 1;
       mipLevel++) {

    MipLevel &prevLevel = mipmap[mipLevel - 1];
    MipLevel &currLevel = mipmap[mipLevel];

    int prevLevelPitch = prevLevel.width * 3; // 32 bit RGB
    int currLevelPitch = currLevel.width * 3; // 32 bit RGB

    unsigned char *prevLevelMem;
    unsigned char *currLevelMem;

    currLevelMem = (unsigned char *)&currLevel.texels[0];
    prevLevelMem = (unsigned char *)&prevLevel.texels[0];

    float wDecimal, wNorm, wWeight[3];
    int wSupport;
    float hDecimal, hNorm, hWeight[3];
    int hSupport;

    float result[3];
    float input[3];

    // conditional differentiates no rounding case from round down case
    if (prevLevel.width & 1) {
      wSupport = 3;
      wDecimal = 1.0f / (float)currLevel.width;
    } else {
      wSupport = 2;
      wDecimal = 0.0f;
    }

    // conditional differentiates no rounding case from round down case
    if (prevLevel.height & 1) {
      hSupport = 3;
      hDecimal = 1.0f / (float)currLevel.height;
    } else {
      hSupport = 2;
      hDecimal = 0.0f;
    }

    wNorm = 1.0f / (2.0f + wDecimal);
    hNorm = 1.0f / (2.0f + hDecimal);

    // case 1: reduction only in horizontal size (vertical size is 1)
    if (currLevel.height == prevLevel.height) {
      // assert (currLevel.height == 1);

      for (int i = 0; i < currLevel.width; i++) {
        wWeight[0] = wNorm * (1.0f - wDecimal * i);
        wWeight[1] = wNorm * 1.0f;
        wWeight[2] = wNorm * wDecimal * (i + 1);

        result[0] = result[1] = result[2] = 0.0f;

        for (int ii = 0; ii < wSupport; ii++) {
          uint8_to_float(input, prevLevelMem + 3 * (2 * i + ii));
          result[0] += wWeight[ii] * input[0];
          result[1] += wWeight[ii] * input[1];
          result[2] += wWeight[ii] * input[2];
        }

        // convert back to format of the texture
        float_to_uint8(currLevelMem + (3 * i), result);
      }

      // case 2: reduction only in vertical size (horizontal size is 1)
    } else if (currLevel.width == prevLevel.width) {
      // assert (currLevel.width == 1);

      for (int j = 0; j < currLevel.height; j++) {
        hWeight[0] = hNorm * (1.0f - hDecimal * j);
        hWeight[1] = hNorm;
        hWeight[2] = hNorm * hDecimal * (j + 1);

        result[0] = result[1] = result[2] = 0.0f;
        for (int jj = 0; jj < hSupport; jj++) {
          uint8_to_float(input, prevLevelMem + prevLevelPitch * (2 * j + jj));
          result[0] += hWeight[jj] * input[0];
          result[1] += hWeight[jj] * input[1];
          result[2] += hWeight[jj] * input[2];
        }

        // convert back to format of the texture
        float_to_uint8(currLevelMem + (currLevelPitch * j), result);
      }

      // case 3: reduction in both horizontal and vertical size
    } else {

      for (int j = 0; j < currLevel.height; j++) {
        hWeight[0] = hNorm * (1.0f - hDecimal * j);
        hWeight[1] = hNorm;
        hWeight[2] = hNorm * hDecimal * (j + 1);

        for (int i = 0; i < currLevel.width; i++) {
          wWeight[0] = wNorm * (1.0f - wDecimal * i);
          wWeight[1] = wNorm * 1.0f;
          wWeight[2] = wNorm * wDecimal * (i + 1);

          result[0] = result[1] = result[2] = 0.0f;

          // convolve source image with a trapezoidal filter.
          // in the case of no rounding this is just a box filter of width 2.
          // in the general case, the support region is 3x3.
          for (int jj = 0; jj < hSupport; jj++)
            for (int ii = 0; ii < wSupport; ii++) {
              float weight = hWeight[jj] * wWeight[ii];
              uint8_to_float(input, prevLevelMem +
                                        prevLevelPitch * (2 * j + jj) +
                                        3 * (2 * i + ii));
              result[0] += weight * input[0];
              result[1] += weight * input[1];
              result[2] += weight * input[2];
            }

          // convert back to format of the texture
          float_to_uint8(currLevelMem + currLevelPitch * j + 3 * i, result);
        }
      }
    }
  }
}

} // namespace CGL
