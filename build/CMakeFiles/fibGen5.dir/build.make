# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aaron/Programming/c/basics/5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aaron/Programming/c/basics/5/build

# Include any dependencies generated for this target.
include CMakeFiles/fibGen5.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/fibGen5.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/fibGen5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fibGen5.dir/flags.make

CMakeFiles/fibGen5.dir/src/main.c.o: CMakeFiles/fibGen5.dir/flags.make
CMakeFiles/fibGen5.dir/src/main.c.o: /home/aaron/Programming/c/basics/5/src/main.c
CMakeFiles/fibGen5.dir/src/main.c.o: CMakeFiles/fibGen5.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/aaron/Programming/c/basics/5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/fibGen5.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/fibGen5.dir/src/main.c.o -MF CMakeFiles/fibGen5.dir/src/main.c.o.d -o CMakeFiles/fibGen5.dir/src/main.c.o -c /home/aaron/Programming/c/basics/5/src/main.c

CMakeFiles/fibGen5.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/fibGen5.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aaron/Programming/c/basics/5/src/main.c > CMakeFiles/fibGen5.dir/src/main.c.i

CMakeFiles/fibGen5.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/fibGen5.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aaron/Programming/c/basics/5/src/main.c -o CMakeFiles/fibGen5.dir/src/main.c.s

# Object files for target fibGen5
fibGen5_OBJECTS = \
"CMakeFiles/fibGen5.dir/src/main.c.o"

# External object files for target fibGen5
fibGen5_EXTERNAL_OBJECTS =

fibGen5: CMakeFiles/fibGen5.dir/src/main.c.o
fibGen5: CMakeFiles/fibGen5.dir/build.make
fibGen5: /usr/lib/libz.so
fibGen5: /home/aaron/.conan2/p/b/gmp569edeaff041b/p/lib/libgmpxx.a
fibGen5: /home/aaron/.conan2/p/b/gmp569edeaff041b/p/lib/libgmp.a
fibGen5: CMakeFiles/fibGen5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/aaron/Programming/c/basics/5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable fibGen5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fibGen5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fibGen5.dir/build: fibGen5
.PHONY : CMakeFiles/fibGen5.dir/build

CMakeFiles/fibGen5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fibGen5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fibGen5.dir/clean

CMakeFiles/fibGen5.dir/depend:
	cd /home/aaron/Programming/c/basics/5/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aaron/Programming/c/basics/5 /home/aaron/Programming/c/basics/5 /home/aaron/Programming/c/basics/5/build /home/aaron/Programming/c/basics/5/build /home/aaron/Programming/c/basics/5/build/CMakeFiles/fibGen5.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/fibGen5.dir/depend

