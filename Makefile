# Makefile for Recursive Maze Generator
# Author: AI Assistant
# Description: Build system for the C++ maze generation project

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -g
LDFLAGS = 

# Project name and directories
PROJECT_NAME = maze_generator
SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = bin

# Source files
SOURCES = main.cpp Maze.cpp
OBJECTS = $(SOURCES:%.cpp=$(OBJ_DIR)/%.o)
TARGET = $(BIN_DIR)/$(PROJECT_NAME)

# Default target
all: directories $(TARGET)

# Create necessary directories
directories:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	@echo "Linking $(TARGET)..."
	@$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)
	@echo "Build successful! Executable: $(TARGET)"

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Debug build
debug: CXXFLAGS += -DDEBUG -g3 -O0
debug: clean all

# Release build
release: CXXFLAGS += -DNDEBUG -O3
release: clean all

# Fast build (minimal optimization)
fast: CXXFLAGS = -std=c++17 -O1
fast: clean all

# Run the program
run: $(TARGET)
	@echo "Running $(PROJECT_NAME)..."
	@./$(TARGET)

# Run with sample parameters
demo: $(TARGET)
	@echo "Running maze generator demo..."
	@./$(TARGET)

# Check for memory leaks (requires valgrind)
memcheck: $(TARGET)
	@echo "Running memory check..."
	@valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# Profile the application (requires gprof)
profile: CXXFLAGS += -pg
profile: LDFLAGS += -pg
profile: clean $(TARGET)
	@echo "Running profiling build..."
	@./$(TARGET)
	@gprof $(TARGET) gmon.out > profile_analysis.txt
	@echo "Profile analysis saved to profile_analysis.txt"

# Static analysis (requires cppcheck)
analyze:
	@echo "Running static analysis..."
	@cppcheck --enable=all --std=c++17 $(SOURCES)

# Format code (requires clang-format)
format:
	@echo "Formatting code..."
	@clang-format -i *.cpp *.h

# Clean build artifacts
clean:
	@echo "Cleaning build artifacts..."
	@rm -rf $(OBJ_DIR) $(BIN_DIR)
	@rm -f *.o *.gch core gmon.out profile_analysis.txt

# Clean everything including backup files
distclean: clean
	@rm -f *~ *.bak *.swp *.tmp

# Install (copy to system bin - requires sudo)
install: $(TARGET)
	@echo "Installing $(PROJECT_NAME)..."
	@sudo cp $(TARGET) /usr/local/bin/
	@echo "Installation complete. You can now run '$(PROJECT_NAME)' from anywhere."

# Uninstall
uninstall:
	@echo "Uninstalling $(PROJECT_NAME)..."
	@sudo rm -f /usr/local/bin/$(PROJECT_NAME)
	@echo "Uninstallation complete."

# Create source distribution
dist: clean
	@echo "Creating source distribution..."
	@tar -czf $(PROJECT_NAME)-src.tar.gz *.cpp *.h Makefile README.md
	@echo "Source distribution created: $(PROJECT_NAME)-src.tar.gz"

# Show help
help:
	@echo "Available targets:"
	@echo "  all        - Build the project (default)"
	@echo "  debug      - Build with debug flags"
	@echo "  release    - Build with release optimization"
	@echo "  fast       - Build with minimal optimization"
	@echo "  run        - Build and run the program"
	@echo "  demo       - Build and run demonstration"
	@echo "  memcheck   - Run with valgrind memory checking"
	@echo "  profile    - Build with profiling and generate analysis"
	@echo "  analyze    - Run static code analysis"
	@echo "  format     - Format source code"
	@echo "  clean      - Remove build artifacts"
	@echo "  distclean  - Remove all generated files"
	@echo "  install    - Install to system (requires sudo)"
	@echo "  uninstall  - Remove from system (requires sudo)"
	@echo "  dist       - Create source distribution"
	@echo "  help       - Show this help message"

# Show project information
info:
	@echo "Project: $(PROJECT_NAME)"
	@echo "Compiler: $(CXX)"
	@echo "Flags: $(CXXFLAGS)"
	@echo "Sources: $(SOURCES)"
	@echo "Target: $(TARGET)"

# Test different compiler versions
test-compilers:
	@echo "Testing with different compilers..."
	@echo "Testing g++..."
	@make CXX=g++ clean all
	@echo "Testing clang++..."
	@make CXX=clang++ clean all

# Dependencies (automatically generated)
$(OBJ_DIR)/main.o: main.cpp Maze.h
$(OBJ_DIR)/Maze.o: Maze.cpp Maze.h

# Phony targets
.PHONY: all directories debug release fast run demo memcheck profile analyze format clean distclean install uninstall dist help info test-compilers

# Print variables for debugging
print-%:
	@echo $* = $($*)




