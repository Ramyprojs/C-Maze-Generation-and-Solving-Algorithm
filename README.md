C++ Maze Generation and Solving Algorithm
A comprehensive C++ implementation of maze generation algorithms, featuring both recursive and iterative depth-first search (DFS) approaches. This project creates intricate, perfect mazes and includes a built-in solver.

🎯 Project Overview
This program generates perfect mazes (mazes with no loops and a single solution path between any two points). It serves as a practical demonstration of graph traversal algorithms, data structures, and object-oriented design in C++.

Algorithms Implemented

Iterative Depth-First Search (DFS): Uses an explicit stack (std::stack) for efficient, non-recursive generation, which is ideal for very large mazes.

Recursive Depth-First Search (Backtracking): A classic, elegant implementation that uses the call stack to manage its state.

🚀 Key Features
Dual Generation Algorithms: Switch between iterative and recursive methods.

Customizable Mazes: Specify width, height, and a random seed for reproducible results.

Built-in Maze Solver: Finds and displays the solution path from start to finish.

Multiple Display Formats: View the maze using clean Unicode box characters or standard ASCII.

Performance Benchmarking: Compare the generation speeds of the iterative vs. recursive algorithms.

Interactive CLI: A user-friendly command-line menu to access all features.

🛠️ Getting Started
Prerequisites

A C++17 compatible compiler (like GCC or Clang).

make for easy compilation.

Compilation and Execution

Clone the repository:

git clone [https://github.com/YOUR_USERNAME/cpp-maze-generator.git](https://github.com/YOUR_USERNAME/cpp-maze-generator.git)
cd cpp-maze-generator

Compile the project using the included Makefile:

make

Run the program to open the interactive menu:

make run

Alternatively, you can run the executable directly:

./bin/maze_generator

📚 Usage
Once running, the program presents a menu with several options:

Generate Mazes: Create default or custom-sized mazes with either algorithm.

Solve Maze: Find the path through the currently generated maze.

Performance Test: See a speed comparison for generating mazes of different sizes.

Change View: Toggle between detailed Unicode and simple ASCII output.

🏗️ Project Structure
.
├── Makefile          # Handles all build and run commands
├── Maze.h            # Header file for the Maze class
├── Maze.cpp          # Implementation of the Maze class and algorithms
├── main.cpp          # Main program driver with the user interface
└── README.md         # This documentation file

