#include "Maze.h"
#include <algorithm>
#include <chrono>
#include <queue>

/**
 * Default constructor - creates a 10x10 maze
 */
Maze::Maze() : width(10), height(10), rng(std::chrono::steady_clock::now().time_since_epoch().count()) {
    grid.resize(height, std::vector<Cell>(width));
    
    // Initialize grid with coordinates
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y][x] = Cell(x, y);
        }
    }
}

/**
 * Constructor with custom dimensions
 */
Maze::Maze(int w, int h) : width(w), height(h), rng(std::chrono::steady_clock::now().time_since_epoch().count()) {
    grid.resize(height, std::vector<Cell>(width));
    
    // Initialize grid with coordinates
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y][x] = Cell(x, y);
        }
    }
}

/**
 * Constructor with custom dimensions and seed
 */
Maze::Maze(int w, int h, unsigned int seed) : width(w), height(h), rng(seed) {
    grid.resize(height, std::vector<Cell>(width));
    
    // Initialize grid with coordinates
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y][x] = Cell(x, y);
        }
    }
}

/**
 * Get cell at specific coordinates
 */
Cell* Maze::getCell(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return &grid[y][x];
    }
    return nullptr;
}

/**
 * Get all unvisited neighbors of a cell
 */
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
}

/**
 * Get direction from one cell to another
 */
Direction Maze::getDirection(Cell* from, Cell* to) {
    if (to->y < from->y) return TOP;
    if (to->x > from->x) return RIGHT;
    if (to->y > from->y) return BOTTOM;
    return LEFT;
}

/**
 * Remove wall between two adjacent cells
 */
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
}

/**
 * Main maze generation method (uses iterative approach by default)
 */
void Maze::generateMaze() {
    generateMazeIterative();
}

/**
 * Iterative maze generation using stack-based depth-first search
 */
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
}

/**
 * Recursive maze generation algorithm
 */
void Maze::generateMazeRecursive(int x, int y) {
    // Base case: if starting a new maze
    static bool isNewMaze = true;
    if (isNewMaze) {
        resetMaze();
        isNewMaze = false;
    }
    
    Cell* currentCell = getCell(x, y);
    if (!currentCell) {
        isNewMaze = true; // Reset for next call
        return;
    }
    
    currentCell->visited = true;
    
    // Get all unvisited neighbors
    std::vector<Cell*> neighbors = getUnvisitedNeighbors(currentCell);
    
    // Shuffle neighbors for randomness
    std::shuffle(neighbors.begin(), neighbors.end(), rng);
    
    // Recursively visit each unvisited neighbor
    for (Cell* neighbor : neighbors) {
        if (!neighbor->visited) {
            removeWall(currentCell, neighbor);
            generateMazeRecursive(neighbor->x, neighbor->y);
        }
    }
    
    // Check if we're done (all cells visited)
    bool allVisited = true;
    for (int cy = 0; cy < height && allVisited; cy++) {
        for (int cx = 0; cx < width && allVisited; cx++) {
            if (!grid[cy][cx].visited) {
                allVisited = false;
            }
        }
    }
    
    if (allVisited) {
        isNewMaze = true; // Reset for next call
    }
}

/**
 * Reset maze to initial state
 */
void Maze::resetMaze() {
    // Clear stack
    while (!cellStack.empty()) {
        cellStack.pop();
    }
    
    // Reset all cells
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y][x].visited = false;
            for (int i = 0; i < 4; i++) {
                grid[y][x].walls[i] = true;
            }
        }
    }
}

/**
 * Print maze in a simple format
 */
void Maze::printMaze() const {
    std::cout << "\n=== MAZE (" << width << "x" << height << ") ===\n";
    
    // Top border
    std::cout << "┌";
    for (int x = 0; x < width; x++) {
        std::cout << "──";
        if (x < width - 1) std::cout << "┬";
    }
    std::cout << "┐\n";
    
    // Maze content
    for (int y = 0; y < height; y++) {
        // Vertical walls and spaces
        std::cout << "│";
        for (int x = 0; x < width; x++) {
            std::cout << "  ";
            if (x < width - 1) {
                std::cout << (grid[y][x].walls[RIGHT] ? "│" : " ");
            }
        }
        std::cout << "│\n";
        
        // Horizontal walls (except for last row)
        if (y < height - 1) {
            std::cout << "├";
            for (int x = 0; x < width; x++) {
                std::cout << (grid[y][x].walls[BOTTOM] ? "──" : "  ");
                if (x < width - 1) {
                    // Corner character
                    bool hasBottom = grid[y][x].walls[BOTTOM];
                    bool hasRight = grid[y][x].walls[RIGHT];
                    bool hasBottomRight = grid[y][x + 1].walls[BOTTOM];
                    bool hasBottomLeft = grid[y + 1][x].walls[RIGHT];
                    
                    if (hasBottom && hasRight && hasBottomRight && hasBottomLeft) std::cout << "┼";
                    else if (hasBottom && hasBottomRight) std::cout << "┬";
                    else if (hasRight && hasBottomLeft) std::cout << "├";
                    else if (hasBottom || hasBottomRight) std::cout << "─";
                    else if (hasRight || hasBottomLeft) std::cout << "│";
                    else std::cout << " ";
                }
            }
            std::cout << "┤\n";
        }
    }
    
    // Bottom border
    std::cout << "└";
    for (int x = 0; x < width; x++) {
        std::cout << "──";
        if (x < width - 1) std::cout << "┴";
    }
    std::cout << "┘\n";
}

/**
 * Print maze in ASCII format (alternative visualization)
 */
void Maze::printMazeASCII() const {
    std::cout << "\n=== ASCII MAZE (" << width << "x" << height << ") ===\n";
    
    // Top border
    for (int x = 0; x < width * 2 + 1; x++) {
        std::cout << "#";
    }
    std::cout << "\n";
    
    for (int y = 0; y < height; y++) {
        // Left border
        std::cout << "#";
        
        // Cell content and right walls
        for (int x = 0; x < width; x++) {
            std::cout << " ";  // Cell space
            std::cout << (grid[y][x].walls[RIGHT] ? "#" : " ");
        }
        std::cout << "\n";
        
        // Bottom walls (except for last row)
        if (y < height - 1) {
            std::cout << "#";
            for (int x = 0; x < width; x++) {
                std::cout << (grid[y][x].walls[BOTTOM] ? "#" : " ");
                std::cout << "#";
            }
            std::cout << "\n";
        }
    }
    
    // Bottom border
    for (int x = 0; x < width * 2 + 1; x++) {
        std::cout << "#";
    }
    std::cout << "\n";
}

/**
 * Print detailed maze information
 */
void Maze::printMazeDetailed() const {
    std::cout << "\n=== DETAILED MAZE INFO ===\n";
    std::cout << "Dimensions: " << width << "x" << height << "\n";
    std::cout << "Total cells: " << width * height << "\n";
    
    int wallCount = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int w = 0; w < 4; w++) {
                if (grid[y][x].walls[w]) wallCount++;
            }
        }
    }
    std::cout << "Total walls: " << wallCount / 2 << "\n"; // Divide by 2 since walls are shared
    
    printMaze();
}

/**
 * Simple maze solver using DFS (bonus feature)
 */
bool Maze::solveMaze(int startX, int startY, int endX, int endY) {
    // Set default end position if not specified
    if (endX == -1) endX = width - 1;
    if (endY == -1) endY = height - 1;
    
    // Validate start and end positions
    if (startX < 0 || startX >= width || startY < 0 || startY >= height) {
        std::cout << "\nInvalid start position!\n";
        return false;
    }
    if (endX < 0 || endX >= width || endY < 0 || endY >= height) {
        std::cout << "\nInvalid end position!\n";
        return false;
    }
    
    // Use BFS to reliably find the shortest path from start to end.
    if (endX == -1) endX = width - 1;
    if (endY == -1) endY = height - 1;

    // Validate start and end positions
    if (startX < 0 || startX >= width || startY < 0 || startY >= height) {
        std::cout << "\nInvalid start position!\n";
        return false;
    }
    if (endX < 0 || endX >= width || endY < 0 || endY >= height) {
        std::cout << "\nInvalid end position!\n";
        return false;
    }

    // Local visited and parent trackers (do not modify grid visited flags here)
    std::vector<std::vector<bool>> visitedLocal(height, std::vector<bool>(width, false));
    std::vector<std::vector<std::pair<int,int>>> parent(height, std::vector<std::pair<int,int>>(width, {-1,-1}));

    std::queue<std::pair<int,int>> q;
    q.push({startX, startY});
    visitedLocal[startY][startX] = true;
    bool found = false;

    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();

        if (cx == endX && cy == endY) {
            found = true;
            break;
        }

        Cell* current = getCell(cx, cy);
        if (!current) continue;

        // Explore neighbors allowed by removed walls
        // TOP
        if (!current->walls[TOP]) {
            int nx = cx, ny = cy - 1;
            if (ny >= 0 && !visitedLocal[ny][nx]) {
                visitedLocal[ny][nx] = true;
                parent[ny][nx] = {cx, cy};
                q.push({nx, ny});
            }
        }
        // RIGHT
        if (!current->walls[RIGHT]) {
            int nx = cx + 1, ny = cy;
            if (nx < width && !visitedLocal[ny][nx]) {
                visitedLocal[ny][nx] = true;
                parent[ny][nx] = {cx, cy};
                q.push({nx, ny});
            }
        }
        // BOTTOM
        if (!current->walls[BOTTOM]) {
            int nx = cx, ny = cy + 1;
            if (ny < height && !visitedLocal[ny][nx]) {
                visitedLocal[ny][nx] = true;
                parent[ny][nx] = {cx, cy};
                q.push({nx, ny});
            }
        }
        // LEFT
        if (!current->walls[LEFT]) {
            int nx = cx - 1, ny = cy;
            if (nx >= 0 && !visitedLocal[ny][nx]) {
                visitedLocal[ny][nx] = true;
                parent[ny][nx] = {cx, cy};
                q.push({nx, ny});
            }
        }
    }

    if (!found) {
        std::cout << "\nNo solution found: end is unreachable from start.\n";
        return false;
    }

    // Reconstruct path length
    int pathLen = 0;
    int px = endX, py = endY;
    while (!(px == startX && py == startY)) {
        auto p = parent[py][px];
        if (p.first == -1) break; // safety
        px = p.first; py = p.second;
        pathLen++;
    }

    std::cout << "\nSolution found! Shortest path length: " << pathLen << " steps\n";
    return true;
}

/**
 * Print solution path (placeholder implementation)
 */
void Maze::printSolution() const {
    std::cout << "Solution visualization not implemented in this version.\n";
    std::cout << "Use solveMaze() method to find if a solution exists.\n";
}

/**
 * Check if the maze is properly connected (all cells reachable)
 */
bool Maze::isMazeConnected() {
    // Reset visited flags
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y][x].visited = false;
        }
    }
    
    // Use DFS to visit all reachable cells from (0,0)
    std::stack<Cell*> toVisit;
    Cell* start = getCell(0, 0);
    if (!start) return false;
    
    start->visited = true;
    toVisit.push(start);
    int visitedCount = 1;
    
    while (!toVisit.empty()) {
        Cell* current = toVisit.top();
        toVisit.pop();
        
        // Check all four directions
        if (!current->walls[TOP]) {
            Cell* neighbor = getCell(current->x, current->y - 1);
            if (neighbor && !neighbor->visited) {
                neighbor->visited = true;
                toVisit.push(neighbor);
                visitedCount++;
            }
        }
        if (!current->walls[RIGHT]) {
            Cell* neighbor = getCell(current->x + 1, current->y);
            if (neighbor && !neighbor->visited) {
                neighbor->visited = true;
                toVisit.push(neighbor);
                visitedCount++;
            }
        }
        if (!current->walls[BOTTOM]) {
            Cell* neighbor = getCell(current->x, current->y + 1);
            if (neighbor && !neighbor->visited) {
                neighbor->visited = true;
                toVisit.push(neighbor);
                visitedCount++;
            }
        }
        if (!current->walls[LEFT]) {
            Cell* neighbor = getCell(current->x - 1, current->y);
            if (neighbor && !neighbor->visited) {
                neighbor->visited = true;
                toVisit.push(neighbor);
                visitedCount++;
            }
        }
    }
    
    // All cells should be reachable in a proper maze
    int totalCells = width * height;
    std::cout << "\nMaze connectivity check:\n";
    std::cout << "Visited cells: " << visitedCount << "/" << totalCells << "\n";
    
    if (visitedCount == totalCells) {
        std::cout << "✓ Maze is properly connected!\n";
        return true;
    } else {
        std::cout << "✗ Maze has isolated regions! " << (totalCells - visitedCount) << " cells unreachable.\n";
        return false;
    }
}
