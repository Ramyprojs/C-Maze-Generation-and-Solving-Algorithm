#include "Maze.h"
#include <algorithm>
#include <chrono>

/**
 * test_maze/Maze.cpp
 *
 * Skeleton implementation: each function mirrors the real project's API
 * but contains only TODO comments describing intended behavior and
 * safe placeholder returns so the file compiles.
 */

// Constructors
Maze::Maze() : width(10), height(10) {
    // TODO: Initialize a 10x10 grid, set coordinates for each Cell,
    // and initialize RNG (e.g., with a time-based seed).
    
    // Initialize RNG with time-based seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    randomGenerator = std::default_random_engine(seed);
    
    // Initialize 10x10 grid
    grid.resize(height, std::vector<Cell>(width));
    
    // Set coordinates for each cell
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x].setCoordinates(x, y);
        }
    }
}
        // Moaz
}

Maze::Maze(int w, int h) : width(w), height(h) {
    // TODO: Resize grid to [height][width], set coordinates for each Cell,
    // and initialize RNG with a default seed.
    (void)w; (void)h;
    // Moaz
}

Maze::Maze(int w, int h, unsigned int seed) : width(w), height(h), rng(seed) {
    // TODO: Resize grid and initialize RNG with provided seed.
    (void)w; (void)h; (void)seed;
    // Moaz
}

// Helper methods
Cell* Maze::getCell(int x, int y) {
    // TODO: Return pointer to grid[y][x] if in bounds; otherwise return nullptr.
    (void)x; (void)y;
           // Ramy
    return nullptr;
}

std::vector<Cell*> Maze::getUnvisitedNeighbors(Cell* cell) {
    // TODO: Inspect adjacent cells (top/right/bottom/left) and collect
    // pointers to neighbors whose visited == false. Return the list.
    (void)cell;
           // Ramy
    return {};
}

void Maze::removeWall(Cell* current, Cell* neighbor) {
    // TODO: Determine the direction between current and neighbor and
    // clear the corresponding wall flags on both cells.
    (void)current; (void)neighbor;
    // Ramy
}

Direction Maze::getDirection(Cell* from, Cell* to) {
    // TODO: Compare coordinates and return TOP/RIGHT/BOTTOM/LEFT.
    (void)from; (void)to;
           // Ramy
    return TOP;
}

// Core functionality
void Maze::generateMaze() {
    // TODO: Default to iterative generation (call generateMazeIterative()).
        // Ramy
}

void Maze::generateMazeIterative() {
    // TODO: Implement stack-based DFS generation:
    // - reset maze
    // - start at (0,0), mark visited
    // - while stack not empty: pick unvisited neighbor, remove wall, push, else pop
        // Ramy
}

void Maze::generateMazeRecursive(int x, int y) {
    // TODO: Implement recursive DFS generation starting from (x,y):
    // - mark current visited
    // - shuffle unvisited neighbors and recurse
    (void)x; (void)y;
        // Ramy
}

// Display and utility methods
void Maze::printMaze() const {
    // TODO: Pretty-print maze using Unicode box drawing characters.
    // Ramy
}

void Maze::printMazeASCII() const {
    // TODO: Print a compact ASCII representation where walls are '#'.
    // Youssef
}

void Maze::printMazeDetailed() const {
    // TODO: Print dimensions, total cells, wall count, and call printMaze().
    // Youssef
}

void Maze::resetMaze() {
    // TODO: Clear the stack, set all cells visited=false and all walls=true.
    // Youssef
}

// Solver
bool Maze::solveMaze(int startX, int startY, int endX, int endY) {
    // TODO: Implement solver (BFS recommended) that finds a path from
    // (startX,startY) to (endX,endY). Use local visited/parent arrays
    // so you don't clash with generation's visited flags. Return true
    // if a solution is found.
    (void)startX; (void)startY; (void)endX; (void)endY;
           // Youssef
    return false;
}

void Maze::printSolution() const {
    // TODO: Visualize the solution path on top of the maze output.
    // Youssef
}

// Debug and validation
bool Maze::isMazeConnected() {
    // TODO: Use DFS/BFS from (0,0) to count reachable cells and
    // compare against width*height; return true if equal.
    return false;
    // Youssef
}

