# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/linxing/concurrency/net/test_base/test_sock

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/linxing/concurrency/net/test_base/test_sock

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/test.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/test.cpp.o: test.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/linxing/concurrency/net/test_base/test_sock/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test.dir/test.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test.dir/test.cpp.o -c /home/linxing/concurrency/net/test_base/test_sock/test.cpp

CMakeFiles/test.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/test.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/linxing/concurrency/net/test_base/test_sock/test.cpp > CMakeFiles/test.dir/test.cpp.i

CMakeFiles/test.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/test.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/linxing/concurrency/net/test_base/test_sock/test.cpp -o CMakeFiles/test.dir/test.cpp.s

CMakeFiles/test.dir/test.cpp.o.requires:
.PHONY : CMakeFiles/test.dir/test.cpp.o.requires

CMakeFiles/test.dir/test.cpp.o.provides: CMakeFiles/test.dir/test.cpp.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/test.cpp.o.provides.build
.PHONY : CMakeFiles/test.dir/test.cpp.o.provides

CMakeFiles/test.dir/test.cpp.o.provides.build: CMakeFiles/test.dir/test.cpp.o

CMakeFiles/test.dir/socket.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/socket.cpp.o: socket.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/linxing/concurrency/net/test_base/test_sock/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test.dir/socket.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test.dir/socket.cpp.o -c /home/linxing/concurrency/net/test_base/test_sock/socket.cpp

CMakeFiles/test.dir/socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/socket.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/linxing/concurrency/net/test_base/test_sock/socket.cpp > CMakeFiles/test.dir/socket.cpp.i

CMakeFiles/test.dir/socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/socket.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/linxing/concurrency/net/test_base/test_sock/socket.cpp -o CMakeFiles/test.dir/socket.cpp.s

CMakeFiles/test.dir/socket.cpp.o.requires:
.PHONY : CMakeFiles/test.dir/socket.cpp.o.requires

CMakeFiles/test.dir/socket.cpp.o.provides: CMakeFiles/test.dir/socket.cpp.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/socket.cpp.o.provides.build
.PHONY : CMakeFiles/test.dir/socket.cpp.o.provides

CMakeFiles/test.dir/socket.cpp.o.provides.build: CMakeFiles/test.dir/socket.cpp.o

CMakeFiles/test.dir/socket_util.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/socket_util.cpp.o: socket_util.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/linxing/concurrency/net/test_base/test_sock/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test.dir/socket_util.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test.dir/socket_util.cpp.o -c /home/linxing/concurrency/net/test_base/test_sock/socket_util.cpp

CMakeFiles/test.dir/socket_util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/socket_util.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/linxing/concurrency/net/test_base/test_sock/socket_util.cpp > CMakeFiles/test.dir/socket_util.cpp.i

CMakeFiles/test.dir/socket_util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/socket_util.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/linxing/concurrency/net/test_base/test_sock/socket_util.cpp -o CMakeFiles/test.dir/socket_util.cpp.s

CMakeFiles/test.dir/socket_util.cpp.o.requires:
.PHONY : CMakeFiles/test.dir/socket_util.cpp.o.requires

CMakeFiles/test.dir/socket_util.cpp.o.provides: CMakeFiles/test.dir/socket_util.cpp.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/socket_util.cpp.o.provides.build
.PHONY : CMakeFiles/test.dir/socket_util.cpp.o.provides

CMakeFiles/test.dir/socket_util.cpp.o.provides.build: CMakeFiles/test.dir/socket_util.cpp.o

CMakeFiles/test.dir/ip_address.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/ip_address.cpp.o: ip_address.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/linxing/concurrency/net/test_base/test_sock/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test.dir/ip_address.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test.dir/ip_address.cpp.o -c /home/linxing/concurrency/net/test_base/test_sock/ip_address.cpp

CMakeFiles/test.dir/ip_address.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/ip_address.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/linxing/concurrency/net/test_base/test_sock/ip_address.cpp > CMakeFiles/test.dir/ip_address.cpp.i

CMakeFiles/test.dir/ip_address.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/ip_address.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/linxing/concurrency/net/test_base/test_sock/ip_address.cpp -o CMakeFiles/test.dir/ip_address.cpp.s

CMakeFiles/test.dir/ip_address.cpp.o.requires:
.PHONY : CMakeFiles/test.dir/ip_address.cpp.o.requires

CMakeFiles/test.dir/ip_address.cpp.o.provides: CMakeFiles/test.dir/ip_address.cpp.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/ip_address.cpp.o.provides.build
.PHONY : CMakeFiles/test.dir/ip_address.cpp.o.provides

CMakeFiles/test.dir/ip_address.cpp.o.provides.build: CMakeFiles/test.dir/ip_address.cpp.o

CMakeFiles/test.dir/thread.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/thread.cpp.o: thread.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/linxing/concurrency/net/test_base/test_sock/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test.dir/thread.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test.dir/thread.cpp.o -c /home/linxing/concurrency/net/test_base/test_sock/thread.cpp

CMakeFiles/test.dir/thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/thread.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/linxing/concurrency/net/test_base/test_sock/thread.cpp > CMakeFiles/test.dir/thread.cpp.i

CMakeFiles/test.dir/thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/thread.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/linxing/concurrency/net/test_base/test_sock/thread.cpp -o CMakeFiles/test.dir/thread.cpp.s

CMakeFiles/test.dir/thread.cpp.o.requires:
.PHONY : CMakeFiles/test.dir/thread.cpp.o.requires

CMakeFiles/test.dir/thread.cpp.o.provides: CMakeFiles/test.dir/thread.cpp.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/thread.cpp.o.provides.build
.PHONY : CMakeFiles/test.dir/thread.cpp.o.provides

CMakeFiles/test.dir/thread.cpp.o.provides.build: CMakeFiles/test.dir/thread.cpp.o

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/test.cpp.o" \
"CMakeFiles/test.dir/socket.cpp.o" \
"CMakeFiles/test.dir/socket_util.cpp.o" \
"CMakeFiles/test.dir/ip_address.cpp.o" \
"CMakeFiles/test.dir/thread.cpp.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

test: CMakeFiles/test.dir/test.cpp.o
test: CMakeFiles/test.dir/socket.cpp.o
test: CMakeFiles/test.dir/socket_util.cpp.o
test: CMakeFiles/test.dir/ip_address.cpp.o
test: CMakeFiles/test.dir/thread.cpp.o
test: CMakeFiles/test.dir/build.make
test: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: test
.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/requires: CMakeFiles/test.dir/test.cpp.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/socket.cpp.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/socket_util.cpp.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/ip_address.cpp.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/thread.cpp.o.requires
.PHONY : CMakeFiles/test.dir/requires

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	cd /home/linxing/concurrency/net/test_base/test_sock && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/linxing/concurrency/net/test_base/test_sock /home/linxing/concurrency/net/test_base/test_sock /home/linxing/concurrency/net/test_base/test_sock /home/linxing/concurrency/net/test_base/test_sock /home/linxing/concurrency/net/test_base/test_sock/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test.dir/depend
