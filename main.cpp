#include "Maze.h"
#include <iostream>
#include <string>
#include <chrono>
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
}

/**
 * Get integer input with validation
 */
int getIntInput(const std::string& prompt, int min = 0, int max = 1000) {
    // TODO: Prompt the user and validate numeric input between min and max.
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            if (value >= min && value <= max) {
                break;
            } else {
                std::cout << "Please enter a value between " << min << " and " << max << ".\n";
            }
        } else {
            std::cout << "Invalid input. Please enter a valid number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return value;
} //Moaaz
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
    // TODO: Attempt to solve the provided maze and print timings/results.
    (void)maze;
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
                // Generate random maze
                std::cout << "Generating random maze...\n";
                break;
            case 2:
                // Generate maze with seed
                {
                    unsigned int seed = getIntInput("Enter seed value: ", 0, 1000000);
                    std::cout << "Generating maze with seed " << seed << "...\n";
                }
                break;
            case 3:
                // Set dimensions
                {
                    int width = getIntInput("Enter width: ", 5, 50);
                    int height = getIntInput("Enter height: ", 5, 50);
                    std::cout << "Setting dimensions to " << width << "x" << height << "...\n";
                }
                break;
            case 4:
                // Display maze
                std::cout << "Displaying current maze...\n";
                break;
            case 5:
                // Solve maze
                std::cout << "Solving maze...\n";
                break;
            case 6:
                // Save maze
                std::cout << "Saving maze to file...\n";
                break;
            case 7:
                // Load maze
                std::cout << "Loading maze from file...\n";
                break;
            case 8:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 8);
    
    return 0;
}  //Moaz
}

/**
 * Additional utility functions for demonstration
 */
namespace MazeUtils {
    void sizeDemonstration() {
        // TODO: Construct several mazes of different sizes and print them.
        std::cout << "\n=== Maze Size Demonstration ===\n";
        
        // Create mazes of different sizes
        Maze smallMaze(5, 5);
        Maze mediumMaze(10, 10);
        Maze largeMaze(15, 20);
        Maze customMaze(8, 12, 12345); // With fixed seed
        
        std::cout << "Created mazes with sizes:\n";
        std::cout << "- Small: 5x5\n";
        std::cout << "- Medium: 10x10\n";
        std::cout << "- Large: 15x20\n";
        std::cout << "- Custom: 8x12 (with seed 12345)\n";
        
        // Placeholder for actual maze printing
        std::cout << "Maze display functionality to be implemented...\n";
    }
}
        // Moaz
    }

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

