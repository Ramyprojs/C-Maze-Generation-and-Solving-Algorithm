#include "Maze.h"
#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <limits>

/**
 * Display the main menu
 */
void displayMenu() {
    // TODO: Print the menu options to stdout (copy from the real project)
    // Moaz
}

/**
 * Get integer input with validation
 */
int getIntInput(const std::string& prompt, int min = 0, int max = 1000) {
    // TODO: Prompt the user and validate numeric input between min and max.
    // Placeholder: return min as a safe default for compilation and tests.
    (void)prompt; (void)min; (void)max;
    // Moaz
    return min;
}

/**
 * Generate and display a basic maze
 */
void generateBasicMaze(Maze& maze, bool useRecursive = false) {
    // TODO: Measure timing, call maze.generateMazeIterative() or
    // maze.generateMazeRecursive(), then print results with maze.printMaze().
    (void)maze; (void)useRecursive;
    // Ramy
}

/**
 * Generate maze with custom dimensions (now updates a passed-in currentMaze)
 */
void generateCustomMaze(Maze &currentMaze) {
    // TODO: Ask user for width & height, construct a Maze, generate it,
    // and assign it into currentMaze so the rest of the program uses it.
    (void)currentMaze;
    // Ramy
}

/**
 * Generate maze with custom seed (now updates a passed-in currentMaze)
 */
void generateSeededMaze(Maze &currentMaze) {
    // TODO: Ask user for width/height/seed, create Maze(w,h,seed),
    // generate it, and assign to currentMaze.
    (void)currentMaze;
    // Ramy
}

/**
 * Compare multiple maze generation algorithms
 */
void compareMazes() {
    // TODO: Generate mazes of different sizes and print timings.
    // Ramy
}

/**
 * Performance testing
 */
void performanceTest() {
    // TODO: Benchmark generateMazeIterative() and generateMazeRecursive().
    // Ramy
}

/**
 * Demonstrate maze solving
 */
void solveMazeDemo(Maze& maze) {
    std::cout << "\n🎯 MAZE SOLVING DEMONSTRATION\n";
    std::cout << std::string(50, '=') << "\n";

    // Validate maze
    if (maze.getWidth() <= 0 || maze.getHeight() <= 0) {
        std::cout << "❌ Error: No valid maze to solve. Generate a maze first.\n";
        return;
    }

    const int width = maze.getWidth();
    const int height = maze.getHeight();

    std::cout << "Maze: " << width << "x" << height << " (" << (width * height) << " cells)\n";

    // Check connectivity with timing
    std::cout << "\nChecking maze connectivity...\n";
    auto start = std::chrono::high_resolution_clock::now();
    maze.isMazeConnected();  // This function prints its own results
    auto end = std::chrono::high_resolution_clock::now();
    auto connectTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Connectivity check completed in " << connectTime.count() << " μs\n";

    // Show original maze
    std::cout << "\nOriginal maze:\n";
    maze.printMazeASCII();

    // Test multiple solving scenarios
    struct TestCase {
        int sx, sy, ex, ey;
        const char* name;
    };

    std::vector<TestCase> tests = {
        {0, 0, width-1, height-1, "Corner to corner"},
        {0, height-1, width-1, 0, "Reverse diagonal"}
    };

    // Add center test only if maze is big enough
    if (width > 2 && height > 2) {
        tests.push_back({width/2, height/2, 0, 0, "Center to origin"});
    }

    std::cout << "\nTesting " << tests.size() << " solving scenarios:\n";
    std::cout << std::string(50, '-') << "\n";

    int solved = 0;
    std::vector<long long> times;

    for (const auto& test : tests) {
        // Skip invalid positions
        if (test.sx >= width || test.sy >= height || test.ex >= width || test.ey >= height) {
            continue;
        }

        std::cout << "\n" << test.name << ": (" << test.sx << "," << test.sy
                  << ") → (" << test.ex << "," << test.ey << ")\n";

        // Time the solve
        start = std::chrono::high_resolution_clock::now();
        bool success = maze.solveMaze(test.sx, test.sy, test.ex, test.ey);
        end = std::chrono::high_resolution_clock::now();
        auto solveTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        times.push_back(solveTime.count());

        if (success) {
            solved++;
            // Count path length
            int pathLen = 0;
            const auto& grid = maze.getGrid();
            for (int y = 0; y < height; ++y) {
                for (int x = 0; x < width; ++x) {
                    if (grid[y][x].onPath) pathLen++;
                }
            }
            std::cout << "✅ Solved in " << solveTime.count() << " μs (path: " << pathLen << " cells)\n";

            // Show first solution
            if (solved == 1) {
                std::cout << "\nSolution visualization:\n";
                maze.printSolution();
            }
        } else {
            std::cout << "❌ No path found (" << solveTime.count() << " μs)\n";
        }
    }

    // Performance summary
    std::cout << "\n" << std::string(50, '=') << "\n";
    std::cout << "RESULTS SUMMARY:\n";
    std::cout << "• Solutions found: " << solved << "/" << tests.size() << "\n";

    // FIX: Explicit std:: namespace and proper algorithm usage
    if (!times.empty()) {
        // Use explicit iterators and std:: namespace
        auto times_begin = times.begin();
        auto times_end = times.end();

        auto minTime = *std::min_element(times_begin, times_end);
        auto maxTime = *std::max_element(times_begin, times_end);

        // Use proper accumulate with explicit types
        long long sum = std::accumulate(times_begin, times_end, 0LL);
        auto avgTime = sum / static_cast<long long>(times.size());

        std::cout << "• Fastest solve: " << minTime << " μs\n";
        std::cout << "• Slowest solve: " << maxTime << " μs\n";
        std::cout << "• Average time: " << avgTime << " μs\n";
        std::cout << "• Algorithm: BFS (optimal shortest path)\n";
    }

    // FIX: Proper size comparison
    if (solved == static_cast<int>(tests.size())) {
        std::cout << "🎉 All test cases passed! Maze is fully connected.\n";
    } else if (solved > 0) {
        std::cout << "⚠️  Some paths not found - normal for complex mazes.\n";
    } else {
        std::cout << "❌ No solutions found - check maze connectivity.\n";
    }

    std::cout << std::string(50, '=') << "\n";
    // Youssef
}

/**
 * Main program loop (skeleton)
 */
int main() {
    // TODO: Implement full interactive loop. This skeleton just demonstrates
    // how the real main is structured. Replace with real logic when
    // implementing tests.
    std::cout << "test_maze skeleton main (no-op).\n";
    // Moaz
    return 0;
}

/**
 * Additional utility functions for demonstration
 */
namespace MazeUtils {
    void sizeDemonstration() {
        // TODO: Construct several mazes of different sizes and print them.
        // Moaz
    }

    void showComplexityInfo() {
        // TODO: Print algorithm complexity information.
        // Moaz
    }
}

