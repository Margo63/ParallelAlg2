# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.25.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.25.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/margarita/CLionProjects/lab2_par_alg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/margarita/CLionProjects/lab2_par_alg

# Include any dependencies generated for this target.
include CMakeFiles/lab2_par_alg.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab2_par_alg.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab2_par_alg.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab2_par_alg.dir/flags.make

CMakeFiles/lab2_par_alg.dir/coarse_grain.cpp.o: CMakeFiles/lab2_par_alg.dir/flags.make
CMakeFiles/lab2_par_alg.dir/coarse_grain.cpp.o: coarse_grain.cpp
CMakeFiles/lab2_par_alg.dir/coarse_grain.cpp.o: CMakeFiles/lab2_par_alg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/margarita/CLionProjects/lab2_par_alg/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab2_par_alg.dir/coarse_grain.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab2_par_alg.dir/coarse_grain.cpp.o -MF CMakeFiles/lab2_par_alg.dir/coarse_grain.cpp.o.d -o CMakeFiles/lab2_par_alg.dir/coarse_grain.cpp.o -c /Users/margarita/CLionProjects/lab2_par_alg/coarse_grain.cpp

CMakeFiles/lab2_par_alg.dir/coarse_grain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab2_par_alg.dir/coarse_grain.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/margarita/CLionProjects/lab2_par_alg/coarse_grain.cpp > CMakeFiles/lab2_par_alg.dir/coarse_grain.cpp.i

CMakeFiles/lab2_par_alg.dir/coarse_grain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab2_par_alg.dir/coarse_grain.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/margarita/CLionProjects/lab2_par_alg/coarse_grain.cpp -o CMakeFiles/lab2_par_alg.dir/coarse_grain.cpp.s

CMakeFiles/lab2_par_alg.dir/matrix.cpp.o: CMakeFiles/lab2_par_alg.dir/flags.make
CMakeFiles/lab2_par_alg.dir/matrix.cpp.o: matrix.cpp
CMakeFiles/lab2_par_alg.dir/matrix.cpp.o: CMakeFiles/lab2_par_alg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/margarita/CLionProjects/lab2_par_alg/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab2_par_alg.dir/matrix.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab2_par_alg.dir/matrix.cpp.o -MF CMakeFiles/lab2_par_alg.dir/matrix.cpp.o.d -o CMakeFiles/lab2_par_alg.dir/matrix.cpp.o -c /Users/margarita/CLionProjects/lab2_par_alg/matrix.cpp

CMakeFiles/lab2_par_alg.dir/matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab2_par_alg.dir/matrix.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/margarita/CLionProjects/lab2_par_alg/matrix.cpp > CMakeFiles/lab2_par_alg.dir/matrix.cpp.i

CMakeFiles/lab2_par_alg.dir/matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab2_par_alg.dir/matrix.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/margarita/CLionProjects/lab2_par_alg/matrix.cpp -o CMakeFiles/lab2_par_alg.dir/matrix.cpp.s

# Object files for target lab2_par_alg
lab2_par_alg_OBJECTS = \
"CMakeFiles/lab2_par_alg.dir/coarse_grain.cpp.o" \
"CMakeFiles/lab2_par_alg.dir/matrix.cpp.o"

# External object files for target lab2_par_alg
lab2_par_alg_EXTERNAL_OBJECTS =

lab2_par_alg: CMakeFiles/lab2_par_alg.dir/coarse_grain.cpp.o
lab2_par_alg: CMakeFiles/lab2_par_alg.dir/matrix.cpp.o
lab2_par_alg: CMakeFiles/lab2_par_alg.dir/build.make
lab2_par_alg: CMakeFiles/lab2_par_alg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/margarita/CLionProjects/lab2_par_alg/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable lab2_par_alg"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab2_par_alg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab2_par_alg.dir/build: lab2_par_alg
.PHONY : CMakeFiles/lab2_par_alg.dir/build

CMakeFiles/lab2_par_alg.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab2_par_alg.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab2_par_alg.dir/clean

CMakeFiles/lab2_par_alg.dir/depend:
	cd /Users/margarita/CLionProjects/lab2_par_alg && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/margarita/CLionProjects/lab2_par_alg /Users/margarita/CLionProjects/lab2_par_alg /Users/margarita/CLionProjects/lab2_par_alg /Users/margarita/CLionProjects/lab2_par_alg /Users/margarita/CLionProjects/lab2_par_alg/CMakeFiles/lab2_par_alg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab2_par_alg.dir/depend

