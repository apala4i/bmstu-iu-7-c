# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\C_labs\RK_22_19

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\C_labs\RK_22_19\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RK_22_19.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RK_22_19.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RK_22_19.dir/flags.make

CMakeFiles/RK_22_19.dir/main.c.obj: CMakeFiles/RK_22_19.dir/flags.make
CMakeFiles/RK_22_19.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\C_labs\RK_22_19\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/RK_22_19.dir/main.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\RK_22_19.dir\main.c.obj -c C:\C_labs\RK_22_19\main.c

CMakeFiles/RK_22_19.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RK_22_19.dir/main.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\C_labs\RK_22_19\main.c > CMakeFiles\RK_22_19.dir\main.c.i

CMakeFiles/RK_22_19.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RK_22_19.dir/main.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\C_labs\RK_22_19\main.c -o CMakeFiles\RK_22_19.dir\main.c.s

CMakeFiles/RK_22_19.dir/funcs.c.obj: CMakeFiles/RK_22_19.dir/flags.make
CMakeFiles/RK_22_19.dir/funcs.c.obj: ../funcs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\C_labs\RK_22_19\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/RK_22_19.dir/funcs.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\RK_22_19.dir\funcs.c.obj -c C:\C_labs\RK_22_19\funcs.c

CMakeFiles/RK_22_19.dir/funcs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RK_22_19.dir/funcs.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\C_labs\RK_22_19\funcs.c > CMakeFiles\RK_22_19.dir\funcs.c.i

CMakeFiles/RK_22_19.dir/funcs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RK_22_19.dir/funcs.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\C_labs\RK_22_19\funcs.c -o CMakeFiles\RK_22_19.dir\funcs.c.s

# Object files for target RK_22_19
RK_22_19_OBJECTS = \
"CMakeFiles/RK_22_19.dir/main.c.obj" \
"CMakeFiles/RK_22_19.dir/funcs.c.obj"

# External object files for target RK_22_19
RK_22_19_EXTERNAL_OBJECTS =

RK_22_19.exe: CMakeFiles/RK_22_19.dir/main.c.obj
RK_22_19.exe: CMakeFiles/RK_22_19.dir/funcs.c.obj
RK_22_19.exe: CMakeFiles/RK_22_19.dir/build.make
RK_22_19.exe: CMakeFiles/RK_22_19.dir/linklibs.rsp
RK_22_19.exe: CMakeFiles/RK_22_19.dir/objects1.rsp
RK_22_19.exe: CMakeFiles/RK_22_19.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\C_labs\RK_22_19\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable RK_22_19.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\RK_22_19.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RK_22_19.dir/build: RK_22_19.exe

.PHONY : CMakeFiles/RK_22_19.dir/build

CMakeFiles/RK_22_19.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\RK_22_19.dir\cmake_clean.cmake
.PHONY : CMakeFiles/RK_22_19.dir/clean

CMakeFiles/RK_22_19.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\C_labs\RK_22_19 C:\C_labs\RK_22_19 C:\C_labs\RK_22_19\cmake-build-debug C:\C_labs\RK_22_19\cmake-build-debug C:\C_labs\RK_22_19\cmake-build-debug\CMakeFiles\RK_22_19.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RK_22_19.dir/depend
