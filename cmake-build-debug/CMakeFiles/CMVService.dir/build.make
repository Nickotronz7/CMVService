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
CMAKE_COMMAND = /home/nickotronz7/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.7148.70/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/nickotronz7/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.7148.70/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nickotronz7/Documents/DevProjects/CMVService

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nickotronz7/Documents/DevProjects/CMVService/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CMVService.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CMVService.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CMVService.dir/flags.make

CMakeFiles/CMVService.dir/server/main.c.o: CMakeFiles/CMVService.dir/flags.make
CMakeFiles/CMVService.dir/server/main.c.o: ../server/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nickotronz7/Documents/DevProjects/CMVService/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/CMVService.dir/server/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CMVService.dir/server/main.c.o   -c /home/nickotronz7/Documents/DevProjects/CMVService/server/main.c

CMakeFiles/CMVService.dir/server/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CMVService.dir/server/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nickotronz7/Documents/DevProjects/CMVService/server/main.c > CMakeFiles/CMVService.dir/server/main.c.i

CMakeFiles/CMVService.dir/server/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CMVService.dir/server/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nickotronz7/Documents/DevProjects/CMVService/server/main.c -o CMakeFiles/CMVService.dir/server/main.c.s

CMakeFiles/CMVService.dir/server/source/cJSON.c.o: CMakeFiles/CMVService.dir/flags.make
CMakeFiles/CMVService.dir/server/source/cJSON.c.o: ../server/source/cJSON.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nickotronz7/Documents/DevProjects/CMVService/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/CMVService.dir/server/source/cJSON.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CMVService.dir/server/source/cJSON.c.o   -c /home/nickotronz7/Documents/DevProjects/CMVService/server/source/cJSON.c

CMakeFiles/CMVService.dir/server/source/cJSON.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CMVService.dir/server/source/cJSON.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nickotronz7/Documents/DevProjects/CMVService/server/source/cJSON.c > CMakeFiles/CMVService.dir/server/source/cJSON.c.i

CMakeFiles/CMVService.dir/server/source/cJSON.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CMVService.dir/server/source/cJSON.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nickotronz7/Documents/DevProjects/CMVService/server/source/cJSON.c -o CMakeFiles/CMVService.dir/server/source/cJSON.c.s

CMakeFiles/CMVService.dir/server/source/httpd.c.o: CMakeFiles/CMVService.dir/flags.make
CMakeFiles/CMVService.dir/server/source/httpd.c.o: ../server/source/httpd.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nickotronz7/Documents/DevProjects/CMVService/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/CMVService.dir/server/source/httpd.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CMVService.dir/server/source/httpd.c.o   -c /home/nickotronz7/Documents/DevProjects/CMVService/server/source/httpd.c

CMakeFiles/CMVService.dir/server/source/httpd.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CMVService.dir/server/source/httpd.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nickotronz7/Documents/DevProjects/CMVService/server/source/httpd.c > CMakeFiles/CMVService.dir/server/source/httpd.c.i

CMakeFiles/CMVService.dir/server/source/httpd.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CMVService.dir/server/source/httpd.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nickotronz7/Documents/DevProjects/CMVService/server/source/httpd.c -o CMakeFiles/CMVService.dir/server/source/httpd.c.s

# Object files for target CMVService
CMVService_OBJECTS = \
"CMakeFiles/CMVService.dir/server/main.c.o" \
"CMakeFiles/CMVService.dir/server/source/cJSON.c.o" \
"CMakeFiles/CMVService.dir/server/source/httpd.c.o"

# External object files for target CMVService
CMVService_EXTERNAL_OBJECTS =

CMVService: CMakeFiles/CMVService.dir/server/main.c.o
CMVService: CMakeFiles/CMVService.dir/server/source/cJSON.c.o
CMVService: CMakeFiles/CMVService.dir/server/source/httpd.c.o
CMVService: CMakeFiles/CMVService.dir/build.make
CMVService: CMakeFiles/CMVService.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nickotronz7/Documents/DevProjects/CMVService/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable CMVService"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CMVService.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CMVService.dir/build: CMVService

.PHONY : CMakeFiles/CMVService.dir/build

CMakeFiles/CMVService.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CMVService.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CMVService.dir/clean

CMakeFiles/CMVService.dir/depend:
	cd /home/nickotronz7/Documents/DevProjects/CMVService/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nickotronz7/Documents/DevProjects/CMVService /home/nickotronz7/Documents/DevProjects/CMVService /home/nickotronz7/Documents/DevProjects/CMVService/cmake-build-debug /home/nickotronz7/Documents/DevProjects/CMVService/cmake-build-debug /home/nickotronz7/Documents/DevProjects/CMVService/cmake-build-debug/CMakeFiles/CMVService.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CMVService.dir/depend
