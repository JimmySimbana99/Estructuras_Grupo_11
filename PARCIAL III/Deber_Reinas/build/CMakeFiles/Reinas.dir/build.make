# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/USUARIO/Downloads/REINAS/REINAS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/USUARIO/Downloads/REINAS/REINAS/build

# Include any dependencies generated for this target.
include CMakeFiles/Reinas.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Reinas.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Reinas.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Reinas.dir/flags.make

CMakeFiles/Reinas.dir/main.cpp.obj: CMakeFiles/Reinas.dir/flags.make
CMakeFiles/Reinas.dir/main.cpp.obj: ../main.cpp
CMakeFiles/Reinas.dir/main.cpp.obj: CMakeFiles/Reinas.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/USUARIO/Downloads/REINAS/REINAS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Reinas.dir/main.cpp.obj"
	C:/TDM-GCC-64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Reinas.dir/main.cpp.obj -MF CMakeFiles/Reinas.dir/main.cpp.obj.d -o CMakeFiles/Reinas.dir/main.cpp.obj -c C:/Users/USUARIO/Downloads/REINAS/REINAS/main.cpp

CMakeFiles/Reinas.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reinas.dir/main.cpp.i"
	C:/TDM-GCC-64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/USUARIO/Downloads/REINAS/REINAS/main.cpp > CMakeFiles/Reinas.dir/main.cpp.i

CMakeFiles/Reinas.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reinas.dir/main.cpp.s"
	C:/TDM-GCC-64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/USUARIO/Downloads/REINAS/REINAS/main.cpp -o CMakeFiles/Reinas.dir/main.cpp.s

# Object files for target Reinas
Reinas_OBJECTS = \
"CMakeFiles/Reinas.dir/main.cpp.obj"

# External object files for target Reinas
Reinas_EXTERNAL_OBJECTS =

Reinas.exe: CMakeFiles/Reinas.dir/main.cpp.obj
Reinas.exe: CMakeFiles/Reinas.dir/build.make
Reinas.exe: CMakeFiles/Reinas.dir/linklibs.rsp
Reinas.exe: CMakeFiles/Reinas.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/Users/USUARIO/Downloads/REINAS/REINAS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Reinas.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/Reinas.dir/objects.a
	C:/TDM-GCC-64/bin/ar.exe qc CMakeFiles/Reinas.dir/objects.a @CMakeFiles/Reinas.dir/objects1.rsp
	C:/TDM-GCC-64/bin/g++.exe -g -Wl,--whole-archive CMakeFiles/Reinas.dir/objects.a -Wl,--no-whole-archive -o Reinas.exe -Wl,--out-implib,libReinas.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/Reinas.dir/linklibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/Reinas.dir/build: Reinas.exe
.PHONY : CMakeFiles/Reinas.dir/build

CMakeFiles/Reinas.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Reinas.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Reinas.dir/clean

CMakeFiles/Reinas.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/USUARIO/Downloads/REINAS/REINAS C:/Users/USUARIO/Downloads/REINAS/REINAS C:/Users/USUARIO/Downloads/REINAS/REINAS/build C:/Users/USUARIO/Downloads/REINAS/REINAS/build C:/Users/USUARIO/Downloads/REINAS/REINAS/build/CMakeFiles/Reinas.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Reinas.dir/depend
