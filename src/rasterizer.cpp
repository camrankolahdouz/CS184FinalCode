#include "rasterizer.h"

using namespace std;

namespace CGL {

RasterizerImp::RasterizerImp(PixelSampleMethod psm, LevelSampleMethod lsm,
                                       size_t width, size_t height,
                                       unsigned int sample_rate) {
  this->psm = psm;
  this->lsm = lsm;
  this->width = width;
  this->height = height;
  this->sample_rate = sample_rate;

  supersample_buffer.resize(width * height * sample_rate, Color::White);
    // new
    int rootrate = sqrt(sample_rate);
    pressures.resize(width * height * sample_rate, 0.);
    xVelocities.resize((width * rootrate + 1) * height * rootrate, 0.);
    yVelocities.resize((height * rootrate + 1) * width * rootrate, 0.);
}

// Used by rasterize_point and rasterize_line
void RasterizerImp::fill_pixel(size_t x, size_t y, Color c) {
  // TODO: Task 2: You might need to this function to fix points and lines (such as the black rectangle border in test4.svg)
  // NOTE: You are not required to implement proper supersampling for points and lines
  // It is sufficient to use the same color for all supersamples of a pixel for points and lines (not triangles)

  rgb_framebuffer_target[3 * (y * width + x)    ] = (unsigned char)(c.r * 255);
  rgb_framebuffer_target[3 * (y * width + x) + 1] = (unsigned char)(c.g * 255);
  rgb_framebuffer_target[3 * (y * width + x) + 2] = (unsigned char)(c.b * 255);
}

// Optional helper function to add a sample to the supersample_buffer
void RasterizerImp::fill_supersample(size_t x, size_t y, size_t s, Color c) {
  // TODO: Task 2: You may want to implement this function. Hint: our solution uses one line
    supersample_buffer[(width * y + x) * sample_rate + s] = c;
};
    
    size_t RasterizerImp::get_supersample_index(size_t x, size_t y) {
        int rootrate = sqrt(sample_rate);
        return (width * (y / rootrate) + (x / rootrate)) * sample_rate + (x % rootrate) * rootrate + (y % rootrate);
    }
    
    void RasterizerImp::add_liquid(size_t x, size_t y) {
        int rootrate = sqrt(sample_rate);
        pressures[y * width * rootrate + x] = 1.;
        supersample_buffer[get_supersample_index(x, y)] = Color::Black;
    }

// Rasterize a point: simple example to help you start familiarizing
// yourself with the starter code.
//
void RasterizerImp::rasterize_point(float x, float y, Color color) {
  // fill in the nearest pixel
  int sx = (int)floor(x);
  int sy = (int)floor(y);

  // check bounds
  if (sx < 0 || sx >= width) return;
  if (sy < 0 || sy >= height) return;

    for (size_t s = 0; s < sample_rate; s++) {
        fill_supersample(sx, sy, s, color);
    }
  //fill_pixel(sx, sy, color);
}

// Rasterize a line.
void RasterizerImp::rasterize_line(float x0, float y0,
  float x1, float y1,
  Color color) {
  if (x0 > x1) {
    swap(x0, x1); swap(y0, y1);
  }

  float pt[] = { x0,y0 };
  float m = (y1 - y0) / (x1 - x0);
  float dpt[] = { 1,m };
  int steep = abs(m) > 1;
  if (steep) {
    dpt[0] = x1 == x0 ? 0 : 1 / abs(m);
    dpt[1] = x1 == x0 ? (y1 - y0) / abs(y1 - y0) : m / abs(m);
  }

  while (floor(pt[0]) <= floor(x1) && abs(pt[1] - y0) <= abs(y1 - y0)) {
    rasterize_point(pt[0], pt[1], color);
    pt[0] += dpt[0]; pt[1] += dpt[1];
  }
}

// Rasterize a triangle.
void RasterizerImp::rasterize_triangle(float x0, float y0,
                                       float x1, float y1,
                                       float x2, float y2,
                                       Color color) {
  // TODO: Task 1: Implement basic triangle rasterization here, no supersampling
    //rasterize_line(x0, y0, x1, y1, color);
    //rasterize_line(x1, y1, x2, y2, color);
    //rasterize_line(x2, y2, x0, y0, color);
    Vector2D p0 = Vector2D(x0, y0);
    Vector2D p1 = Vector2D(x1, y1);
    Vector2D p2 = Vector2D(x2, y2);
    Vector2D e0 = p1 - p0;
    Vector2D e1 = p2 - p1;
    Vector2D e2 = p0 - p2;
    Vector2D perp0 = Vector2D(-e0.y, e0.x);
    Vector2D perp1 = Vector2D(-e1.y, e1.x);
    Vector2D perp2 = Vector2D(-e2.y, e2.x);
    
    if (perp0.x * e2.x + perp0.y * e2.y > 0) {
        Vector2D temp = p1;
        p1 = p2;
        p2 = temp;
        e0 = p1 - p0;
        e1 = p2 - p1;
        e2 = p0 - p2;
        perp0 = Vector2D(-e0.y, e0.x);
        perp1 = Vector2D(-e1.y, e1.x);
        perp2 = Vector2D(-e2.y, e2.x);
    }
    
    // when you walk from p0 to p1 you will now turn left to reach p2
    float xstart;
    float ystart;
    float xend;
    float yend;
    if (p0.x > p1.x) {
        xstart = p1.x;
        xend = p0.x;
    } else {
        xstart = p0.x;
        xend = p1.x;
    }
    if (p2.x > xend) {
        xend = p2.x;
    }
    if (p2.x < xstart) {
        xstart = p2.x;
    }
    if (p0.y > p1.y) {
        ystart = p1.y;
        yend = p0.y;
    } else {
        ystart = p0.y;
        yend = p1.y;
    }
    if (p2.y > yend) {
        yend = p2.y;
    }
    if (p2.y < ystart) {
        ystart = p2.y;
    }
    
    // checking on screen
    int minx;
    int maxx;
    int miny;
    int maxy;
    if (xstart < 0) {
        minx = 0;
    } else if (xstart >= width) {
        return;
    } else {
        minx = (int)floor(xstart);
    }
    
    if (ystart < 0) {
        miny = 0;
    } else if (ystart >= height) {
        return;
    } else {
        miny = (int)floor(ystart);
    }
    
    if (xend < 0) {
        return;
    } else if (xend >= width) {
        maxx = width - 1;
    } else {
        maxx = (int)floor(xend);
    }
    
    if (yend < 0) {
        return;
    } else if (yend >= height) {
        maxy = height - 1;
    } else {
        maxy = (int)floor(yend);
    }
    int rootrate = sqrt(sample_rate);
    float step = 1 / (float)rootrate;
    for (int x = minx; x < maxx + 1; x += 1) {
        for (int y = miny; y <= maxy; y += 1) {
            float sampx = x;
            for (int i = 0; i < rootrate; i++) {
                float v0x = sampx - p0.x + .5 * step;
                float v1x = sampx - p1.x + .5 * step;
                float v2x = sampx - p2.x + .5 * step;
                float sampy = y;
                for (int j = 0; j < rootrate; j++) {
                    float v0y = sampy - p0.y + .5 * step;
                    float v1y = sampy - p1.y + .5 * step;
                    float v2y = sampy - p2.y + .5 * step;
                    float dp0 = v0x * perp0.x + v0y * perp0.y;
                    float dp1 = v1x * perp1.x + v1y * perp1.y;
                    float dp2 = v2x * perp2.x + v2y * perp2.y;
                    if (dp0 >= 0 && dp1 >= 0 && dp2 >= 0) {
                        fill_supersample(x, y, rootrate * i + j, color);
                    }
                    sampy += step;
                }
                sampx += step;
            }
        }
    }
}


void RasterizerImp::rasterize_interpolated_color_triangle(float x0, float y0, Color c0,
                                                          float x1, float y1, Color c1,
                                                          float x2, float y2, Color c2)
{
  // TODO: Task 4: Rasterize the triangle, calculating barycentric coordinates and using them to interpolate vertex colors across the triangle
  // Hint: You can reuse code from rasterize_triangle
    Vector2D p0 = Vector2D(x0, y0);
    Vector2D p1 = Vector2D(x1, y1);
    Vector2D p2 = Vector2D(x2, y2);
    Vector2D e0 = p1 - p0;
    Vector2D e1 = p2 - p1;
    Vector2D e2 = p0 - p2;
    Vector2D perp0 = Vector2D(-e0.y, e0.x);
    Vector2D perp1 = Vector2D(-e1.y, e1.x);
    Vector2D perp2 = Vector2D(-e2.y, e2.x);
    
    if (perp0.x * e2.x + perp0.y * e2.y > 0) {
        Vector2D temp = p1;
        p1 = p2;
        p2 = temp;
        e0 = p1 - p0;
        e1 = p2 - p1;
        e2 = p0 - p2;
        perp0 = Vector2D(-e0.y, e0.x);
        perp1 = Vector2D(-e1.y, e1.x);
        perp2 = Vector2D(-e2.y, e2.x);
        Color tempc = c1;
        c1 = c2;
        c2 = tempc;
    }
    
    // when you walk from p0 to p1 you will now turn left to reach p2
    float xstart;
    float ystart;
    float xend;
    float yend;
    if (p0.x > p1.x) {
        xstart = p1.x;
        xend = p0.x;
    } else {
        xstart = p0.x;
        xend = p1.x;
    }
    if (p2.x > xend) {
        xend = p2.x;
    }
    if (p2.x < xstart) {
        xstart = p2.x;
    }
    if (p0.y > p1.y) {
        ystart = p1.y;
        yend = p0.y;
    } else {
        ystart = p0.y;
        yend = p1.y;
    }
    if (p2.y > yend) {
        yend = p2.y;
    }
    if (p2.y < ystart) {
        ystart = p2.y;
    }
    
    // checking on screen
    int minx;
    int maxx;
    int miny;
    int maxy;
    if (xstart < 0) {
        minx = 0;
    } else if (xstart >= width) {
        return;
    } else {
        minx = (int)floor(xstart);
    }
    
    if (ystart < 0) {
        miny = 0;
    } else if (ystart >= height) {
        return;
    } else {
        miny = (int)floor(ystart);
    }
    
    if (xend < 0) {
        return;
    } else if (xend >= width) {
        maxx = width - 1;
    } else {
        maxx = (int)floor(xend);
    }
    
    if (yend < 0) {
        return;
    } else if (yend >= height) {
        maxy = height - 1;
    } else {
        maxy = (int)floor(yend);
    }
    int rootrate = sqrt(sample_rate);
    float step = 1 / (float)rootrate;
    for (int x = minx; x < maxx + 1; x += 1) {
        for (int y = miny; y <= maxy; y += 1) {
            float sampx = x;
            for (int i = 0; i < rootrate; i++) {
                float v0x = sampx - p0.x + .5 * step;
                float v1x = sampx - p1.x + .5 * step;
                float v2x = sampx - p2.x + .5 * step;
                float sampy = y;
                for (int j = 0; j < rootrate; j++) {
                    float v0y = sampy - p0.y + .5 * step;
                    float v1y = sampy - p1.y + .5 * step;
                    float v2y = sampy - p2.y + .5 * step;
                    float dp0 = v0x * perp0.x + v0y * perp0.y;
                    float dp1 = v1x * perp1.x + v1y * perp1.y;
                    float dp2 = v2x * perp2.x + v2y * perp2.y;
                    if (dp0 >= 0 && dp1 >= 0 && dp2 >= 0) {
                        float d = e2.x * e0.y - e0.x * e2.y;
                        float v = (v0y * e2.x - v0x * e2.y) / d;
                        float w = (e0.x * v0y - v0x * e0.y) / d;
                        fill_supersample(x, y, rootrate * i + j, (1 - v - w) * c0 + v * c1 + w * c2);
                    }
                    sampy += step;
                }
                sampx += step;
            }
        }
    }
}

void RasterizerImp::rasterize_textured_triangle(float x0, float y0, float u0, float v0,
    float x1, float y1, float u1, float v1,
    float x2, float y2, float u2, float v2,
    Texture& tex)
{
    // TODO: Task 5: Fill in the SampleParams struct and pass it to the tex.sample function.
    // TODO: Task 6: Set the correct barycentric differentials in the SampleParams struct.
    // Hint: You can reuse code from rasterize_triangle/rasterize_interpolated_color_triangle
    Vector2D p0 = Vector2D(x0, y0);
    Vector2D p1 = Vector2D(x1, y1);
    Vector2D p2 = Vector2D(x2, y2);
    Vector2D e0 = p1 - p0;
    Vector2D e1 = p2 - p1;
    Vector2D e2 = p0 - p2;
    Vector2D perp0 = Vector2D(-e0.y, e0.x);
    Vector2D perp1 = Vector2D(-e1.y, e1.x);
    Vector2D perp2 = Vector2D(-e2.y, e2.x);
    
    if (perp0.x * e2.x + perp0.y * e2.y > 0) {
        Vector2D temp = p1;
        p1 = p2;
        p2 = temp;
        e0 = p1 - p0;
        e1 = p2 - p1;
        e2 = p0 - p2;
        perp0 = Vector2D(-e0.y, e0.x);
        perp1 = Vector2D(-e1.y, e1.x);
        perp2 = Vector2D(-e2.y, e2.x);
        float t = u1;
        u1 = u2;
        u2 = t;
        t = v1;
        v1 = v2;
        v2 = t;
    }
    
    // when you walk from p0 to p1 you will now turn left to reach p2
    float xstart;
    float ystart;
    float xend;
    float yend;
    if (p0.x > p1.x) {
        xstart = p1.x;
        xend = p0.x;
    } else {
        xstart = p0.x;
        xend = p1.x;
    }
    if (p2.x > xend) {
        xend = p2.x;
    }
    if (p2.x < xstart) {
        xstart = p2.x;
    }
    if (p0.y > p1.y) {
        ystart = p1.y;
        yend = p0.y;
    } else {
        ystart = p0.y;
        yend = p1.y;
    }
    if (p2.y > yend) {
        yend = p2.y;
    }
    if (p2.y < ystart) {
        ystart = p2.y;
    }
    
    // checking on screen
    int minx;
    int maxx;
    int miny;
    int maxy;
    if (xstart < 0) {
        minx = 0;
    } else if (xstart >= width) {
        return;
    } else {
        minx = (int)floor(xstart);
    }
    
    if (ystart < 0) {
        miny = 0;
    } else if (ystart >= height) {
        return;
    } else {
        miny = (int)floor(ystart);
    }
    
    if (xend < 0) {
        return;
    } else if (xend >= width) {
        maxx = width - 1;
    } else {
        maxx = (int)floor(xend);
    }
    
    if (yend < 0) {
        return;
    } else if (yend >= height) {
        maxy = height - 1;
    } else {
        maxy = (int)floor(yend);
    }
    int rootrate = sqrt(sample_rate);
    float step = 1 / (float)rootrate;
    for (int x = minx; x < maxx + 1; x += 1) {
        for (int y = miny; y <= maxy; y += 1) {
            float sampx = x;
            for (int i = 0; i < rootrate; i++) {
                float v0x = sampx - p0.x + .5 * step;
                float v1x = sampx - p1.x + .5 * step;
                float v2x = sampx - p2.x + .5 * step;
                float sampy = y;
                for (int j = 0; j < rootrate; j++) {
                    float v0y = sampy - p0.y + .5 * step;
                    float v1y = sampy - p1.y + .5 * step;
                    float v2y = sampy - p2.y + .5 * step;
                    float dp0 = v0x * perp0.x + v0y * perp0.y;
                    float dp1 = v1x * perp1.x + v1y * perp1.y;
                    float dp2 = v2x * perp2.x + v2y * perp2.y;
                    if (dp0 >= 0 && dp1 >= 0 && dp2 >= 0) {
                        SampleParams s;
                        s.lsm = lsm;
                        s.psm = psm;
                        
                        float d = e2.x * e0.y - e0.x * e2.y;
                        
                        float v = (v0y * e2.x - v0x * e2.y) / d;
                        float w = (e0.x * v0y - v0x * e0.y) / d;
                        s.p_uv = Vector2D((1 - v - w) * u0 + v * u1 + w * u2, (1 - v - w) * v0 + v * v1 + w * v2);
                        
                        v = (v0y * e2.x - (v0x + 1) * e2.y) / d;
                        w = (e0.x * v0y - (v0x + 1) * e0.y) / d;
                        s.p_dx_uv = Vector2D((1 - v - w) * u0 + v * u1 + w * u2, (1 - v - w) * v0 + v * v1 + w * v2);
                        
                        v = ((v0y + 1) * e2.x - v0x * e2.y) / d;
                        w = (e0.x * (v0y + 1) - v0x * e0.y) / d;
                        s.p_dy_uv = Vector2D((1 - v - w) * u0 + v * u1 + w * u2, (1 - v - w) * v0 + v * v1 + w * v2);
                        
                        fill_supersample(x, y, rootrate * i + j, tex.sample(s));
                        //fill_supersample(x, y, rootrate * i + j, (1 - v - w) * c0 + v * c1 + w * c2);
                    }
                    sampy += step;
                }
                sampx += step;
            }
        }
    }

}

void RasterizerImp::set_sample_rate(unsigned int rate) {
  // TODO: Task 2: You may want to update this function for supersampling support

    if (pow((int)floor(sqrt(rate)), 2) != rate) {
        return;
    }
    this->sample_rate = rate;
    supersample_buffer.clear();
    supersample_buffer.resize(rate * width * height, Color::White);
    // new
    int rootrate = sqrt(sample_rate);
    pressures.clear();
    xVelocities.clear();
    yVelocities.clear();
    pressures.resize(width * height * sample_rate, 0.);
    xVelocities.resize((width * rootrate + 1) * height * rootrate, 0.);
    yVelocities.resize((height * rootrate + 1) * width * rootrate, 0.);

}


void RasterizerImp::set_framebuffer_target( unsigned char* rgb_framebuffer,
                                                size_t width, size_t height )
{
  // TODO: Task 2: You may want to update this function for supersampling support

    this->width = width;
    this->height = height;
    this->rgb_framebuffer_target = rgb_framebuffer;
    this->supersample_buffer.clear();
    this->supersample_buffer.resize(width * height * sample_rate, Color::White);
    
    // new
    int rootrate = sqrt(sample_rate);
    pressures.clear();
    xVelocities.clear();
    yVelocities.clear();
    pressures.resize(width * height * sample_rate, 0.);
    xVelocities.resize((width * rootrate + 1) * height * rootrate, 0.);
    yVelocities.resize((height * rootrate + 1) * width * rootrate, 0.);
  
}


void RasterizerImp::clear_buffers() {
  // TODO: Task 2: You may want to update this function for supersampling support
  // Hint: With supersampling, you have an additional buffer to take care of

    std::fill(rgb_framebuffer_target, rgb_framebuffer_target + 3 * width * height, 255);
    supersample_buffer.clear();
    supersample_buffer.resize(sample_rate * width * height, Color::White);
}


    void RasterizerImp::initialize_liquid() {
        int rootrate = sqrt(sample_rate);
        for (size_t x = width * rootrate / 3; x < 2 * width * rootrate / 3; x++) {
            for (size_t y = height * rootrate / 3; y < 2 * height * rootrate / 3; y++) {
                if (supersample_buffer[get_supersample_index(x, y)] == Color::White) {
                    add_liquid(x, y);
                }
            }
        }
    }

    void RasterizerImp::timestep() {
        int rootrate = sqrt(sample_rate);
        for (size_t y = rootrate * height - 2; y > 0; y--) {
            for (size_t x = 0; x < rootrate * width; x++) {
                yVelocities[y * width + x] += 1.; //gravity
                if (pressures[y * width * rootrate + x] > 0) {
                    int newY;
                    for (newY = y + 1; newY <= y + yVelocities[y * width + x] && newY < height; newY++) {
                        if (supersample_buffer.at(get_supersample_index(x, newY)) == Color::White) {
                            pressures[newY * width * rootrate + x] = pressures[(newY - 1) * width * rootrate + x];
                            pressures[(newY - 1) * width * rootrate + x] = 0.;
                            supersample_buffer[get_supersample_index(x, newY)] = Color::Black;
                            supersample_buffer[get_supersample_index(x, newY - 1)] = Color::White;
                            }
                        }
                    }
                }
            }
    }
// This function is called at the end of rasterizing all elements of the
// SVG file.  If you use a supersample buffer to rasterize SVG elements
// for antialising, you could use this call to fill the target framebuffer
// pixels from the supersample buffer data.
//
void RasterizerImp::resolve_to_framebuffer() {
  // TODO: Task 2: You will likely want to update this function for supersampling support
    //Position [x,y] = [width * y + x]
    //initialize_liquid();

    //int time = 100;
    //for (int t = 0; t < time; t++) {
       //timestep();
    //}
    int rootrate = sqrt(sample_rate);
    for (size_t x = 0; x < width; x++) {
        for (size_t y = 0; y < height; y++) {
            Color c = Color();
            for (size_t i = 0; i < rootrate; i++) {
                for (size_t j = 0; j < rootrate; j++) {
                    Color d = supersample_buffer.at((y * width + x) * sample_rate + rootrate * i + j);
                    if (d == Color::Black) {
                        if (pressures[(y * rootrate + j) * width * rootrate + (x * rootrate) + i] > 0) {
                            c += Color::fromHex("0000FF");
                        }
                    } else {
                        c += d;
                    }
                }
            }
            c *= (1 / (float)sample_rate);
            fill_pixel(x, y, c);
        }
    }
}

    void RasterizerImp::make_galton_board(int numPins) {
        supersample_buffer.clear();
        supersample_buffer.resize(width * height * sample_rate, Color::White);
        int rootrate = sqrt(sample_rate);
        float radius = float(height) / numPins;
        int xStart = width * rootrate / 2;
        int yStart = floor(height * rootrate / 2. - (numPins / 4.) * sqrt(3.) * radius);
        for (int i = 0; i <= numPins; i++) {
            int x = xStart;
            for (int j = 0; j <= i; j++) {
                rasterize_circle(x, yStart, radius / 6., Color::fromHex("00FF00"));
                x += radius;
                }
            xStart -= radius / 2.;
            yStart += radius * sqrt(3.) / 2.;
            }
    }

    void RasterizerImp::rasterize_circle(float x, float y, float r, Color color) {
        // fill in the nearest pixel
        int sx = (int)floor(x);
        int sy = (int)floor(y);
        int rootrate = sqrt(sample_rate);
        int xStart = floor((x - r) * rootrate);
        if (xStart < 0) {
            xStart = 0;
            }
        int yStart = floor((y - r) * rootrate);
        if (yStart < 0) {
            yStart = 0;
            }
        for (int i = xStart; i <= floor((x + r) * rootrate) && i < width * rootrate; i++) {
            for (int j = yStart; j <= floor((y + r) * rootrate) && j < height * rootrate; j++) {
                if (pow(x - (i / float(rootrate)) - .5, 2) + pow(y - (j / float(rootrate)) - .5, 2) <= pow(r, 2)) {
                    supersample_buffer[get_supersample_index(i, j)] = color;
                    }
                }
            }
        }

Rasterizer::~Rasterizer() { }


}// CGL
