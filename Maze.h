#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <stack>
#include <random>
#include <iostream>
#include <iomanip>

/**
 * TODO: Cell structure representing each position in the maze
 * 
 * INSTRUCTIONS:
 * 1. Create a struct called Cell that represents each cell in the maze
 * 2. Each cell should track:
 *    - Whether it has been visited during generation (bool visited)
 *    - Which walls are present (bool walls[4]) - 0=top, 1=right, 2=bottom, 3=left
 *    - Its coordinates (int x, int y)
 * 3. Include constructors to initialize the cell properly
 * 4. Initially, all walls should be present (true) and visited should be false
 */

// TODO: Define your Cell struct here
struct Cell {
    // TODO: Add member variables
    // bool visited;        // Has this cell been visited during generation?
    // bool walls[4];       // Walls: 0=top, 1=right, 2=bottom, 3=left  
    // int x, y;            // Coordinates
    
    // TODO: Add default constructor
    
    // TODO: Add parameterized constructor that takes x and y coordinates
};

/**
 * TODO: Direction enumeration for easier navigation
 * 
 * INSTRUCTIONS:
 * Create an enum called Direction with values:
 * TOP = 0, RIGHT = 1, BOTTOM = 2, LEFT = 3
 * This will help when working with walls and navigation
 */

// TODO: Define your Direction enum here
enum Direction {
    // TODO: Add direction values
};

/**
 * TODO: Maze class implementing maze generation algorithms
 * 
 * INSTRUCTIONS:
 * 1. Create a class called Maze that will contain all maze functionality
 * 2. It should have private member variables for:
 *    - width and height (int)
 *    - 2D grid of cells (std::vector<std::vector<Cell>>)
 *    - stack for backtracking (std::stack<Cell*>)
 *    - random number generator (std::mt19937)
 * 3. Include helper methods (private) and public interface methods
 */

class Maze {
private:
    // TODO: Add private member variables
    // int width;               // Maze width
    // int height;              // Maze height
    // std::vector<std::vector<Cell>> grid;  // 2D grid of cells
    // std::stack<Cell*> cellStack;          // Stack for backtracking
    // std::mt19937 rng;                     // Random number generator
    
    // TODO: Add private helper methods
    // Cell* getCell(int x, int y);                           // Get cell at coordinates
    // std::vector<Cell*> getUnvisitedNeighbors(Cell* cell);  // Get unvisited neighbors
    // void removeWall(Cell* current, Cell* neighbor);        // Remove wall between cells
    // Direction getDirection(Cell* from, Cell* to);          // Get direction between cells
    
public:
    // TODO: Add constructors
    // Maze();                              // Default constructor (10x10)
    // Maze(int w, int h);                  // Constructor with dimensions
    // Maze(int w, int h, unsigned int seed); // Constructor with dimensions and seed
    
    // TODO: Add core functionality methods
    // void generateMaze();                 // Main generation method
    // void generateMazeIterative();        // Iterative (stack-based) generation
    // void generateMazeRecursive(int x = 0, int y = 0);  // Recursive generation
    
    // TODO: Add display and utility methods
    // void printMaze() const;              // Print maze with Unicode characters
    // void printMazeASCII() const;         // Print maze with ASCII characters
    // void printMazeDetailed() const;      // Print detailed maze information
    // void resetMaze();                    // Reset maze to initial state
    
    // TODO: Add getter methods
    // int getWidth() const { return width; }
    // int getHeight() const { return height; }
    // const std::vector<std::vector<Cell>>& getGrid() const { return grid; }
    
    // TODO: Add bonus feature (maze solving)
    // bool solveMaze(int startX = 0, int startY = 0, int endX = -1, int endY = -1);
    // void printSolution() const;
};

/*
 * LEARNING OBJECTIVES:
 * 
 * After implementing this header file, you should understand:
 * 1. How to design classes and structures for complex data representation
 * 2. The importance of encapsulation (private vs public members)
 * 3. How to use STL containers (vector, stack) effectively
 * 4. Forward declarations and proper header file organization
 * 5. How to design APIs that are both powerful and easy to use
 * 
 * IMPLEMENTATION TIPS:
 * 1. Start with the Cell struct - it's the foundation
 * 2. Think about how cells relate to each other (neighbors)
 * 3. Consider how walls connect between adjacent cells
 * 4. Plan your coordinate system (0,0 at top-left is common)
 * 5. Remember that removing a wall affects TWO cells
 */

#endif // MAZE_H

