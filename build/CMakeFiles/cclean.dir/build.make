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

# Utility rule file for cclean.

# Include the progress variables for this target.
include CMakeFiles/cclean.dir/progress.make

CMakeFiles/cclean:
	cd /home/min/libyang && make clean
	cd /home/min/libyang && find . -iname '*cmake*' -not -name CMakeLists.txt -not -path './CMakeModules*' -exec rm -rf {} +
	cd /home/min/libyang && rm -rf Makefile Doxyfile

cclean: CMakeFiles/cclean
cclean: CMakeFiles/cclean.dir/build.make

.PHONY : cclean

# Rule to build all files generated by this target.
CMakeFiles/cclean.dir/build: cclean

.PHONY : CMakeFiles/cclean.dir/build

CMakeFiles/cclean.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cclean.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cclean.dir/clean

CMakeFiles/cclean.dir/depend:
	cd /home/min/libyang/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/min/libyang /home/min/libyang /home/min/libyang/build /home/min/libyang/build /home/min/libyang/build/CMakeFiles/cclean.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cclean.dir/depend

