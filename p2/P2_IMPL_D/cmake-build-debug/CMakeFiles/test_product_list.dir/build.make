# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = "C:\@MisProgramas\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\@MisProgramas\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\@MisProgramas\JetBrains\PRO2\P2_IMPL_D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\@MisProgramas\JetBrains\PRO2\P2_IMPL_D\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/test_product_list.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/test_product_list.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_product_list.dir/flags.make

CMakeFiles/test_product_list.dir/test_product_list.c.obj: CMakeFiles/test_product_list.dir/flags.make
CMakeFiles/test_product_list.dir/test_product_list.c.obj: ../test_product_list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\@MisProgramas\JetBrains\PRO2\P2_IMPL_D\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test_product_list.dir/test_product_list.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test_product_list.dir\test_product_list.c.obj -c C:\@MisProgramas\JetBrains\PRO2\P2_IMPL_D\test_product_list.c

CMakeFiles/test_product_list.dir/test_product_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_product_list.dir/test_product_list.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\@MisProgramas\JetBrains\PRO2\P2_IMPL_D\test_product_list.c > CMakeFiles\test_product_list.dir\test_product_list.c.i

CMakeFiles/test_product_list.dir/test_product_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_product_list.dir/test_product_list.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\@MisProgramas\JetBrains\PRO2\P2_IMPL_D\test_product_list.c -o CMakeFiles\test_product_list.dir\test_product_list.c.s

CMakeFiles/test_product_list.dir/product_list.c.obj: CMakeFiles/test_product_list.dir/flags.make
CMakeFiles/test_product_list.dir/product_list.c.obj: ../product_list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\@MisProgramas\JetBrains\PRO2\P2_IMPL_D\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/test_product_list.dir/product_list.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test_product_list.dir\product_list.c.obj -c C:\@MisProgramas\JetBrains\PRO2\P2_IMPL_D\product_list.c

CMakeFiles/test_product_list.dir/product_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_product_list.dir/product_list.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\@MisProgramas\JetBrains\PRO2\P2_IMPL_D\product_list.c > CMakeFiles\test_product_list.dir\product_list.c.i

CMakeFiles/test_product_list.dir/product_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_product_list.dir/product_list.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\@MisProgramas\JetBrains\PRO2\P2_IMPL_D\product_list.c -o CMakeFiles\test_product_list.dir\product_list.c.s

# Object files for target test_product_list
test_product_list_OBJECTS = \
"CMakeFiles/test_product_list.dir/test_product_list.c.obj" \
"CMakeFiles/test_product_list.dir/product_list.c.obj"

# External object files for target test_product_list
test_product_list_EXTERNAL_OBJECTS =

../bin/test_product_list.exe: CMakeFiles/test_product_list.dir/test_product_list.c.obj
../bin/test_product_list.exe: CMakeFiles/test_product_list.dir/product_list.c.obj
../bin/test_product_list.exe: CMakeFiles/test_product_list.dir/build.make
../bin/test_product_list.exe: CMakeFiles/test_product_list.dir/linklibs.rsp
../bin/test_product_list.exe: CMakeFiles/test_product_list.dir/objects1.rsp
../bin/test_product_list.exe: CMakeFiles/test_product_list.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\@MisProgramas\JetBrains\PRO2\P2_IMPL_D\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ..\bin\test_product_list.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test_product_list.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_product_list.dir/build: ../bin/test_product_list.exe
.PHONY : CMakeFiles/test_product_list.dir/build

CMakeFiles/test_product_list.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test_product_list.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test_product_list.dir/clean

CMakeFiles/test_product_list.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\@MisProgramas\JetBrains\PRO2\P2_IMPL_D C:\@MisProgramas\JetBrains\PRO2\P2_IMPL_D C:\@MisProgramas\JetBrains\PRO2\P2_IMPL_D\cmake-build-debug C:\@MisProgramas\JetBrains\PRO2\P2_IMPL_D\cmake-build-debug C:\@MisProgramas\JetBrains\PRO2\P2_IMPL_D\cmake-build-debug\CMakeFiles\test_product_list.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_product_list.dir/depend
