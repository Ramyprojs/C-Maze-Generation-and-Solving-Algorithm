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
    std::cout << "\n" << std::string(50, '=') << "\n";
    std::cout << "        RECURSIVE MAZE GENERATOR\n";
    std::cout << std::string(50, '=') << "\n";
    std::cout << "1. Generate maze (Iterative - Stack-based)\n";
    std::cout << "2. Generate maze (Recursive)\n";
    std::cout << "3. Generate custom size maze\n";
    std::cout << "4. Generate maze with custom seed\n";
    std::cout << "5. Show maze in ASCII format\n";
    std::cout << "6. Show detailed maze information\n";
    std::cout << "7. Solve current maze\n";
    std::cout << "8. Generate multiple mazes comparison\n";
    std::cout << "9. Performance test\n";
    std::cout << "A. Check maze connectivity (debug)\n";
    std::cout << "0. Exit\n";
    std::cout << std::string(50, '=') << "\n";
    std::cout << "Choose an option: ";
}
    // Moaz
    
/**
 * Get integer input with validation
 */
int getIntInput(const std::string& prompt, int min = 0, int max = 1000) {  
    // TODO: Prompt the user and validate numeric input between min and max.
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= min && value <= max) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        } else {
            std::cout << "Invalid input. Please enter a number between " 
                      << min << " and " << max << ".\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
 //Moaaz


/**
 * Generate and display a basic maze
 */
void generateBasicMaze(Maze& maze, bool useRecursive = false) {
    std::cout << "\nGenerating maze using " 
              << (useRecursive ? "recursive" : "iterative") 
              << " algorithm...\n";
    
    auto start = std::chrono::high_resolution_clock::now();
    
    if (useRecursive) {
        maze.generateMazeRecursive();
    } else {
        maze.generateMazeIterative();
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << "Generation completed in " << duration.count() << " microseconds.\n";
    maze.printMaze();
}  //Ramy

/**
 * Generate maze with custom dimensions (now updates a passed-in currentMaze)
 */
void generateCustomMaze(Maze &currentMaze) {
    int width = getIntInput("Enter maze width (3-50): ", 3, 50);
    int height = getIntInput("Enter maze height (3-50): ", 3, 50);

    Maze customMaze(width, height);

    std::cout << "\nChoose algorithm:\n";
    std::cout << "1. Iterative (Stack-based)\n";
    std::cout << "2. Recursive\n";
    int choice = getIntInput("Choice (1-2): ", 1, 2);

    generateBasicMaze(customMaze, choice == 2);

    // Replace the currentMaze with the newly generated maze so option 7
    // (solve current maze) operates on the maze the user just created.
    currentMaze = std::move(customMaze);
}  //Ramy

/**
 * Generate maze with custom seed (now updates a passed-in currentMaze)
 */
void generateSeededMaze(Maze &currentMaze) {
    int width = getIntInput("Enter maze width (3-30): ", 3, 30);
    int height = getIntInput("Enter maze height (3-30): ", 3, 30);
    unsigned int seed = getIntInput("Enter seed value: ", 0, 999999);

    Maze seededMaze(width, height, seed);

    std::cout << "\nChoose algorithm:\n";
    std::cout << "1. Iterative (Stack-based)\n";
    std::cout << "2. Recursive\n";
    int choice = getIntInput("Choice (1-2): ", 1, 2);

    std::cout << "\nUsing seed: " << seed << "\n";
    generateBasicMaze(seededMaze, choice == 2);

    // Make the seeded maze the current maze for subsequent operations
    currentMaze = std::move(seededMaze);
} //Ramy


/**
 * Compare multiple maze generation algorithms
 */
void compareMazes() {
    int width = getIntInput("Enter maze width for comparison (5-20): ", 5, 20);
    int height = getIntInput("Enter maze height for comparison (5-20): ", 5, 20);
    
    std::cout << "\nGenerating mazes for comparison...\n";
    
    // Iterative maze
    Maze iterativeMaze(width, height, 12345);
    std::cout << "\n--- ITERATIVE (STACK-BASED) ALGORITHM ---";
    generateBasicMaze(iterativeMaze, false);
    
    // Recursive maze
    Maze recursiveMaze(width, height, 12345);
    std::cout << "\n--- RECURSIVE ALGORITHM ---";
    generateBasicMaze(recursiveMaze, true);
    
    std::cout << "\nNote: Both mazes use the same seed (12345) for comparison.\n";
}  //Ramy


/**
 * Performance testing
 */
void performanceTest() {
    std::cout << "\nPerformance Test - Maze Generation Times\n";
    std::cout << std::string(45, '-') << "\n";
    
    std::vector<std::pair<int, int>> sizes = {{10, 10}, {20, 20}, {30, 30}, {40, 40}};
    
    for (const auto& size : sizes) {
        int width = size.first;
        int height = size.second;
        
        std::cout << "Testing " << width << "x" << height << " maze:\n";
        
        // Test iterative algorithm
        Maze iterativeMaze(width, height);
        auto start = std::chrono::high_resolution_clock::now();
        iterativeMaze.generateMazeIterative();
        auto end = std::chrono::high_resolution_clock::now();
        auto iterativeTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        
        // Test recursive algorithm
        Maze recursiveMaze(width, height);
        start = std::chrono::high_resolution_clock::now();
        recursiveMaze.generateMazeRecursive();
        end = std::chrono::high_resolution_clock::now();
        auto recursiveTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        
        std::cout << "  Iterative: " << std::setw(8) << iterativeTime.count() << " μs\n";
        std::cout << "  Recursive: " << std::setw(8) << recursiveTime.count() << " μs\n";
        std::cout << "  Difference: " << std::setw(7) << (recursiveTime.count() - iterativeTime.count()) << " μs\n\n";
    }
}  //Ramy

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
    
    Maze maze;
    int choice;
    
    do {
        displayMenu();
        choice = getIntInput("", 1, 8);
        
        switch (choice) {
            case 1:
                currentMaze = Maze(10, 10);
                generateBasicMaze(currentMaze, false);
                break;
                
            case 2:
                currentMaze = Maze(10, 10);
                generateBasicMaze(currentMaze, true);
                break;
                
            case 3:
                generateCustomMaze(currentMaze);
                break;
                
            case 4:
                generateSeededMaze(currentMaze);
                break;
                
            case 5:
                std::cout << "\nASCII representation of current maze:\n";
                currentMaze.printMazeASCII();
                break;
                
            case 6:
                currentMaze.printMazeDetailed();
                break;
                
            case 7:
                solveMazeDemo(currentMaze);
                break;
                
            case 8:
                compareMazes();
                break;
                
            case 9:
                performanceTest();
                break;
                
            case 10:
                std::cout << "\nChecking maze connectivity...\n";
                currentMaze.isMazeConnected();
                break;
                
            case 0:
                std::cout << "\nThank you for using the Recursive Maze Generator!\n";
                std::cout << "Goodbye!\n";
                break;
                
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
}  //Moaz
}

/**
 * Additional utility functions for demonstration
 */
namespace MazeUtils {        
  void sizeDemonstration() {       
      // TODO: Construct several mazes of different sizes and print them.
      std::cout << "\n=== SIZE DEMONSTRATION ===\n";
        std::vector<std::pair<int, int>> sizes = {{5, 5}, {8, 8}, {12, 12}};
        
        for (const auto& size : sizes) {
            Maze demo(size.first, size.second);
            demo.generateMazeIterative();
            std::cout << "\nMaze " << size.first << "x" << size.second << ":\n";
            demo.printMaze();
        }
    }
    }
        // Moaz

   void showComplexityInfo() {
    // TODO: Print algorithm complexity information.
    std::cout << "\n=== Maze Generation Algorithm Complexities ===\n";
    std::cout << "1. Depth-First Search (DFS):\n";
    std::cout << "   - Time: O(n) where n is number of cells\n";
    std::cout << "   - Space: O(n) for recursion stack\n";
    std::cout << "   - Characteristics: Creates long corridors, few dead ends\n\n";
    
    std::cout << "2. Prim's Algorithm:\n";
    std::cout << "   - Time: O(n log n) with binary heap\n";
    std::cout << "   - Space: O(n) for priority queue\n";
    std::cout << "   - Characteristics: More uniform, many short dead ends\n\n";
    
    std::cout << "3. Kruskal's Algorithm:\n";
    std::cout << "   - Time: O(n log n) with union-find\n";
    std::cout << "   - Space: O(n) for disjoint set\n";
    std::cout << "   - Characteristics: Balanced, medium difficulty\n\n";
    
    std::cout << "4. Recursive Division:\n";
    std::cout << "   - Time: O(n log n)\n";
    std::cout << "   - Space: O(log n) for recursion\n";
    std::cout << "   - Characteristics: Perfect maze, rectangular patterns\n";
}
        // Moaz
    }
}

