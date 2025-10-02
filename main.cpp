#include "Maze.h"
#include <iostream>
#include <string>
#include <chrono>
#include <limits>

/*
 * MAIN.CPP TEMPLATE - INTERACTIVE MAZE GENERATOR
 * 
 * This file contains the user interface and demonstration functions
 * for your maze generation project. Follow the TODOs to implement
 * a complete interactive menu system.
 * 
 * LEARNING OBJECTIVES:
 * 1. User input validation and handling
 * 2. Menu-driven program design
 * 3. Performance measurement
 * 4. Code organization and modularity
 * 5. Error handling and edge cases
 */

/**
 * TODO: Implement displayMenu Function
 * 
 * INSTRUCTIONS:
 * Create a function that displays a nice-looking menu with options:
 * 1. Generate maze (Iterative - Stack-based)
 * 2. Generate maze (Recursive)
 * 3. Generate custom size maze
 * 4. Generate maze with custom seed
 * 5. Show maze in ASCII format
 * 6. Show detailed maze information
 * 7. Solve current maze
 * 8. Generate multiple mazes comparison
 * 9. Performance test
 * 0. Exit
 * 
 * TIPS:
 * - Use std::string(50, '=') to create separator lines
 * - Make it visually appealing with proper spacing
 */
// void displayMenu() {
//     // TODO: Print attractive menu header
//     // std::cout << "\n" << std::string(50, '=') << "\n";
//     // std::cout << "        RECURSIVE MAZE GENERATOR\n";
//     // std::cout << std::string(50, '=') << "\n";
//     
//     // TODO: Print all menu options
//     // std::cout << "1. Generate maze (Iterative - Stack-based)\n";
//     // ... add other options
//     
//     // TODO: Print prompt
//     // std::cout << "Choose an option: ";
// }

/**
 * TODO: Implement getIntInput Function
 * 
 * INSTRUCTIONS:
 * Create a robust input validation function that:
 * 1. Prompts user with given message
 * 2. Validates input is within min/max range
 * 3. Handles invalid input gracefully
 * 4. Clears input buffer after errors
 * 5. Returns valid integer
 * 
 * PARAMETERS:
 * - prompt: Message to show user
 * - min: Minimum valid value (default 0)
 * - max: Maximum valid value (default 1000)
 */
// int getIntInput(const std::string& prompt, int min = 0, int max = 1000) {
//     int value;
//     while (true) {
//         // TODO: Display prompt
//         // std::cout << prompt;
//         
//         // TODO: Try to read input and validate range
//         // if (std::cin >> value && value >= min && value <= max) {
//         //     // TODO: Clear input buffer and return valid value
//         //     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//         //     return value;
//         // } else {
//         //     // TODO: Print error message
//         //     std::cout << "Invalid input. Please enter a number between " 
//         //               << min << " and " << max << ".\n";
//         //     // TODO: Clear error state and input buffer
//         //     std::cin.clear();
//         //     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//         // }
//     }
// }

/**
 * TODO: Implement generateBasicMaze Function
 * 
 * INSTRUCTIONS:
 * Create a function that generates and displays a maze with timing:
 * 1. Print which algorithm is being used
 * 2. Measure generation time using std::chrono
 * 3. Generate maze using specified algorithm
 * 4. Print timing results
 * 5. Display the generated maze
 * 
 * PARAMETERS:
 * - maze: Reference to Maze object to generate
 * - useRecursive: true for recursive, false for iterative
 */
// void generateBasicMaze(Maze& maze, bool useRecursive = false) {
//     // TODO: Print which algorithm is being used
//     // std::cout << "\nGenerating maze using " 
//     //           << (useRecursive ? "recursive" : "iterative") 
//     //           << " algorithm...\n";
//     
//     // TODO: Start timing
//     // auto start = std::chrono::high_resolution_clock::now();
//     
//     // TODO: Generate maze with chosen algorithm
//     // if (useRecursive) {
//     //     maze.generateMazeRecursive();
//     // } else {
//     //     maze.generateMazeIterative();
//     // }
//     
//     // TODO: Stop timing and calculate duration
//     // auto end = std::chrono::high_resolution_clock::now();
//     // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
//     
//     // TODO: Print results
//     // std::cout << "Generation completed in " << duration.count() << " microseconds.\n";
//     // maze.printMaze();
// }

/**
 * TODO: Implement generateCustomMaze Function
 * 
 * INSTRUCTIONS:
 * Create a function that lets users specify custom maze dimensions:
 * 1. Get width and height from user (with validation)
 * 2. Create new Maze object with custom dimensions
 * 3. Let user choose algorithm
 * 4. Generate and display the maze
 */
// void generateCustomMaze() {
//     // TODO: Get dimensions from user
//     // int width = getIntInput("Enter maze width (3-50): ", 3, 50);
//     // int height = getIntInput("Enter maze height (3-50): ", 3, 50);
//     
//     // TODO: Create custom maze
//     // Maze customMaze(width, height);
//     
//     // TODO: Let user choose algorithm
//     // std::cout << "\nChoose algorithm:\n";
//     // std::cout << "1. Iterative (Stack-based)\n";
//     // std::cout << "2. Recursive\n";
//     // int choice = getIntInput("Choice (1-2): ", 1, 2);
//     
//     // TODO: Generate maze
//     // generateBasicMaze(customMaze, choice == 2);
// }

/**
 * TODO: Implement generateSeededMaze Function
 * 
 * INSTRUCTIONS:
 * Create a function for reproducible maze generation:
 * 1. Get dimensions and seed from user
 * 2. Create Maze with custom seed
 * 3. Generate and display maze
 * 4. Show which seed was used
 */
// void generateSeededMaze() {
//     // TODO: Get parameters from user
//     // int width = getIntInput("Enter maze width (3-30): ", 3, 30);
//     // int height = getIntInput("Enter maze height (3-30): ", 3, 30);
//     // unsigned int seed = getIntInput("Enter seed value: ", 0, 999999);
//     
//     // TODO: Create seeded maze
//     // Maze seededMaze(width, height, seed);
//     
//     // TODO: Choose algorithm and generate
//     // TODO: Display seed used
// }

/**
 * TODO: Implement compareMazes Function
 * 
 * INSTRUCTIONS:
 * Create a function that generates two mazes with the same seed
 * to compare iterative vs recursive algorithms:
 * 1. Get dimensions from user
 * 2. Create two identical mazes (same seed)
 * 3. Generate one with iterative, one with recursive
 * 4. Display both with timing information
 */
// void compareMazes() {
//     // TODO: Get dimensions for comparison
//     // int width = getIntInput("Enter maze width for comparison (5-20): ", 5, 20);
//     // int height = getIntInput("Enter maze height for comparison (5-20): ", 5, 20);
//     
//     // TODO: Create two identical mazes
//     // Maze iterativeMaze(width, height, 12345);
//     // Maze recursiveMaze(width, height, 12345);
//     
//     // TODO: Generate both and compare
//     // std::cout << "\n--- ITERATIVE (STACK-BASED) ALGORITHM ---";
//     // generateBasicMaze(iterativeMaze, false);
//     
//     // std::cout << "\n--- RECURSIVE ALGORITHM ---";
//     // generateBasicMaze(recursiveMaze, true);
//     
//     // TODO: Print comparison note
// }

/**
 * TODO: Implement performanceTest Function
 * 
 * INSTRUCTIONS:
 * Create a function that benchmarks both algorithms on different maze sizes:
 * 1. Test multiple maze sizes (e.g., 10x10, 20x20, 30x30, 40x40)
 * 2. Time both algorithms for each size
 * 3. Display results in a nice table format
 * 4. Calculate and show the difference
 */
// void performanceTest() {
//     // TODO: Print test header
//     // std::cout << "\nPerformance Test - Maze Generation Times\n";
//     // std::cout << std::string(45, '-') << "\n";
//     
//     // TODO: Define test sizes
//     // std::vector<std::pair<int, int>> sizes = {{10, 10}, {20, 20}, {30, 30}, {40, 40}};
//     
//     // TODO: Test each size
//     // for (const auto& size : sizes) {
//     //     int width = size.first;
//     //     int height = size.second;
//     //     
//     //     std::cout << "Testing " << width << "x" << height << " maze:\n";
//     //     
//     //     // TODO: Test iterative algorithm
//     //     // TODO: Test recursive algorithm
//     //     // TODO: Display results
//     // }
// }

/**
 * TODO: Implement solveMazeDemo Function
 * 
 * INSTRUCTIONS:
 * Create a function that demonstrates maze solving:
 * 1. Explain what the solver will do
 * 2. Time the solving process
 * 3. Display results
 */
// void solveMazeDemo(Maze& maze) {
//     // TODO: Print demo header
//     // std::cout << "\nMaze Solving Demo\n";
//     // std::cout << "Attempting to solve maze from (0,0) to (" 
//     //           << (maze.getWidth()-1) << "," << (maze.getHeight()-1) << ")...\n";
//     
//     // TODO: Time the solving process
//     // auto start = std::chrono::high_resolution_clock::now();
//     // bool solved = maze.solveMaze();
//     // auto end = std::chrono::high_resolution_clock::now();
//     // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
//     
//     // TODO: Display results
//     // if (solved) {
//     //     std::cout << "Maze solved in " << duration.count() << " microseconds!\n";
//     // } else {
//     //     std::cout << "Maze could not be solved.\n";
//     // }
// }

/**
 * TODO: Implement main Function
 * 
 * INSTRUCTIONS:
 * Create the main program loop that:
 * 1. Displays welcome message
 * 2. Creates a default maze
 * 3. Shows menu and handles user choices
 * 4. Continues until user chooses to exit
 * 5. Handles all menu options
 * 6. Provides "Press Enter to continue" functionality
 */
int main() {
    // TODO: Print welcome message
    // std::cout << "Welcome to the Recursive Maze Generator!\n";
    // std::cout << "This program demonstrates various maze generation algorithms.\n";
    
    // TODO: Create default maze
    // Maze currentMaze(10, 10);
    // currentMaze.generateMazeIterative(); // Generate initial maze
    
    // TODO: Main program loop
    // int choice;
    // do {
    //     displayMenu();
    //     choice = getIntInput("", 0, 9);
    //     
    //     switch (choice) {
    //         case 1:
    //             // TODO: Generate iterative maze
    //             // currentMaze = Maze(10, 10);
    //             // generateBasicMaze(currentMaze, false);
    //             break;
    //             
    //         case 2:
    //             // TODO: Generate recursive maze
    //             // currentMaze = Maze(10, 10);
    //             // generateBasicMaze(currentMaze, true);
    //             break;
    //             
    //         case 3:
    //             // TODO: Generate custom maze
    //             // generateCustomMaze();
    //             break;
    //             
    //         case 4:
    //             // TODO: Generate seeded maze
    //             // generateSeededMaze();
    //             break;
    //             
    //         case 5:
    //             // TODO: Show ASCII maze
    //             // std::cout << "\nASCII representation of current maze:\n";
    //             // currentMaze.printMazeASCII();
    //             break;
    //             
    //         case 6:
    //             // TODO: Show detailed info
    //             // currentMaze.printMazeDetailed();
    //             break;
    //             
    //         case 7:
    //             // TODO: Solve maze
    //             // solveMazeDemo(currentMaze);
    //             break;
    //             
    //         case 8:
    //             // TODO: Compare mazes
    //             // compareMazes();
    //             break;
    //             
    //         case 9:
    //             // TODO: Performance test
    //             // performanceTest();
    //             break;
    //             
    //         case 0:
    //             // TODO: Exit message
    //             // std::cout << "\nThank you for using the Recursive Maze Generator!\n";
    //             // std::cout << "Goodbye!\n";
    //             break;
    //             
    //         default:
    //             // TODO: Invalid option
    //             // std::cout << "Invalid option. Please try again.\n";
    //     }
    //     
    //     // TODO: Press Enter to continue (except for exit)
    //     // if (choice != 0) {
    //     //     std::cout << "\nPress Enter to continue...";
    //     //     std::cin.get();
    //     // }
    //     
    // } while (choice != 0);
    
    // TODO: For now, just print a placeholder message
    std::cout << "Welcome to the Maze Generator Template!\n";
    std::cout << "Please implement the functions above to create your maze generator.\n";
    std::cout << "\nStart by implementing:\n";
    std::cout << "1. The Cell struct in Maze.h\n";
    std::cout << "2. The Direction enum in Maze.h\n";
    std::cout << "3. The Maze class constructors in Maze.cpp\n";
    std::cout << "4. The helper methods in Maze.cpp\n";
    std::cout << "5. The generation algorithms in Maze.cpp\n";
    std::cout << "6. The display methods in Maze.cpp\n";
    std::cout << "7. The main program functions above\n";
    
    return 0;
}

/*
 * IMPLEMENTATION STRATEGY:
 * 
 * 1. START WITH BASICS:
 *    - Implement displayMenu() and getIntInput() first
 *    - Test the menu system without maze functionality
 * 
 * 2. ADD MAZE FUNCTIONALITY:
 *    - Implement basic maze generation and display
 *    - Test with small mazes first
 * 
 * 3. ADD FEATURES INCREMENTALLY:
 *    - Add custom sizing
 *    - Add seeded generation
 *    - Add performance testing
 *    - Add maze solving
 * 
 * 4. POLISH AND REFINE:
 *    - Improve error handling
 *    - Add more visualization options
 *    - Optimize performance
 * 
 * TESTING TIPS:
 * 
 * 1. Test input validation thoroughly
 * 2. Try edge cases (very small/large mazes)
 * 3. Test with different seeds
 * 4. Verify that both algorithms produce valid mazes
 * 5. Check memory usage with large mazes
 * 
 * ENHANCEMENT IDEAS:
 * 
 * 1. Add save/load maze functionality
 * 2. Add different maze generation algorithms
 * 3. Add graphical output (if libraries available)
 * 4. Add maze difficulty analysis
 * 5. Add multi-threaded generation for large mazes
 */

