# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = "/mnt/72d75732-3d9f-41aa-857d-7e5c3776d308/Work/CeePloosPloos/Classy Clash"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/72d75732-3d9f-41aa-857d-7e5c3776d308/Work/CeePloosPloos/Classy Clash"

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/cmake-gui -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start "/mnt/72d75732-3d9f-41aa-857d-7e5c3776d308/Work/CeePloosPloos/Classy Clash/CMakeFiles" "/mnt/72d75732-3d9f-41aa-857d-7e5c3776d308/Work/CeePloosPloos/Classy Clash//CMakeFiles/progress.marks"
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start "/mnt/72d75732-3d9f-41aa-857d-7e5c3776d308/Work/CeePloosPloos/Classy Clash/CMakeFiles" 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named game

# Build rule for target.
game: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 game
.PHONY : game

# fast build rule for target.
game/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/build
.PHONY : game/fast

src/basecharacter.o: src/basecharacter.cpp.o

.PHONY : src/basecharacter.o

# target to build an object file
src/basecharacter.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/basecharacter.cpp.o
.PHONY : src/basecharacter.cpp.o

src/basecharacter.i: src/basecharacter.cpp.i

.PHONY : src/basecharacter.i

# target to preprocess a source file
src/basecharacter.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/basecharacter.cpp.i
.PHONY : src/basecharacter.cpp.i

src/basecharacter.s: src/basecharacter.cpp.s

.PHONY : src/basecharacter.s

# target to generate assembly for a file
src/basecharacter.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/basecharacter.cpp.s
.PHONY : src/basecharacter.cpp.s

src/character.o: src/character.cpp.o

.PHONY : src/character.o

# target to build an object file
src/character.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/character.cpp.o
.PHONY : src/character.cpp.o

src/character.i: src/character.cpp.i

.PHONY : src/character.i

# target to preprocess a source file
src/character.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/character.cpp.i
.PHONY : src/character.cpp.i

src/character.s: src/character.cpp.s

.PHONY : src/character.s

# target to generate assembly for a file
src/character.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/character.cpp.s
.PHONY : src/character.cpp.s

src/enemy.o: src/enemy.cpp.o

.PHONY : src/enemy.o

# target to build an object file
src/enemy.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/enemy.cpp.o
.PHONY : src/enemy.cpp.o

src/enemy.i: src/enemy.cpp.i

.PHONY : src/enemy.i

# target to preprocess a source file
src/enemy.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/enemy.cpp.i
.PHONY : src/enemy.cpp.i

src/enemy.s: src/enemy.cpp.s

.PHONY : src/enemy.s

# target to generate assembly for a file
src/enemy.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/enemy.cpp.s
.PHONY : src/enemy.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/prop.o: src/prop.cpp.o

.PHONY : src/prop.o

# target to build an object file
src/prop.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/prop.cpp.o
.PHONY : src/prop.cpp.o

src/prop.i: src/prop.cpp.i

.PHONY : src/prop.i

# target to preprocess a source file
src/prop.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/prop.cpp.i
.PHONY : src/prop.cpp.i

src/prop.s: src/prop.cpp.s

.PHONY : src/prop.s

# target to generate assembly for a file
src/prop.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/prop.cpp.s
.PHONY : src/prop.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... game"
	@echo "... src/basecharacter.o"
	@echo "... src/basecharacter.i"
	@echo "... src/basecharacter.s"
	@echo "... src/character.o"
	@echo "... src/character.i"
	@echo "... src/character.s"
	@echo "... src/enemy.o"
	@echo "... src/enemy.i"
	@echo "... src/enemy.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/prop.o"
	@echo "... src/prop.i"
	@echo "... src/prop.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

