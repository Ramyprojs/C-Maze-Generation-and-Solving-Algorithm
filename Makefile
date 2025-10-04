CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -g
OBJ = main.o Maze.o
TARGET = test_maze

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

main.o: main.cpp Maze.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Maze.o: Maze.cpp Maze.h
	$(CXX) $(CXXFLAGS) -c Maze.cpp

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
