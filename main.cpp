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

/**
 * Get integer input with validation
 */
int getIntInput(const std::string& prompt, int min = 0, int max = 1000) {
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
}

/**
 * Generate maze with custom dimensions
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
}

/**
 * Generate maze with custom seed
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
}

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
}

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
}

/**
 * Demonstrate maze solving
 */
void solveMazeDemo(Maze& maze) {
    std::cout << "\nMaze Solving Demo\n";
    std::cout << "Attempting to solve maze from (0,0) to (" 
              << (maze.getWidth()-1) << "," << (maze.getHeight()-1) << ")...\n";
    
    auto start = std::chrono::high_resolution_clock::now();
    bool solved = maze.solveMaze();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    if (solved) {
        std::cout << "Maze solved in " << duration.count() << " microseconds!\n";
    } else {
        std::cout << "Maze could not be solved.\n";
    }
}

/**
 * Main program loop
 */
int main() {
    std::cout << "Welcome to the Recursive Maze Generator!\n";
    std::cout << "This program demonstrates various maze generation algorithms.\n";
    
    // Default maze
    Maze currentMaze(10, 10);
    currentMaze.generateMazeIterative(); // Generate initial maze
    
    int choice;
    do {
        displayMenu();
        std::string input;
        std::cin >> input;
        
        // Handle both numeric and letter input
        if (input == "A" || input == "a") {
            choice = 10; // Use 10 for connectivity check
        } else {
            try {
                choice = std::stoi(input);
            } catch (...) {
                choice = -1; // Invalid input
            }
        }
        
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
        
        if (choice != 0) {
            std::cout << "\nPress Enter to continue...";
            // Clear any leftover input (e.g., newline from previous >> reads)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
        }
        
    } while (choice != 0);
    
    return 0;
}

/**
 * Additional utility functions for demonstration
 */
namespace MazeUtils {
    /**
     * Create a demo showcasing different maze sizes
     */
    void sizeDemonstration() {
        std::cout << "\n=== SIZE DEMONSTRATION ===\n";
        
        std::vector<std::pair<int, int>> sizes = {{5, 5}, {8, 8}, {12, 12}};
        
        for (const auto& size : sizes) {
            Maze demo(size.first, size.second);
            demo.generateMazeIterative();
            std::cout << "\nMaze " << size.first << "x" << size.second << ":\n";
            demo.printMaze();
        }
    }
    
    /**
     * Show algorithm complexity information
     */
    void showComplexityInfo() {
        std::cout << "\n=== ALGORITHM COMPLEXITY ===\n";
        std::cout << "Iterative Depth-First Search (Stack-based):\n";
        std::cout << "  Time Complexity: O(n)\n";
        std::cout << "  Space Complexity: O(n)\n";
        std::cout << "  Where n = width × height\n\n";
        
        std::cout << "Recursive Depth-First Search:\n";
        std::cout << "  Time Complexity: O(n)\n";
        std::cout << "  Space Complexity: O(n) - due to recursion stack\n";
        std::cout << "  Where n = width × height\n\n";
        
        std::cout << "Both algorithms ensure:\n";
        std::cout << "  - Every cell is visitable\n";
        std::cout << "  - Only one path between any two cells\n";
        std::cout << "  - Perfect maze generation (no loops)\n";
    }
}
