#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <stack>
#include <random>
#include <iostream>
#include <iomanip>

/**
 * Cell structure representing each position in the maze
 */
struct Cell {
    bool visited;           // Has this cell been visited during generation?
    bool walls[4];         // Walls: 0=top, 1=right, 2=bottom, 3=left
    int x, y;              // Coordinates
    
    Cell() : visited(false), x(0), y(0) {
        // Initialize all walls as present
        for (int i = 0; i < 4; i++) {
            walls[i] = true;
        }
    }
    
    Cell(int x_pos, int y_pos) : visited(false), x(x_pos), y(y_pos) {
        // Initialize all walls as present
        for (int i = 0; i < 4; i++) {
            walls[i] = true;
        }
    }
};

/**
 * Direction enumeration for easier navigation
 */
enum Direction {
    TOP = 0,
    RIGHT = 1,
    BOTTOM = 2,
    LEFT = 3
};

/**
 * Maze class implementing recursive maze generation algorithm
 */
class Maze {
private:
    int width;              // Maze width
    int height;             // Maze height
    std::vector<std::vector<Cell>> grid;  // 2D grid of cells
    std::stack<Cell*> cellStack;          // Stack for backtracking
    std::mt19937 rng;                     // Random number generator
    
    // Helper methods
    Cell* getCell(int x, int y);
    std::vector<Cell*> getUnvisitedNeighbors(Cell* cell);
    void removeWall(Cell* current, Cell* neighbor);
    Direction getDirection(Cell* from, Cell* to);
    
public:
    // Constructors
    Maze();
    Maze(int w, int h);
    Maze(int w, int h, unsigned int seed);
    
    // Core functionality
    void generateMaze();
    void generateMazeIterative();
    void generateMazeRecursive(int x = 0, int y = 0);
    
    // Display and utility methods
    void printMaze() const;
    void printMazeASCII() const;
    void printMazeDetailed() const;
    void resetMaze();
    
    // Getters
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    const std::vector<std::vector<Cell>>& getGrid() const { return grid; }
    
    // Maze solving (bonus feature)
    bool solveMaze(int startX = 0, int startY = 0, int endX = -1, int endY = -1);
    void printSolution() const;
    
    // Debug and validation methods
    bool isMazeConnected(); // Check if all cells are reachable
};

#endif // MAZE_H
