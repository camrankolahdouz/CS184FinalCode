# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/draw.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/draw.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/draw.dir/flags.make

CMakeFiles/draw.dir/src/texture.cpp.o: CMakeFiles/draw.dir/flags.make
CMakeFiles/draw.dir/src/texture.cpp.o: ../src/texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/draw.dir/src/texture.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/draw.dir/src/texture.cpp.o -c /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/src/texture.cpp

CMakeFiles/draw.dir/src/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/draw.dir/src/texture.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/src/texture.cpp > CMakeFiles/draw.dir/src/texture.cpp.i

CMakeFiles/draw.dir/src/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/draw.dir/src/texture.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/src/texture.cpp -o CMakeFiles/draw.dir/src/texture.cpp.s

CMakeFiles/draw.dir/src/triangulation.cpp.o: CMakeFiles/draw.dir/flags.make
CMakeFiles/draw.dir/src/triangulation.cpp.o: ../src/triangulation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/draw.dir/src/triangulation.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/draw.dir/src/triangulation.cpp.o -c /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/src/triangulation.cpp

CMakeFiles/draw.dir/src/triangulation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/draw.dir/src/triangulation.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/src/triangulation.cpp > CMakeFiles/draw.dir/src/triangulation.cpp.i

CMakeFiles/draw.dir/src/triangulation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/draw.dir/src/triangulation.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/src/triangulation.cpp -o CMakeFiles/draw.dir/src/triangulation.cpp.s

CMakeFiles/draw.dir/src/svgparser.cpp.o: CMakeFiles/draw.dir/flags.make
CMakeFiles/draw.dir/src/svgparser.cpp.o: ../src/svgparser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/draw.dir/src/svgparser.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/draw.dir/src/svgparser.cpp.o -c /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/src/svgparser.cpp

CMakeFiles/draw.dir/src/svgparser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/draw.dir/src/svgparser.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/src/svgparser.cpp > CMakeFiles/draw.dir/src/svgparser.cpp.i

CMakeFiles/draw.dir/src/svgparser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/draw.dir/src/svgparser.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/src/svgparser.cpp -o CMakeFiles/draw.dir/src/svgparser.cpp.s

CMakeFiles/draw.dir/src/transforms.cpp.o: CMakeFiles/draw.dir/flags.make
CMakeFiles/draw.dir/src/transforms.cpp.o: ../src/transforms.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/draw.dir/src/transforms.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/draw.dir/src/transforms.cpp.o -c /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/src/transforms.cpp

CMakeFiles/draw.dir/src/transforms.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/draw.dir/src/transforms.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/src/transforms.cpp > CMakeFiles/draw.dir/src/transforms.cpp.i

CMakeFiles/draw.dir/src/transforms.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/draw.dir/src/transforms.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/src/transforms.cpp -o CMakeFiles/draw.dir/src/transforms.cpp.s

CMakeFiles/draw.dir/src/rasterizer.cpp.o: CMakeFiles/draw.dir/flags.make
CMakeFiles/draw.dir/src/rasterizer.cpp.o: ../src/rasterizer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/draw.dir/src/rasterizer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/draw.dir/src/rasterizer.cpp.o -c /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/src/rasterizer.cpp

CMakeFiles/draw.dir/src/rasterizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/draw.dir/src/rasterizer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/src/rasterizer.cpp > CMakeFiles/draw.dir/src/rasterizer.cpp.i

CMakeFiles/draw.dir/src/rasterizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/draw.dir/src/rasterizer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/src/rasterizer.cpp -o CMakeFiles/draw.dir/src/rasterizer.cpp.s

CMakeFiles/draw.dir/src/drawrend.cpp.o: CMakeFiles/draw.dir/flags.make
CMakeFiles/draw.dir/src/drawrend.cpp.o: ../src/drawrend.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/draw.dir/src/drawrend.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/draw.dir/src/drawrend.cpp.o -c /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/src/drawrend.cpp

CMakeFiles/draw.dir/src/drawrend.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/draw.dir/src/drawrend.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/src/drawrend.cpp > CMakeFiles/draw.dir/src/drawrend.cpp.i

CMakeFiles/draw.dir/src/drawrend.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/draw.dir/src/drawrend.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/src/drawrend.cpp -o CMakeFiles/draw.dir/src/drawrend.cpp.s

CMakeFiles/draw.dir/src/svg.cpp.o: CMakeFiles/draw.dir/flags.make
CMakeFiles/draw.dir/src/svg.cpp.o: ../src/svg.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/draw.dir/src/svg.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/draw.dir/src/svg.cpp.o -c /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/src/svg.cpp

CMakeFiles/draw.dir/src/svg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/draw.dir/src/svg.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/src/svg.cpp > CMakeFiles/draw.dir/src/svg.cpp.i

CMakeFiles/draw.dir/src/svg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/draw.dir/src/svg.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/src/svg.cpp -o CMakeFiles/draw.dir/src/svg.cpp.s

CMakeFiles/draw.dir/src/main.cpp.o: CMakeFiles/draw.dir/flags.make
CMakeFiles/draw.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/draw.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/draw.dir/src/main.cpp.o -c /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/src/main.cpp

CMakeFiles/draw.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/draw.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/src/main.cpp > CMakeFiles/draw.dir/src/main.cpp.i

CMakeFiles/draw.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/draw.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/src/main.cpp -o CMakeFiles/draw.dir/src/main.cpp.s

# Object files for target draw
draw_OBJECTS = \
"CMakeFiles/draw.dir/src/texture.cpp.o" \
"CMakeFiles/draw.dir/src/triangulation.cpp.o" \
"CMakeFiles/draw.dir/src/svgparser.cpp.o" \
"CMakeFiles/draw.dir/src/transforms.cpp.o" \
"CMakeFiles/draw.dir/src/rasterizer.cpp.o" \
"CMakeFiles/draw.dir/src/drawrend.cpp.o" \
"CMakeFiles/draw.dir/src/svg.cpp.o" \
"CMakeFiles/draw.dir/src/main.cpp.o"

# External object files for target draw
draw_EXTERNAL_OBJECTS =

draw: CMakeFiles/draw.dir/src/texture.cpp.o
draw: CMakeFiles/draw.dir/src/triangulation.cpp.o
draw: CMakeFiles/draw.dir/src/svgparser.cpp.o
draw: CMakeFiles/draw.dir/src/transforms.cpp.o
draw: CMakeFiles/draw.dir/src/rasterizer.cpp.o
draw: CMakeFiles/draw.dir/src/drawrend.cpp.o
draw: CMakeFiles/draw.dir/src/svg.cpp.o
draw: CMakeFiles/draw.dir/src/main.cpp.o
draw: CMakeFiles/draw.dir/build.make
draw: CGL/libCGL.a
draw: /usr/local/lib/libfreetype.dylib
draw: CGL/deps/glew/libglew.a
draw: CGL/deps/glfw/src/libglfw3.a
draw: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.15.sdk/System/Library/Frameworks/OpenGL.framework/OpenGL.tbd
draw: CMakeFiles/draw.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable draw"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/draw.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/draw.dir/build: draw

.PHONY : CMakeFiles/draw.dir/build

CMakeFiles/draw.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/draw.dir/cmake_clean.cmake
.PHONY : CMakeFiles/draw.dir/clean

CMakeFiles/draw.dir/depend:
	cd /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/cmake-build-debug /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/cmake-build-debug /Users/camrankolahdouz/Desktop/cs184/FinalProjectCode/CS184FinalCode/cmake-build-debug/CMakeFiles/draw.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/draw.dir/depend

