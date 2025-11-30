# Recursive Maze Generation Algorithm

A comprehensive C++ implementation of recursive maze generation algorithms featuring both iterative and recursive approaches with stack-based data structures for efficient maze generation.

## 🎯 Project Overview

This project implements a sophisticated maze generation system that creates intricate and challenging mazes using two primary algorithms:

1. **Iterative Depth-First Search** - Stack-based implementation
2. **Recursive Depth-First Search** - Classic recursive approach

Both algorithms ensure perfect maze generation with exactly one path between any two cells.

## 🚀 Features

- **Multiple Generation Algorithms**: Choose between iterative and recursive implementations
- **Customizable Maze Dimensions**: Generate mazes from 3x3 to 50x50 cells
- **Seeded Generation**: Reproducible mazes using custom seeds
- **Multiple Visualization Formats**: Unicode box drawing and ASCII representations
- **Performance Testing**: Built-in benchmarking for algorithm comparison
- **Maze Solving**: Bonus feature with path-finding capabilities
- **Interactive Menu System**: User-friendly command-line interface

## 📋 Requirements

- **C++ Compiler**: GCC 7.0+ or Clang 6.0+ (C++17 support required)
- **Operating System**: Linux, macOS, or Windows (with appropriate compiler)
- **Memory**: Minimal requirements (scales with maze size)

### Optional Tools
- `valgrind` - For memory leak detection
- `cppcheck` - For static code analysis
- `clang-format` - For code formatting

## 🛠️ Installation & Compilation

### Quick Start

```bash
# Clone or download the project files
# Navigate to the project directory
cd Maze

# Compile using make
make

# Run the program
make run
```

### Manual Compilation

```bash
g++ -std=c++17 -Wall -Wextra -O2 main.cpp Maze.cpp -o maze_generator
./maze_generator
```

### Available Make Targets

```bash
make all        # Build the project (default)
make debug      # Build with debug information
make release    # Build with full optimization
make run        # Build and run the program
make clean      # Remove build artifacts
make help       # Show all available targets
```

## 📚 Usage

### Interactive Menu

Run the program and choose from the following options:

1. **Generate maze (Iterative)** - Stack-based depth-first search
2. **Generate maze (Recursive)** - Classic recursive implementation
3. **Generate custom size maze** - Specify dimensions
4. **Generate maze with custom seed** - Reproducible results
5. **Show maze in ASCII format** - Alternative visualization
6. **Show detailed maze information** - Statistics and analysis
7. **Solve current maze** - Pathfinding demonstration
8. **Generate multiple mazes comparison** - Side-by-side algorithm comparison
9. **Performance test** - Benchmark different maze sizes

### Example Output

```
=== MAZE (10x10) ===
┌──┬──┬──┬──┬──┬──┬──┬──┬──┬──┐
│     │           │        │
├──┼  ├──┬──┬──┼  ├──┬──┼  │
│     │        │     │     │
├  ┬──┤  ┌──┬──┴──┬──┤  ┌──┤
│  │     │        │     │  │
└──┴──┴──┴──┴──┴──┴──┴──┴──┘
```

## 🧩 Algorithm Details

### Iterative Depth-First Search (Stack-Based)

```cpp
void generateMazeIterative() {
    // Initialize with starting cell
    Cell* currentCell = getCell(0, 0);
    currentCell->visited = true;
    cellStack.push(currentCell);
    
    while (!cellStack.empty()) {
        currentCell = cellStack.top();
        
        // Get unvisited neighbors
        std::vector<Cell*> neighbors = getUnvisitedNeighbors(currentCell);
        
        if (!neighbors.empty()) {
            // Choose random neighbor and carve path
            Cell* chosenNeighbor = neighbors[random_index];
            removeWall(currentCell, chosenNeighbor);
            chosenNeighbor->visited = true;
            cellStack.push(chosenNeighbor);
        } else {
            // Backtrack
            cellStack.pop();
        }
    }
}
```

### Recursive Depth-First Search

```cpp
void generateMazeRecursive(int x, int y) {
    Cell* currentCell = getCell(x, y);
    currentCell->visited = true;
    
    // Get and shuffle neighbors for randomness
    std::vector<Cell*> neighbors = getUnvisitedNeighbors(currentCell);
    std::shuffle(neighbors.begin(), neighbors.end(), rng);
    
    // Recursively visit unvisited neighbors
    for (Cell* neighbor : neighbors) {
        if (!neighbor->visited) {
            removeWall(currentCell, neighbor);
            generateMazeRecursive(neighbor->x, neighbor->y);
        }
    }
}
```

## 📊 Performance Analysis

### Time Complexity
- **Both algorithms**: O(n) where n = width × height
- **Space Complexity**: O(n) for grid storage + O(n) for stack/recursion

### Benchmark Results (Example)
```
Testing 10x10 maze:
  Iterative:      156 μs
  Recursive:      203 μs
  Difference:      47 μs

Testing 30x30 maze:
  Iterative:     2840 μs
  Recursive:     3120 μs
  Difference:     280 μs
```

## 🏗️ Project Structure

```
Maze/
├── Maze.h              # Header file with class definitions
├── Maze.cpp            # Implementation of maze algorithms
├── main.cpp            # Main program with user interface
├── Makefile            # Build system configuration
├── README.md           # This documentation
├── bin/                # Compiled executables (created by make)
└── obj/                # Object files (created by make)
```

## 🔧 Code Architecture

### Core Classes

- **`Cell`**: Represents individual maze cells with wall and visit information
- **`Maze`**: Main class containing generation algorithms and utilities
- **`Direction`**: Enumeration for navigation (TOP, RIGHT, BOTTOM, LEFT)

### Key Methods

- `generateMazeIterative()`: Stack-based maze generation
- `generateMazeRecursive()`: Recursive maze generation
- `printMaze()`: Unicode box drawing visualization
- `printMazeASCII()`: ASCII character visualization
- `solveMaze()`: Pathfinding algorithm

## 🎨 Customization

### Creating Custom Mazes

```cpp
// Create a 15x20 maze with specific seed
Maze customMaze(15, 20, 12345);

// Generate using recursive algorithm
customMaze.generateMazeRecursive();

// Display the result
customMaze.printMaze();
```

### Modifying Generation Parameters

The maze generation can be customized by:
- Adjusting maze dimensions (minimum 3x3, maximum limited by memory)
- Using different random seeds for reproducible results
- Modifying the random number generator for different distributions

## 🐛 Troubleshooting

### Common Issues

1. **Compilation Errors**
   ```bash
   # Ensure C++17 support
   g++ --version
   # Update compiler if needed
   ```

2. **Stack Overflow (Large Recursive Mazes)**
   ```bash
   # Use iterative algorithm for large mazes
   # Or increase stack size: ulimit -s unlimited
   ```

3. **Memory Issues**
   ```bash
   # Check memory usage
   make memcheck
   ```

### Performance Tips

- Use iterative algorithm for larger mazes (>40x40)
- Compile with `-O2` or `-O3` for better performance
- Consider maze dimensions vs. available memory

## 🔮 Future Enhancements

- [ ] Additional maze generation algorithms (Kruskal's, Prim's)
- [ ] Graphical user interface (GUI) version
- [ ] Maze export to image formats
- [ ] Advanced solving algorithms (A*, Dijkstra)
- [ ] 3D maze generation
- [ ] Multi-threaded generation for large mazes

## 📝 License

This project is open source and available under the MIT License.

## 🤝 Contributing

Contributions are welcome! Please feel free to submit pull requests or open issues for:
- Bug fixes
- Performance improvements
- Additional algorithms
- Documentation improvements

## 📞 Support

For questions or issues:
1. Check the troubleshooting section
2. Review the code comments for implementation details
3. Test with different maze sizes and parameters

## 🎓 Educational Value

This project demonstrates:
- **Data Structures**: Stacks, 2D arrays, vectors
- **Algorithms**: Depth-first search, backtracking
- **Design Patterns**: Object-oriented programming principles
- **Performance Analysis**: Algorithm comparison and benchmarking
- **C++ Features**: Modern C++17 features, STL usage

Perfect for:
- Computer Science students studying algorithms
- Developers learning recursive problem-solving
- Anyone interested in maze generation and pathfinding algorithms

---

**Happy Maze Generating!** 🌟




