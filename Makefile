# ============================================================================
# MAKEFILE TEMPLATE FOR MAZE GENERATOR PROJECT
# ============================================================================
# 
# This Makefile provides a complete build system for your C++ maze project.
# Study the structure and commands to understand how C++ projects are built.
#
# LEARNING OBJECTIVES:
# 1. Understand compilation process (preprocessing, compiling, linking)
# 2. Learn about object files and dependencies
# 3. Understand automatic variables and pattern rules
# 4. Learn about different build configurations (debug/release)
# 5. Understand project organization and build automation
#
# TODO: Read through each section and understand what it does
# ============================================================================

# ----------------------------------------------------------------------------
# COMPILER CONFIGURATION
# ----------------------------------------------------------------------------
# TODO: Understand these compiler settings

# The C++ compiler to use
CXX = g++

# Compiler flags explained:
# -std=c++17    : Use C++17 standard (required for our features)
# -Wall         : Enable all common warnings
# -Wextra       : Enable extra warnings
# -O2           : Optimize for speed (level 2)
# -g            : Include debug information
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -g

# Linker flags (empty for this simple project)
LDFLAGS = 

# TODO: Try experimenting with different optimization levels:
# -O0 (no optimization), -O1 (basic), -O2 (recommended), -O3 (aggressive)

# ----------------------------------------------------------------------------
# PROJECT STRUCTURE
# ----------------------------------------------------------------------------
# TODO: Understand the project organization

# Project name - change this if you want a different executable name
PROJECT_NAME = maze_generator

# Source directory (where .cpp files are located)
SRC_DIR = .

# Object files directory (where .o files will be created)
OBJ_DIR = obj

# Binary directory (where the final executable will be placed)
BIN_DIR = bin

# ----------------------------------------------------------------------------
# FILE LISTS
# ----------------------------------------------------------------------------
# TODO: Add your source files here as you create them

# List all your .cpp source files here
# If you add more .cpp files, add them to this list
SOURCES = main.cpp Maze.cpp

# Automatically generate object file names from source files
# This replaces .cpp with .o and puts them in the obj directory
OBJECTS = $(SOURCES:%.cpp=$(OBJ_DIR)/%.o)

# The final executable target
TARGET = $(BIN_DIR)/$(PROJECT_NAME)

# ----------------------------------------------------------------------------
# BUILD TARGETS
# ----------------------------------------------------------------------------

# DEFAULT TARGET: Build everything
# When you type "make" without arguments, this runs
# TODO: Try running "make" to build your project
all: directories $(TARGET)

# Create necessary directories if they don't exist
# The @ symbol suppresses the command from being printed
# TODO: Understand why we need to create directories first
directories:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR)

# LINKING STEP: Create the final executable from object files
# $@ means "the target name" ($(TARGET))
# $^ means "all prerequisites" ($(OBJECTS))
# TODO: This is where all object files are linked together
$(TARGET): $(OBJECTS)
	@echo "Linking $(TARGET)..."
	@$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)
	@echo "Build successful! Executable: $(TARGET)"

# COMPILATION STEP: Create object files from source files
# This is a pattern rule: %.o matches any .o file
# $< means "the first prerequisite" (the .cpp file)
# $@ means "the target" (the .o file)
# TODO: This compiles each .cpp file into a .o file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# ----------------------------------------------------------------------------
# SPECIAL BUILD CONFIGURATIONS
# ----------------------------------------------------------------------------

# DEBUG BUILD: Extra debugging information, no optimization
# TODO: Use this when you need to debug your program
debug: CXXFLAGS += -DDEBUG -g3 -O0
debug: clean all
	@echo "Debug build complete. Use gdb to debug: gdb $(TARGET)"

# RELEASE BUILD: Maximum optimization, no debug info
# TODO: Use this for final version of your program
release: CXXFLAGS += -DNDEBUG -O3
release: clean all
	@echo "Release build complete. Optimized for performance."

# FAST BUILD: Minimal optimization for quick compilation
# TODO: Use this during development for faster builds
fast: CXXFLAGS = -std=c++17 -O1
fast: clean all
	@echo "Fast build complete."

# ----------------------------------------------------------------------------
# UTILITY TARGETS
# ----------------------------------------------------------------------------

# RUN THE PROGRAM: Build and execute
# TODO: Try "make run" to build and run your program
run: $(TARGET)
	@echo "Running $(PROJECT_NAME)..."
	@./$(TARGET)

# DEMO: Same as run, but with descriptive output
demo: $(TARGET)
	@echo "Running maze generator demo..."
	@./$(TARGET)

# ----------------------------------------------------------------------------
# DEVELOPMENT TOOLS
# ----------------------------------------------------------------------------
# TODO: These targets help with code quality and debugging

# MEMORY CHECK: Run with valgrind to detect memory leaks
# TODO: Install valgrind and use this to check for memory problems
memcheck: $(TARGET)
	@echo "Running memory check..."
	@valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# PROFILING: Build with profiling support and analyze performance
# TODO: Use this to find performance bottlenecks
profile: CXXFLAGS += -pg
profile: LDFLAGS += -pg
profile: clean $(TARGET)
	@echo "Running profiling build..."
	@./$(TARGET)
	@gprof $(TARGET) gmon.out > profile_analysis.txt
	@echo "Profile analysis saved to profile_analysis.txt"

# STATIC ANALYSIS: Check code for potential issues
# TODO: Install cppcheck and use this to find code problems
analyze:
	@echo "Running static analysis..."
	@cppcheck --enable=all --std=c++17 $(SOURCES)

# CODE FORMATTING: Automatically format your code
# TODO: Install clang-format and use this to keep code neat
format:
	@echo "Formatting code..."
	@clang-format -i *.cpp *.h

# ----------------------------------------------------------------------------
# CLEANING TARGETS
# ----------------------------------------------------------------------------

# CLEAN: Remove all build artifacts
# TODO: Use this to clean up build files
clean:
	@echo "Cleaning build artifacts..."
	@rm -rf $(OBJ_DIR) $(BIN_DIR)
	@rm -f *.o *.gch core gmon.out profile_analysis.txt

# DEEP CLEAN: Remove everything including temporary files
distclean: clean
	@rm -f *~ *.bak *.swp *.tmp

# ----------------------------------------------------------------------------
# INSTALLATION TARGETS
# ----------------------------------------------------------------------------
# TODO: These allow system-wide installation (optional)

# INSTALL: Copy to system binary directory (requires sudo)
install: $(TARGET)
	@echo "Installing $(PROJECT_NAME)..."
	@sudo cp $(TARGET) /usr/local/bin/
	@echo "Installation complete. Run '$(PROJECT_NAME)' from anywhere."

# UNINSTALL: Remove from system
uninstall:
	@echo "Uninstalling $(PROJECT_NAME)..."
	@sudo rm -f /usr/local/bin/$(PROJECT_NAME)
	@echo "Uninstallation complete."

# ----------------------------------------------------------------------------
# DISTRIBUTION TARGETS
# ----------------------------------------------------------------------------

# CREATE SOURCE PACKAGE: Make a .tar.gz file with all source code
dist: clean
	@echo "Creating source distribution..."
	@tar -czf $(PROJECT_NAME)-src.tar.gz *.cpp *.h Makefile README.md
	@echo "Source distribution created: $(PROJECT_NAME)-src.tar.gz"

# ----------------------------------------------------------------------------
# HELP AND INFORMATION
# ----------------------------------------------------------------------------

# HELP: Show all available targets and their descriptions
# TODO: Run "make help" to see all available commands
help:
	@echo "Available targets:"
	@echo "  all        - Build the project (default)"
	@echo "  debug      - Build with debug flags (-g3 -O0)"
	@echo "  release    - Build with release optimization (-O3)"
	@echo "  fast       - Build with minimal optimization (-O1)"
	@echo "  run        - Build and run the program"
	@echo "  demo       - Build and run demonstration"
	@echo "  memcheck   - Run with valgrind memory checking"
	@echo "  profile    - Build with profiling and generate analysis"
	@echo "  analyze    - Run static code analysis with cppcheck"
	@echo "  format     - Format source code with clang-format"
	@echo "  clean      - Remove build artifacts"
	@echo "  distclean  - Remove all generated files"
	@echo "  install    - Install to system (requires sudo)"
	@echo "  uninstall  - Remove from system (requires sudo)"
	@echo "  dist       - Create source distribution (.tar.gz)"
	@echo "  help       - Show this help message"
	@echo "  info       - Show project information"

# PROJECT INFO: Display project configuration
info:
	@echo "Project: $(PROJECT_NAME)"
	@echo "Compiler: $(CXX)"
	@echo "Flags: $(CXXFLAGS)"
	@echo "Sources: $(SOURCES)"
	@echo "Objects: $(OBJECTS)"
	@echo "Target: $(TARGET)"

# ----------------------------------------------------------------------------
# COMPILER TESTING
# ----------------------------------------------------------------------------

# TEST DIFFERENT COMPILERS: Useful for compatibility testing
# TODO: Try this to test with different compilers
test-compilers:
	@echo "Testing with different compilers..."
	@echo "Testing g++..."
	@make CXX=g++ clean all
	@echo "Testing clang++..."
	@make CXX=clang++ clean all

# ----------------------------------------------------------------------------
# DEPENDENCY MANAGEMENT
# ----------------------------------------------------------------------------
# TODO: These lines tell Make about file dependencies

# Explicit dependencies - update these when you add #include statements
$(OBJ_DIR)/main.o: main.cpp Maze.h
$(OBJ_DIR)/Maze.o: Maze.cpp Maze.h

# If you add more source files, add their dependencies here
# Example: $(OBJ_DIR)/NewFile.o: NewFile.cpp NewFile.h Maze.h

# ----------------------------------------------------------------------------
# ADVANCED FEATURES
# ----------------------------------------------------------------------------

# PHONY TARGETS: These don't create files with the same name
# TODO: Understand why we need .PHONY
.PHONY: all directories debug release fast run demo memcheck profile analyze format clean distclean install uninstall dist help info test-compilers

# VARIABLE DEBUGGING: Print any variable value
# Usage: make print-VARIABLE_NAME
# Example: make print-SOURCES
print-%:
	@echo $* = $($*)

# ----------------------------------------------------------------------------
# MAKEFILE LEARNING EXERCISES
# ----------------------------------------------------------------------------

# TODO EXERCISES FOR STUDENTS:
# 
# 1. BASIC USAGE:
#    - Run "make" to build the project
#    - Run "make clean" to clean up
#    - Run "make run" to build and execute
#    - Run "make help" to see all options
# 
# 2. EXPERIMENT WITH FLAGS:
#    - Try "make debug" for debugging build
#    - Try "make release" for optimized build
#    - Compare performance between debug and release
# 
# 3. ADD NEW FEATURES:
#    - Add a new .cpp file to the project
#    - Update SOURCES variable to include it
#    - Add its dependencies below
#    - Test that it builds correctly
# 
# 4. UNDERSTAND DEPENDENCIES:
#    - Modify Maze.h and run "make"
#    - Notice which files get recompiled
#    - Understand why dependency tracking matters
# 
# 5. EXPLORE TOOLS:
#    - Try "make analyze" if you have cppcheck
#    - Try "make format" if you have clang-format
#    - Try "make memcheck" if you have valgrind
# 
# 6. CUSTOMIZATION:
#    - Change PROJECT_NAME to something else
#    - Add your own compiler flags
#    - Create custom build configurations

# ----------------------------------------------------------------------------
# COMMON MAKEFILE PATTERNS EXPLAINED
# ----------------------------------------------------------------------------

# AUTOMATIC VARIABLES:
# $@  - The target name
# $<  - The first prerequisite
# $^  - All prerequisites
# $?  - Prerequisites newer than target
# $*  - The stem of the pattern match

# PATTERN RULES:
# %.o: %.cpp  - Any .o file depends on corresponding .cpp file
# $(VAR:old=new) - Replace 'old' with 'new' in $(VAR)

# DIRECTORY CREATION:
# mkdir -p  - Create directory and parents if needed
# @command  - Don't echo the command when running

# CONDITIONAL COMPILATION:
# target: CXXFLAGS += extra_flags  - Add flags for specific target
# target: prerequisite             - Target depends on prerequisite

# ----------------------------------------------------------------------------
# END OF MAKEFILE
# ----------------------------------------------------------------------------

