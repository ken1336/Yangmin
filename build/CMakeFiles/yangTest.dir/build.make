# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/min/libyang

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/min/libyang/build

# Include any dependencies generated for this target.
include CMakeFiles/yangTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/yangTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/yangTest.dir/flags.make

CMakeFiles/yangTest.dir/tools/lint/Ytest.cpp.o: CMakeFiles/yangTest.dir/flags.make
CMakeFiles/yangTest.dir/tools/lint/Ytest.cpp.o: ../tools/lint/Ytest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/min/libyang/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/yangTest.dir/tools/lint/Ytest.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/yangTest.dir/tools/lint/Ytest.cpp.o -c /home/min/libyang/tools/lint/Ytest.cpp

CMakeFiles/yangTest.dir/tools/lint/Ytest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yangTest.dir/tools/lint/Ytest.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/min/libyang/tools/lint/Ytest.cpp > CMakeFiles/yangTest.dir/tools/lint/Ytest.cpp.i

CMakeFiles/yangTest.dir/tools/lint/Ytest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yangTest.dir/tools/lint/Ytest.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/min/libyang/tools/lint/Ytest.cpp -o CMakeFiles/yangTest.dir/tools/lint/Ytest.cpp.s

CMakeFiles/yangTest.dir/tools/lint/Ytest.cpp.o.requires:

.PHONY : CMakeFiles/yangTest.dir/tools/lint/Ytest.cpp.o.requires

CMakeFiles/yangTest.dir/tools/lint/Ytest.cpp.o.provides: CMakeFiles/yangTest.dir/tools/lint/Ytest.cpp.o.requires
	$(MAKE) -f CMakeFiles/yangTest.dir/build.make CMakeFiles/yangTest.dir/tools/lint/Ytest.cpp.o.provides.build
.PHONY : CMakeFiles/yangTest.dir/tools/lint/Ytest.cpp.o.provides

CMakeFiles/yangTest.dir/tools/lint/Ytest.cpp.o.provides.build: CMakeFiles/yangTest.dir/tools/lint/Ytest.cpp.o


CMakeFiles/yangTest.dir/tools/lint/min_extension/module.cpp.o: CMakeFiles/yangTest.dir/flags.make
CMakeFiles/yangTest.dir/tools/lint/min_extension/module.cpp.o: ../tools/lint/min_extension/module.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/min/libyang/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/yangTest.dir/tools/lint/min_extension/module.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/yangTest.dir/tools/lint/min_extension/module.cpp.o -c /home/min/libyang/tools/lint/min_extension/module.cpp

CMakeFiles/yangTest.dir/tools/lint/min_extension/module.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yangTest.dir/tools/lint/min_extension/module.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/min/libyang/tools/lint/min_extension/module.cpp > CMakeFiles/yangTest.dir/tools/lint/min_extension/module.cpp.i

CMakeFiles/yangTest.dir/tools/lint/min_extension/module.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yangTest.dir/tools/lint/min_extension/module.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/min/libyang/tools/lint/min_extension/module.cpp -o CMakeFiles/yangTest.dir/tools/lint/min_extension/module.cpp.s

CMakeFiles/yangTest.dir/tools/lint/min_extension/module.cpp.o.requires:

.PHONY : CMakeFiles/yangTest.dir/tools/lint/min_extension/module.cpp.o.requires

CMakeFiles/yangTest.dir/tools/lint/min_extension/module.cpp.o.provides: CMakeFiles/yangTest.dir/tools/lint/min_extension/module.cpp.o.requires
	$(MAKE) -f CMakeFiles/yangTest.dir/build.make CMakeFiles/yangTest.dir/tools/lint/min_extension/module.cpp.o.provides.build
.PHONY : CMakeFiles/yangTest.dir/tools/lint/min_extension/module.cpp.o.provides

CMakeFiles/yangTest.dir/tools/lint/min_extension/module.cpp.o.provides.build: CMakeFiles/yangTest.dir/tools/lint/min_extension/module.cpp.o


# Object files for target yangTest
yangTest_OBJECTS = \
"CMakeFiles/yangTest.dir/tools/lint/Ytest.cpp.o" \
"CMakeFiles/yangTest.dir/tools/lint/min_extension/module.cpp.o"

# External object files for target yangTest
yangTest_EXTERNAL_OBJECTS =

yangTest: CMakeFiles/yangTest.dir/tools/lint/Ytest.cpp.o
yangTest: CMakeFiles/yangTest.dir/tools/lint/min_extension/module.cpp.o
yangTest: CMakeFiles/yangTest.dir/build.make
yangTest: libyang.so.1.3.0
yangTest: /usr/lib/x86_64-linux-gnu/libpcre.so
yangTest: CMakeFiles/yangTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/min/libyang/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable yangTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/yangTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/yangTest.dir/build: yangTest

.PHONY : CMakeFiles/yangTest.dir/build

CMakeFiles/yangTest.dir/requires: CMakeFiles/yangTest.dir/tools/lint/Ytest.cpp.o.requires
CMakeFiles/yangTest.dir/requires: CMakeFiles/yangTest.dir/tools/lint/min_extension/module.cpp.o.requires

.PHONY : CMakeFiles/yangTest.dir/requires

CMakeFiles/yangTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/yangTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/yangTest.dir/clean

CMakeFiles/yangTest.dir/depend:
	cd /home/min/libyang/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/min/libyang /home/min/libyang /home/min/libyang/build /home/min/libyang/build /home/min/libyang/build/CMakeFiles/yangTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/yangTest.dir/depend

