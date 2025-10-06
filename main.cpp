#include "Maze.h"
#include <iostream>
#include <string>
#include <chrono>
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

