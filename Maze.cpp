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
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return &grid[y][x];
    }
    return nullptr;
}   //Ramy

std::vector<Cell*> Maze::getUnvisitedNeighbors(Cell* cell) {
    std::vector<Cell*> neighbors;
    
    if (!cell) return neighbors;
    
    // Check all four directions
    Cell* top = getCell(cell->x, cell->y - 1);
    Cell* right = getCell(cell->x + 1, cell->y);
    Cell* bottom = getCell(cell->x, cell->y + 1);
    Cell* left = getCell(cell->x - 1, cell->y);
    
    if (top && !top->visited) neighbors.push_back(top);
    if (right && !right->visited) neighbors.push_back(right);
    if (bottom && !bottom->visited) neighbors.push_back(bottom);
    if (left && !left->visited) neighbors.push_back(left);
    
    return neighbors;
}   //Ramy

void Maze::removeWall(Cell* current, Cell* neighbor) {
    if (!current || !neighbor) return;
    
    Direction dir = getDirection(current, neighbor);
    
    // Remove wall from current cell
    current->walls[dir] = false;
    
    // Remove corresponding wall from neighbor
    switch (dir) {
        case TOP:
            neighbor->walls[BOTTOM] = false;
            break;
        case RIGHT:
            neighbor->walls[LEFT] = false;
            break;
        case BOTTOM:
            neighbor->walls[TOP] = false;
            break;
        case LEFT:
            neighbor->walls[RIGHT] = false;
            break;
    }
}  //Ramy

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
    resetMaze();
    
    // Start from top-left corner
    Cell* currentCell = getCell(0, 0);
    currentCell->visited = true;
    cellStack.push(currentCell);
    
    while (!cellStack.empty()) {
        currentCell = cellStack.top();
        
        // Get unvisited neighbors
        std::vector<Cell*> neighbors = getUnvisitedNeighbors(currentCell);
        
        if (!neighbors.empty()) {
            // Choose random neighbor
            std::uniform_int_distribution<int> dist(0, neighbors.size() - 1);
            Cell* chosenNeighbor = neighbors[dist(rng)];
            
            // Remove wall between current and chosen neighbor
            removeWall(currentCell, chosenNeighbor);
            
            // Mark chosen neighbor as visited and push to stack
            chosenNeighbor->visited = true;
            cellStack.push(chosenNeighbor);
        } else {
            // Backtrack - pop from stack
            cellStack.pop();
        }
    }
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

