# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/pff/CLionProjects/spo_lab3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pff/CLionProjects/spo_lab3

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/pff/CLionProjects/spo_lab3/CMakeFiles /home/pff/CLionProjects/spo_lab3/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/pff/CLionProjects/spo_lab3/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named spo_lab3

# Build rule for target.
spo_lab3: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 spo_lab3
.PHONY : spo_lab3

# fast build rule for target.
spo_lab3/fast:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/build
.PHONY : spo_lab3/fast

src/client/client.o: src/client/client.c.o

.PHONY : src/client/client.o

# target to build an object file
src/client/client.c.o:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/client/client.c.o
.PHONY : src/client/client.c.o

src/client/client.i: src/client/client.c.i

.PHONY : src/client/client.i

# target to preprocess a source file
src/client/client.c.i:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/client/client.c.i
.PHONY : src/client/client.c.i

src/client/client.s: src/client/client.c.s

.PHONY : src/client/client.s

# target to generate assembly for a file
src/client/client.c.s:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/client/client.c.s
.PHONY : src/client/client.c.s

src/client/clientEvent.o: src/client/clientEvent.c.o

.PHONY : src/client/clientEvent.o

# target to build an object file
src/client/clientEvent.c.o:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/client/clientEvent.c.o
.PHONY : src/client/clientEvent.c.o

src/client/clientEvent.i: src/client/clientEvent.c.i

.PHONY : src/client/clientEvent.i

# target to preprocess a source file
src/client/clientEvent.c.i:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/client/clientEvent.c.i
.PHONY : src/client/clientEvent.c.i

src/client/clientEvent.s: src/client/clientEvent.c.s

.PHONY : src/client/clientEvent.s

# target to generate assembly for a file
src/client/clientEvent.c.s:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/client/clientEvent.c.s
.PHONY : src/client/clientEvent.c.s

src/client/network.o: src/client/network.c.o

.PHONY : src/client/network.o

# target to build an object file
src/client/network.c.o:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/client/network.c.o
.PHONY : src/client/network.c.o

src/client/network.i: src/client/network.c.i

.PHONY : src/client/network.i

# target to preprocess a source file
src/client/network.c.i:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/client/network.c.i
.PHONY : src/client/network.c.i

src/client/network.s: src/client/network.c.s

.PHONY : src/client/network.s

# target to generate assembly for a file
src/client/network.c.s:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/client/network.c.s
.PHONY : src/client/network.c.s

src/client/ui.o: src/client/ui.c.o

.PHONY : src/client/ui.o

# target to build an object file
src/client/ui.c.o:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/client/ui.c.o
.PHONY : src/client/ui.c.o

src/client/ui.i: src/client/ui.c.i

.PHONY : src/client/ui.i

# target to preprocess a source file
src/client/ui.c.i:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/client/ui.c.i
.PHONY : src/client/ui.c.i

src/client/ui.s: src/client/ui.c.s

.PHONY : src/client/ui.s

# target to generate assembly for a file
src/client/ui.c.s:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/client/ui.c.s
.PHONY : src/client/ui.c.s

src/common/book.o: src/common/book.c.o

.PHONY : src/common/book.o

# target to build an object file
src/common/book.c.o:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/common/book.c.o
.PHONY : src/common/book.c.o

src/common/book.i: src/common/book.c.i

.PHONY : src/common/book.i

# target to preprocess a source file
src/common/book.c.i:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/common/book.c.i
.PHONY : src/common/book.c.i

src/common/book.s: src/common/book.c.s

.PHONY : src/common/book.s

# target to generate assembly for a file
src/common/book.c.s:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/common/book.c.s
.PHONY : src/common/book.c.s

src/common/event.o: src/common/event.c.o

.PHONY : src/common/event.o

# target to build an object file
src/common/event.c.o:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/common/event.c.o
.PHONY : src/common/event.c.o

src/common/event.i: src/common/event.c.i

.PHONY : src/common/event.i

# target to preprocess a source file
src/common/event.c.i:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/common/event.c.i
.PHONY : src/common/event.c.i

src/common/event.s: src/common/event.c.s

.PHONY : src/common/event.s

# target to generate assembly for a file
src/common/event.c.s:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/common/event.c.s
.PHONY : src/common/event.c.s

src/common/protocol.o: src/common/protocol.c.o

.PHONY : src/common/protocol.o

# target to build an object file
src/common/protocol.c.o:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/common/protocol.c.o
.PHONY : src/common/protocol.c.o

src/common/protocol.i: src/common/protocol.c.i

.PHONY : src/common/protocol.i

# target to preprocess a source file
src/common/protocol.c.i:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/common/protocol.c.i
.PHONY : src/common/protocol.c.i

src/common/protocol.s: src/common/protocol.c.s

.PHONY : src/common/protocol.s

# target to generate assembly for a file
src/common/protocol.c.s:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/common/protocol.c.s
.PHONY : src/common/protocol.c.s

src/common/utils.o: src/common/utils.c.o

.PHONY : src/common/utils.o

# target to build an object file
src/common/utils.c.o:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/common/utils.c.o
.PHONY : src/common/utils.c.o

src/common/utils.i: src/common/utils.c.i

.PHONY : src/common/utils.i

# target to preprocess a source file
src/common/utils.c.i:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/common/utils.c.i
.PHONY : src/common/utils.c.i

src/common/utils.s: src/common/utils.c.s

.PHONY : src/common/utils.s

# target to generate assembly for a file
src/common/utils.c.s:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/common/utils.c.s
.PHONY : src/common/utils.c.s

src/main.o: src/main.c.o

.PHONY : src/main.o

# target to build an object file
src/main.c.o:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/main.c.o
.PHONY : src/main.c.o

src/main.i: src/main.c.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.c.i:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/main.c.i
.PHONY : src/main.c.i

src/main.s: src/main.c.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.c.s:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/main.c.s
.PHONY : src/main.c.s

src/server/network.o: src/server/network.c.o

.PHONY : src/server/network.o

# target to build an object file
src/server/network.c.o:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/server/network.c.o
.PHONY : src/server/network.c.o

src/server/network.i: src/server/network.c.i

.PHONY : src/server/network.i

# target to preprocess a source file
src/server/network.c.i:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/server/network.c.i
.PHONY : src/server/network.c.i

src/server/network.s: src/server/network.c.s

.PHONY : src/server/network.s

# target to generate assembly for a file
src/server/network.c.s:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/server/network.c.s
.PHONY : src/server/network.c.s

src/server/server.o: src/server/server.c.o

.PHONY : src/server/server.o

# target to build an object file
src/server/server.c.o:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/server/server.c.o
.PHONY : src/server/server.c.o

src/server/server.i: src/server/server.c.i

.PHONY : src/server/server.i

# target to preprocess a source file
src/server/server.c.i:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/server/server.c.i
.PHONY : src/server/server.c.i

src/server/server.s: src/server/server.c.s

.PHONY : src/server/server.s

# target to generate assembly for a file
src/server/server.c.s:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/server/server.c.s
.PHONY : src/server/server.c.s

src/server/serverEvent.o: src/server/serverEvent.c.o

.PHONY : src/server/serverEvent.o

# target to build an object file
src/server/serverEvent.c.o:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/server/serverEvent.c.o
.PHONY : src/server/serverEvent.c.o

src/server/serverEvent.i: src/server/serverEvent.c.i

.PHONY : src/server/serverEvent.i

# target to preprocess a source file
src/server/serverEvent.c.i:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/server/serverEvent.c.i
.PHONY : src/server/serverEvent.c.i

src/server/serverEvent.s: src/server/serverEvent.c.s

.PHONY : src/server/serverEvent.s

# target to generate assembly for a file
src/server/serverEvent.c.s:
	$(MAKE) -f CMakeFiles/spo_lab3.dir/build.make CMakeFiles/spo_lab3.dir/src/server/serverEvent.c.s
.PHONY : src/server/serverEvent.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... spo_lab3"
	@echo "... src/client/client.o"
	@echo "... src/client/client.i"
	@echo "... src/client/client.s"
	@echo "... src/client/clientEvent.o"
	@echo "... src/client/clientEvent.i"
	@echo "... src/client/clientEvent.s"
	@echo "... src/client/network.o"
	@echo "... src/client/network.i"
	@echo "... src/client/network.s"
	@echo "... src/client/ui.o"
	@echo "... src/client/ui.i"
	@echo "... src/client/ui.s"
	@echo "... src/common/book.o"
	@echo "... src/common/book.i"
	@echo "... src/common/book.s"
	@echo "... src/common/event.o"
	@echo "... src/common/event.i"
	@echo "... src/common/event.s"
	@echo "... src/common/protocol.o"
	@echo "... src/common/protocol.i"
	@echo "... src/common/protocol.s"
	@echo "... src/common/utils.o"
	@echo "... src/common/utils.i"
	@echo "... src/common/utils.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/server/network.o"
	@echo "... src/server/network.i"
	@echo "... src/server/network.s"
	@echo "... src/server/server.o"
	@echo "... src/server/server.i"
	@echo "... src/server/server.s"
	@echo "... src/server/serverEvent.o"
	@echo "... src/server/serverEvent.i"
	@echo "... src/server/serverEvent.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

