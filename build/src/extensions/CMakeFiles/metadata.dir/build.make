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
include src/extensions/CMakeFiles/metadata.dir/depend.make

# Include the progress variables for this target.
include src/extensions/CMakeFiles/metadata.dir/progress.make

# Include the compile flags for this target's objects.
include src/extensions/CMakeFiles/metadata.dir/flags.make

src/extensions/CMakeFiles/metadata.dir/metadata.c.o: src/extensions/CMakeFiles/metadata.dir/flags.make
src/extensions/CMakeFiles/metadata.dir/metadata.c.o: ../src/extensions/metadata.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/min/libyang/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/extensions/CMakeFiles/metadata.dir/metadata.c.o"
	cd /home/min/libyang/build/src/extensions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/metadata.dir/metadata.c.o   -c /home/min/libyang/src/extensions/metadata.c

src/extensions/CMakeFiles/metadata.dir/metadata.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/metadata.dir/metadata.c.i"
	cd /home/min/libyang/build/src/extensions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/min/libyang/src/extensions/metadata.c > CMakeFiles/metadata.dir/metadata.c.i

src/extensions/CMakeFiles/metadata.dir/metadata.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/metadata.dir/metadata.c.s"
	cd /home/min/libyang/build/src/extensions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/min/libyang/src/extensions/metadata.c -o CMakeFiles/metadata.dir/metadata.c.s

src/extensions/CMakeFiles/metadata.dir/metadata.c.o.requires:

.PHONY : src/extensions/CMakeFiles/metadata.dir/metadata.c.o.requires

src/extensions/CMakeFiles/metadata.dir/metadata.c.o.provides: src/extensions/CMakeFiles/metadata.dir/metadata.c.o.requires
	$(MAKE) -f src/extensions/CMakeFiles/metadata.dir/build.make src/extensions/CMakeFiles/metadata.dir/metadata.c.o.provides.build
.PHONY : src/extensions/CMakeFiles/metadata.dir/metadata.c.o.provides

src/extensions/CMakeFiles/metadata.dir/metadata.c.o.provides.build: src/extensions/CMakeFiles/metadata.dir/metadata.c.o


# Object files for target metadata
metadata_OBJECTS = \
"CMakeFiles/metadata.dir/metadata.c.o"

# External object files for target metadata
metadata_EXTERNAL_OBJECTS =

src/extensions/metadata.so: src/extensions/CMakeFiles/metadata.dir/metadata.c.o
src/extensions/metadata.so: src/extensions/CMakeFiles/metadata.dir/build.make
src/extensions/metadata.so: libyang.so.1.3.0
src/extensions/metadata.so: /usr/lib/x86_64-linux-gnu/libpcre.so
src/extensions/metadata.so: src/extensions/CMakeFiles/metadata.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/min/libyang/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library metadata.so"
	cd /home/min/libyang/build/src/extensions && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/metadata.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/extensions/CMakeFiles/metadata.dir/build: src/extensions/metadata.so

.PHONY : src/extensions/CMakeFiles/metadata.dir/build

src/extensions/CMakeFiles/metadata.dir/requires: src/extensions/CMakeFiles/metadata.dir/metadata.c.o.requires

.PHONY : src/extensions/CMakeFiles/metadata.dir/requires

src/extensions/CMakeFiles/metadata.dir/clean:
	cd /home/min/libyang/build/src/extensions && $(CMAKE_COMMAND) -P CMakeFiles/metadata.dir/cmake_clean.cmake
.PHONY : src/extensions/CMakeFiles/metadata.dir/clean

src/extensions/CMakeFiles/metadata.dir/depend:
	cd /home/min/libyang/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/min/libyang /home/min/libyang/src/extensions /home/min/libyang/build /home/min/libyang/build/src/extensions /home/min/libyang/build/src/extensions/CMakeFiles/metadata.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/extensions/CMakeFiles/metadata.dir/depend

