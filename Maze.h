#ifndef TEST_MAZE_H
#define TEST_MAZE_H

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
    bool walls[4];          // Walls: 0=top, 1=right, 2=bottom, 3=left
    int x, y;
    bool onPath = false;// Coordinates

    Cell() : visited(false), x(0), y(0) {
        // TODO: Initialize all walls as present (caller should implement)
        // Ramy
    }

    Cell(int x_pos, int y_pos) : visited(false), x(x_pos), y(y_pos) {
        // TODO: Initialize all walls as present and set coordinates
        // Ramy
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
 * Maze class implementing maze generation and solving API (skeleton)
 */
class Maze {
private:
    int width;              // TODO: maze width
    int height;             // TODO: maze height
    std::vector<std::vector<Cell>> grid;  // TODO: 2D grid of cells
    std::stack<Cell*> cellStack;          // TODO: stack for backtracking (if needed)
    std::mt19937 rng;                     // TODO: random number generator

    // Helper methods (to be implemented)
    Cell* getCell(int x, int y); // Ramy
    std::vector<Cell*> getUnvisitedNeighbors(Cell* cell); // Ramy
    void removeWall(Cell* current, Cell* neighbor); // Ramy
    Direction getDirection(Cell* from, Cell* to); // Ramy

public:
    // Constructors
    Maze();
    Maze(int width, int height);
    Maze(int width, int height, unsigned int seed); // Moaz
    Maze(int w, int h); // Youssef
   Maze(int w, int h, unsigned int seed); // Moaz

    // Core functionality
    void generateMaze();
    void generateMazeIterative(); // Ramy
    void generateMazeRecursive(int x = 0, int y = 0); // Ramy

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
    void printSolution() const; // Youssef

    // Debug and validation methods
    bool isMazeConnected(); // Check if all cells are reachable (Youssef)
};

#endif // TEST_MAZE_H
