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

