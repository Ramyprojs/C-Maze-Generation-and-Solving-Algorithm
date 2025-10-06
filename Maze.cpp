#include "Maze.h"
#include <algorithm>
#include <chrono>
#include <queue>


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
    // Validate dimensions first (reuse the same defensive checks as printMazeASCII)
    if (width <= 0 || height <= 0) {
        std::cout << "Invalid maze dimensions (width/height <= 0).\n";
        return;
    }

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

    // Compute basic statistics
    const int totalCells = width * height;

    // Count unique walls. Each cell stores 4 wall flags; however many walls
    // (internal ones) are duplicated between two adjacent cells. To count
    // each physical wall exactly once we use the following strategy:
    //  - For every cell count its RIGHT and BOTTOM walls (these cover all
    //    internal vertical/horizontal walls once and also count boundary
    //    walls on the right/bottom edges).
    //  - Additionally count TOP walls for the first row and LEFT walls for
    //    the first column to account for the top/left outer boundaries.
    // This ensures each unique wall is counted exactly once.
    int wallCount = 0;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            const Cell &cell = grid[y][x];
            if (cell.walls[RIGHT]) ++wallCount;   // count right edge (internal or external)
            if (cell.walls[BOTTOM]) ++wallCount;  // count bottom edge (internal or external)

            // For the top row, the top wall hasn't been counted yet (no cell above)
            if (y == 0 && cell.walls[TOP]) ++wallCount;
            // For the leftmost column, the left wall hasn't been counted yet (no cell to the left)
            if (x == 0 && cell.walls[LEFT]) ++wallCount;
        }
    }

    // Print the detailed header information
    std::cout << "Maze details:\n";
    std::cout << "  Dimensions: " << width << " x " << height << "\n";
    std::cout << "  Total cells: " << totalCells << "\n";
    std::cout << "  Unique wall count: " << wallCount << "\n";
    if (totalCells > 0) {
        std::cout << "  Average walls per cell (unique walls / cells): "
                  << static_cast<double>(wallCount) / static_cast<double>(totalCells)
                  << "\n";
    }

    // Try to print a pretty/unicode representation first. The method
    // printMaze() is expected to provide a nicer rendering; it may be
    // unimplemented in the skeleton, so we follow with the robust ASCII
    // renderer printMazeASCII() to guarantee usable output.
    std::cout << "\nRendering maze (pretty printer then ASCII fallback):\n";
    printMaze();       // preferred pretty Unicode rendering (may be a no-op in skeleton)
    printMazeASCII();  // reliable ASCII rendering implemented earlier

    // Youssef
}

void Maze::resetMaze() {
    // Clear any backtracking stack state so generation starts fresh.
    while (!cellStack.empty()) cellStack.pop();

    // If dimensions are invalid, clear the grid and return early.
    if (width <= 0 || height <= 0) {
        grid.clear();
        return;
    }

    // Ensure grid has the correct shape [height][width]. If it's the wrong
    // size we'll resize and default-construct Cells as necessary.
    if (static_cast<int>(grid.size()) != height) {
        grid.assign(height, std::vector<Cell>(width));
    }
    for (int y = 0; y < height; ++y) {
        if (static_cast<int>(grid[y].size()) != width) {
            grid[y].assign(width, Cell());
        }

        for (int x = 0; x < width; ++x) {
            Cell &c = grid[y][x];
            // Reset visitation flag used by generation algorithms
            c.visited = false;

            // Set all four walls to present. walls[] ordering follows the
            // enum Direction: TOP=0, RIGHT=1, BOTTOM=2, LEFT=3
            for (int i = 0; i < 4; ++i) c.walls[i] = true;

            // Ensure coordinates are accurate for helpers that rely on them
            c.x = x;
            c.y = y;
        }
    }
    //Youssef
}


bool Maze::solveMaze(int startX, int startY, int endX, int endY) {
    // Clear any previous solution path
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x].onPath = false;
        }
    }

    // Defensive checks
    if (width <= 0 || height <= 0) {
        std::cout << "Invalid maze dimensions.\n";
        return false;
    }
    if (startX < 0 || startX >= width || startY < 0 || startY >= height) {
        std::cout << "Invalid start position (" << startX << "," << startY << ").\n";
        return false;
    }
    if (endX < 0 || endX >= width || endY < 0 || endY >= height) {
        std::cout << "Invalid end position (" << endX << "," << endY << ").\n";
        return false;
    }

    // Direction vectors: TOP, RIGHT, BOTTOM, LEFT
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {-1, 0, 1, 0};

    // Local visited grid (separate from generation visited flags)
    std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));

    // Parent map for backtracking path
    std::vector<std::vector<std::pair<int, int>>> parent(height,
        std::vector<std::pair<int, int>>(width, {-1, -1}));

    // BFS queue
    std::queue<std::pair<int, int>> q;
    q.push({startX, startY});
    visited[startY][startX] = true;

    bool pathFound = false;

    // BFS to find shortest path
    while (!q.empty() && !pathFound) {
        auto [x, y] = q.front();
        q.pop();

        // Check if we've reached the destination
        if (x == endX && y == endY) {
            pathFound = true;
            break;
        }

        // Explore all four directions
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // Skip out-of-bounds positions
            if (nx < 0 || nx >= width || ny < 0 || ny >= height)
                continue;

            // Skip if there's a wall blocking movement
            if (grid[y][x].walls[dir]) continue;

            // Double-check the opposite wall for consistency
            int opposite = (dir + 2) % 4;
            if (grid[ny][nx].walls[opposite]) continue;

            // Skip already visited cells
            if (visited[ny][nx]) continue;

            // Mark as visited and add to queue
            visited[ny][nx] = true;
            parent[ny][nx] = {x, y};
            q.push({nx, ny});
        }
    }

    if (!pathFound) {
        std::cout << "No path found from (" << startX << "," << startY
                  << ") to (" << endX << "," << endY << ").\n";
        return false;
    }

    // Reconstruct and mark the path
    std::vector<std::pair<int, int>> solutionPath;
    int cx = endX, cy = endY;

    while (cx != -1 && cy != -1) {
        solutionPath.push_back({cx, cy});
        grid[cy][cx].onPath = true;  // *** FIX: Actually mark the path ***

        auto [px, py] = parent[cy][cx];
        cx = px;
        cy = py;
    }

    // Reverse to get path from start to end
    std::reverse(solutionPath.begin(), solutionPath.end());

    // Enhanced output with path information
    std::cout << "✅ Path found! Length: " << solutionPath.size() << " steps\n";
    std::cout << "Path: ";
    for (size_t i = 0; i < solutionPath.size(); ++i) {
        auto [x, y] = solutionPath[i];
        std::cout << "(" << x << "," << y << ")";
        if (i < solutionPath.size() - 1) std::cout << " → ";
    }
    std::cout << "\n";

    return true;
}

void Maze::printSolution() const {
    if (width <= 0 || height <= 0 || grid.empty()) {
        std::cout << "Invalid maze dimensions or uninitialized grid.\n";
        return;
    }

    // Check if there's actually a solution to display
    bool hasSolution = false;
    for (int y = 0; y < height && !hasSolution; ++y) {
        for (int x = 0; x < width && !hasSolution; ++x) {
            if (grid[y][x].onPath) hasSolution = true;
        }
    }

    if (!hasSolution) {
        std::cout << "No solution path to display. Run solveMaze() first.\n";
        return;
    }

    const int rows = height * 2 + 1;
    const int cols = width * 2 + 1;
    std::vector<std::string> canvas(rows, std::string(cols, '#'));

    auto setCanvas = [&](int r, int c, char ch) {
        if (r >= 0 && r < rows && c >= 0 && c < cols)
            canvas[r][c] = ch;
    };

    // Draw maze with solution path
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            const Cell &cell = grid[y][x];
            int cr = 2 * y + 1;
            int cc = 2 * x + 1;

            // Mark cell interior (solution path or empty space)
            char cellChar = cell.onPath ? '●' : ' ';  // Use filled circle for path
            setCanvas(cr, cc, cellChar);

            // Mark passages (solution extends through passages)
            if (!cell.walls[TOP]) {
                char passageChar = cell.onPath ? '●' : ' ';
                setCanvas(cr - 1, cc, passageChar);
            }
            if (!cell.walls[BOTTOM]) {
                char passageChar = cell.onPath ? '●' : ' ';
                setCanvas(cr + 1, cc, passageChar);
            }
            if (!cell.walls[LEFT]) {
                char passageChar = cell.onPath ? '●' : ' ';
                setCanvas(cr, cc - 1, passageChar);
            }
            if (!cell.walls[RIGHT]) {
                char passageChar = cell.onPath ? '●' : ' ';
                setCanvas(cr, cc + 1, passageChar);
            }
        }
    }

    // Create entrance and exit
    setCanvas(0, 1, ' ');
    setCanvas(rows - 1, cols - 2, ' ');

    // Display the solution
    std::cout << "\n🎯 MAZE SOLUTION (" << width << "x" << height << ") 🎯\n";
    std::cout << "Legend: # = wall, ● = solution path, space = open\n\n";

    for (const auto &line : canvas) {
        std::cout << line << '\n';
    }
    std::cout << "\n";
}


// Debug and validation
bool Maze::isMazeConnected() {
    // Defensive checks
    if (width <= 0 || height <= 0 || grid.empty()) {
        std::cout << "Invalid maze dimensions or uninitialized grid.\n";
        return false;
    }

    // Total number of cells expected to be reachable
    const int totalCells = width * height;

    // Local visited tracker (don’t use Cell.visited so it doesn’t interfere with other algorithms)
    std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));

    // Directions: TOP, RIGHT, BOTTOM, LEFT
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {-1, 0, 1, 0};

    // Start BFS from (0,0)
    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    int reachableCount = 1;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // Explore 4 neighbors
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // Skip out-of-bounds
            if (nx < 0 || ny < 0 || nx >= width || ny >= height)
                continue;

            // Skip if wall blocks movement in that direction
            if (grid[y][x].walls[dir])
                continue;

            // Skip already visited
            if (visited[ny][nx])
                continue;

            // Otherwise, mark and push
            visited[ny][nx] = true;
            q.push({nx, ny});
            ++reachableCount;
        }
    }

    // Maze is connected if we reached every cell
    bool connected = (reachableCount == totalCells);

    // Optional: print debug info
    std::cout << "Reachable cells: " << reachableCount
              << " / " << totalCells
              << " -> Maze " << (connected ? "is connected ✅" : "has disconnected regions ❌")
              << "\n";

    return connected;

    //Youssef
}

