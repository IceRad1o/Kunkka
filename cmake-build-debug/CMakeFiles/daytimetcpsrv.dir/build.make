# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /opt/clion-2020.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2020.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jialeiwang/Desktop/Net

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jialeiwang/Desktop/Net/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/daytimetcpsrv.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/daytimetcpsrv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/daytimetcpsrv.dir/flags.make

CMakeFiles/daytimetcpsrv.dir/unp/daytimetcpsrv.cpp.o: CMakeFiles/daytimetcpsrv.dir/flags.make
CMakeFiles/daytimetcpsrv.dir/unp/daytimetcpsrv.cpp.o: ../unp/daytimetcpsrv.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jialeiwang/Desktop/Net/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/daytimetcpsrv.dir/unp/daytimetcpsrv.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/daytimetcpsrv.dir/unp/daytimetcpsrv.cpp.o -c /home/jialeiwang/Desktop/Net/unp/daytimetcpsrv.cpp

CMakeFiles/daytimetcpsrv.dir/unp/daytimetcpsrv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/daytimetcpsrv.dir/unp/daytimetcpsrv.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jialeiwang/Desktop/Net/unp/daytimetcpsrv.cpp > CMakeFiles/daytimetcpsrv.dir/unp/daytimetcpsrv.cpp.i

CMakeFiles/daytimetcpsrv.dir/unp/daytimetcpsrv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/daytimetcpsrv.dir/unp/daytimetcpsrv.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jialeiwang/Desktop/Net/unp/daytimetcpsrv.cpp -o CMakeFiles/daytimetcpsrv.dir/unp/daytimetcpsrv.cpp.s

CMakeFiles/daytimetcpsrv.dir/unp/error.cpp.o: CMakeFiles/daytimetcpsrv.dir/flags.make
CMakeFiles/daytimetcpsrv.dir/unp/error.cpp.o: ../unp/error.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jialeiwang/Desktop/Net/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/daytimetcpsrv.dir/unp/error.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/daytimetcpsrv.dir/unp/error.cpp.o -c /home/jialeiwang/Desktop/Net/unp/error.cpp

CMakeFiles/daytimetcpsrv.dir/unp/error.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/daytimetcpsrv.dir/unp/error.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jialeiwang/Desktop/Net/unp/error.cpp > CMakeFiles/daytimetcpsrv.dir/unp/error.cpp.i

CMakeFiles/daytimetcpsrv.dir/unp/error.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/daytimetcpsrv.dir/unp/error.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jialeiwang/Desktop/Net/unp/error.cpp -o CMakeFiles/daytimetcpsrv.dir/unp/error.cpp.s

# Object files for target daytimetcpsrv
daytimetcpsrv_OBJECTS = \
"CMakeFiles/daytimetcpsrv.dir/unp/daytimetcpsrv.cpp.o" \
"CMakeFiles/daytimetcpsrv.dir/unp/error.cpp.o"

# External object files for target daytimetcpsrv
daytimetcpsrv_EXTERNAL_OBJECTS =

daytimetcpsrv: CMakeFiles/daytimetcpsrv.dir/unp/daytimetcpsrv.cpp.o
daytimetcpsrv: CMakeFiles/daytimetcpsrv.dir/unp/error.cpp.o
daytimetcpsrv: CMakeFiles/daytimetcpsrv.dir/build.make
daytimetcpsrv: CMakeFiles/daytimetcpsrv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jialeiwang/Desktop/Net/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable daytimetcpsrv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/daytimetcpsrv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/daytimetcpsrv.dir/build: daytimetcpsrv

.PHONY : CMakeFiles/daytimetcpsrv.dir/build

CMakeFiles/daytimetcpsrv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/daytimetcpsrv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/daytimetcpsrv.dir/clean

CMakeFiles/daytimetcpsrv.dir/depend:
	cd /home/jialeiwang/Desktop/Net/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jialeiwang/Desktop/Net /home/jialeiwang/Desktop/Net /home/jialeiwang/Desktop/Net/cmake-build-debug /home/jialeiwang/Desktop/Net/cmake-build-debug /home/jialeiwang/Desktop/Net/cmake-build-debug/CMakeFiles/daytimetcpsrv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/daytimetcpsrv.dir/depend

