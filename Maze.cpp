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
    // Defensive validation: ensure dimensions look sane
    if (width <= 0 || height <= 0) {
        std::cout << "Invalid maze dimensions (width/height <= 0).\n";
        return;
    }

    // If grid is not initialized to the expected size, avoid UB and print a warning
    if (static_cast<int>(grid.size()) != height) {
        std::cout << "Maze grid not initialized or size mismatch.\n";
        return;
    }
    for (const auto &row : grid) {
        if (static_cast<int>(row.size()) != width) {
            std::cout << "Maze grid row size mismatch.\n";
            return;
        }
    }

    // Canvas dimensions: we use a compact representation where each cell
    // maps to coordinates (2*y+1, 2*x+1) and walls occupy the other positions.
    const int rows = height * 2 + 1;
    const int cols = width * 2 + 1;

    // Create canvas filled entirely with wall characters '#'
    std::vector<std::string> canvas(rows, std::string(cols, '#'));

    // Helper to safely set a character in the canvas
    auto setCanvas = [&](int r, int c, char ch) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) canvas[r][c] = ch;
    };

    // Iterate each logical cell and carve out the cell interior and any
    // openings where walls are absent. We interpret Cell.walls[] as:
    // walls[TOP]==true means a wall exists on the top side, false means an opening.
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            const Cell &cell = grid[y][x];
            int cr = 2 * y + 1; // canvas row
            int cc = 2 * x + 1; // canvas col

            // Mark the cell interior as an open space
            setCanvas(cr, cc, ' ');

            // If there's no top wall, open a passage above the cell
            if (cell.walls[TOP] == false) {
                setCanvas(cr - 1, cc, ' ');
            }

            // If there's no bottom wall, open a passage below the cell
            if (cell.walls[BOTTOM] == false) {
                setCanvas(cr + 1, cc, ' ');
            }

            // If there's no left wall, open a passage to the left
            if (cell.walls[LEFT] == false) {
                setCanvas(cr, cc - 1, ' ');
            }

            // If there's no right wall, open a passage to the right
            if (cell.walls[RIGHT] == false) {
                setCanvas(cr, cc + 1, ' ');
            }
        }
    }

    // Optionally open a conventional entrance and exit so the maze is usable
    // Entrance: top row just above cell (0,0) at (0,1). Exit: bottom row
    // just below cell (height-1,width-1) at (rows-1, cols-2).
    setCanvas(0, 1, ' ');
    setCanvas(rows - 1, cols - 2, ' ');

    // Print the canvas line by line
    for (const auto &line : canvas) {
        std::cout << line << '\n';
    }
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
