# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /Users/jialeiwang/Desktop/Net

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jialeiwang/Desktop/Net/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/daytimetcpcli.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/daytimetcpcli.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/daytimetcpcli.dir/flags.make

CMakeFiles/daytimetcpcli.dir/unp/daytimetcpcli.cpp.o: CMakeFiles/daytimetcpcli.dir/flags.make
CMakeFiles/daytimetcpcli.dir/unp/daytimetcpcli.cpp.o: ../unp/daytimetcpcli.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jialeiwang/Desktop/Net/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/daytimetcpcli.dir/unp/daytimetcpcli.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/daytimetcpcli.dir/unp/daytimetcpcli.cpp.o -c /Users/jialeiwang/Desktop/Net/unp/daytimetcpcli.cpp

CMakeFiles/daytimetcpcli.dir/unp/daytimetcpcli.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/daytimetcpcli.dir/unp/daytimetcpcli.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jialeiwang/Desktop/Net/unp/daytimetcpcli.cpp > CMakeFiles/daytimetcpcli.dir/unp/daytimetcpcli.cpp.i

CMakeFiles/daytimetcpcli.dir/unp/daytimetcpcli.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/daytimetcpcli.dir/unp/daytimetcpcli.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jialeiwang/Desktop/Net/unp/daytimetcpcli.cpp -o CMakeFiles/daytimetcpcli.dir/unp/daytimetcpcli.cpp.s

CMakeFiles/daytimetcpcli.dir/unp/error.cpp.o: CMakeFiles/daytimetcpcli.dir/flags.make
CMakeFiles/daytimetcpcli.dir/unp/error.cpp.o: ../unp/error.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jialeiwang/Desktop/Net/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/daytimetcpcli.dir/unp/error.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/daytimetcpcli.dir/unp/error.cpp.o -c /Users/jialeiwang/Desktop/Net/unp/error.cpp

CMakeFiles/daytimetcpcli.dir/unp/error.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/daytimetcpcli.dir/unp/error.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jialeiwang/Desktop/Net/unp/error.cpp > CMakeFiles/daytimetcpcli.dir/unp/error.cpp.i

CMakeFiles/daytimetcpcli.dir/unp/error.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/daytimetcpcli.dir/unp/error.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jialeiwang/Desktop/Net/unp/error.cpp -o CMakeFiles/daytimetcpcli.dir/unp/error.cpp.s

# Object files for target daytimetcpcli
daytimetcpcli_OBJECTS = \
"CMakeFiles/daytimetcpcli.dir/unp/daytimetcpcli.cpp.o" \
"CMakeFiles/daytimetcpcli.dir/unp/error.cpp.o"

# External object files for target daytimetcpcli
daytimetcpcli_EXTERNAL_OBJECTS =

daytimetcpcli: CMakeFiles/daytimetcpcli.dir/unp/daytimetcpcli.cpp.o
daytimetcpcli: CMakeFiles/daytimetcpcli.dir/unp/error.cpp.o
daytimetcpcli: CMakeFiles/daytimetcpcli.dir/build.make
daytimetcpcli: CMakeFiles/daytimetcpcli.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jialeiwang/Desktop/Net/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable daytimetcpcli"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/daytimetcpcli.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/daytimetcpcli.dir/build: daytimetcpcli

.PHONY : CMakeFiles/daytimetcpcli.dir/build

CMakeFiles/daytimetcpcli.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/daytimetcpcli.dir/cmake_clean.cmake
.PHONY : CMakeFiles/daytimetcpcli.dir/clean

CMakeFiles/daytimetcpcli.dir/depend:
	cd /Users/jialeiwang/Desktop/Net/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jialeiwang/Desktop/Net /Users/jialeiwang/Desktop/Net /Users/jialeiwang/Desktop/Net/cmake-build-debug /Users/jialeiwang/Desktop/Net/cmake-build-debug /Users/jialeiwang/Desktop/Net/cmake-build-debug/CMakeFiles/daytimetcpcli.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/daytimetcpcli.dir/depend

