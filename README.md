# Push Swap

A sorting algorithm project that sorts a stack of integers using a limited set of operations with the goal of minimizing the number of moves.

## 📖 Description

Push Swap is a program that sorts a stack of integers (stack A) using an auxiliary stack (stack B) and a predefined set of operations. The challenge is to sort the stack using the **minimum number of operations** possible.

This project implements an efficient sorting algorithm that handles:
- Small stacks (2-3 elements) with optimized hardcoded solutions
- Medium stacks (up to ~90 elements) using median-based partitioning
- Large stacks (500+ elements) with advanced optimization techniques

## 🎯 Objectives

- Sort integers in ascending order using only allowed operations
- Minimize the number of operations required
- Handle edge cases (duplicates, already sorted, reverse sorted)
- Implement a checker program to validate sorting sequences

## 🔧 Operations

The program can only use these operations:

### Stack A Operations
- `sa` - Swap the first 2 elements at the top of stack A
- `pa` - Push the first element of stack B to the top of stack A
- `ra` - Rotate stack A up (first element becomes last)
- `rra` - Rotate stack A down (last element becomes first)

### Stack B Operations
- `sb` - Swap the first 2 elements at the top of stack B
- `pb` - Push the first element of stack A to the top of stack B
- `rb` - Rotate stack B up (first element becomes last)
- `rrb` - Rotate stack B down (last element becomes first)

### Combined Operations
- `ss` - Execute `sa` and `sb` simultaneously
- `rr` - Execute `ra` and `rb` simultaneously
- `rrr` - Execute `rra` and `rrb` simultaneously

## 🏗️ Algorithm Strategy

### 1. Small Arrays (2-3 elements)
Direct hardcoded solutions for optimal performance.

### 2. Medium Arrays (4-90 elements)
- **Median-based partitioning**: Split elements around median values
- **Push smaller elements to stack B**: Keep larger elements in stack A
- **Smart positioning**: Elements below median go to bottom of stack B
- **Efficient sorting**: Sort remaining elements in stack A, then merge back

### 3. Large Arrays (90+ elements)
- **Advanced median partitioning**: Multiple median levels for better distribution
- **Cost calculation**: Each move calculates the total cost to optimally position elements
- **Cheapest move selection**: Always choose the element that requires the least moves
- **Optimization**: Combine rotations when both stacks need to move in the same direction

## 📁 Project Structure

```
push_swap/
├── src/                    # Main program source files
│   ├── push_swap.c        # Main program entry point
│   ├── parsing.c          # Input validation and parsing
│   ├── instructions_a.c   # Stack A operations (sa, pa, ra, rra)
│   ├── instructions_b.c   # Stack B operations (sb, pb, rb, rrb)
│   ├── instructions.c     # Combined operations (ss, rr, rrr)
│   ├── sorting.c          # Main sorting algorithm
│   ├── sorting2.c         # Advanced sorting functions
│   ├── supercalculator.c  # Cost calculation and optimization
│   ├── optimization.c     # Algorithm optimizations
│   └── ...
├── bonus/                 # Checker program
│   ├── checker.c          # Checker main program
│   ├── get_next_line_*    # Reading instructions from stdin
│   └── ...
├── includes/              # Header files
│   ├── push_swap.h        # Main header
│   ├── checker.h          # Checker header
│   └── ...
├── libft/                 # Custom C library
└── Makefile              # Build configuration
```

## 🚀 Compilation

### Build the main program:
```bash
make
```

### Build the checker (bonus):
```bash
make bonus
```

### Clean object files:
```bash
make clean
```

### Full clean (including binaries):
```bash
make fclean
```

### Rebuild everything:
```bash
make re
```

## 📋 Usage

### Push Swap Program
```bash
./push_swap [list of integers]
```

**Examples:**
```bash
./push_swap 3 2 1
./push_swap 42 1 67 34 2
./push_swap "5 4 3 2 1"
```

The program outputs the sequence of operations needed to sort the stack.

### Checker Program (Bonus)
```bash
./push_swap [numbers] | ./checker [same numbers]
```

**Example:**
```bash
./push_swap 3 2 1 | ./checker 3 2 1
# Output: OK (if sorted correctly) or KO (if not)
```

**Manual checking:**
```bash
./checker 3 2 1
sa
ra
[Ctrl+D]
# Output: OK or KO
```

## 🧪 Testing

### Basic Tests
```bash
# Test with 3 numbers
./push_swap 2 1 3

# Test with 5 numbers
./push_swap 5 4 3 2 1

# Test with duplicates (should output "Error")
./push_swap 1 2 2 3

# Test with non-integers (should output "Error")
./push_swap 1 abc 3
```

### Performance Tests
```bash
# Generate 100 random numbers and test
ARG="4 67 3 87 23 ..."  # Your random numbers
./push_swap $ARG | wc -l  # Count operations
./push_swap $ARG | ./checker $ARG  # Verify correctness
```

### Performance Benchmarks
- **3 elements**: ≤ 3 operations
- **5 elements**: ≤ 12 operations
- **100 elements**: ≤ 700 operations
- **500 elements**: ≤ 5500 operations

## ⚠️ Error Handling

The program handles various error cases:

- **Non-integer arguments**: `Error`
- **Duplicated numbers**: `Error`
- **Empty input**: No output (success)
- **Already sorted**: No output (success)
- **Invalid instructions** (checker): `Error`

## 🏆 Key Features

### Optimizations Implemented
- **Early termination**: Stop if stack is already sorted
- **Hardcoded solutions**: Optimal moves for small stacks
- **Cost-based decisions**: Always choose the cheapest move
- **Combined operations**: Use `rr`, `rrr`, `ss` when beneficial
- **Smart partitioning**: Efficient median-based splitting

### Data Structure
- **Doubly-linked circular lists**: Efficient for stack operations
- **Rank system**: Elements are assigned ranks for easy comparison
- **Position tracking**: Track element positions for cost calculation

## 🔧 Technical Details

### Complexity
- **Time Complexity**: O(n²) worst case, O(n log n) average
- **Space Complexity**: O(n) for the stacks

### Algorithm Highlights
1. **Parsing & Validation**: Convert arguments to integers with error checking
2. **Ranking**: Assign ranks (1 to n) to handle any integer range
3. **Median Partitioning**: Split around median for balanced distribution
4. **Cost Calculation**: Calculate rotation costs for optimal moves
5. **Final Positioning**: Ensure smallest element is at top

## 👨‍💻 Author

**fli** - 42 School Student

## 📝 License

This project is part of the 42 School curriculum.

---

*This project demonstrates understanding of sorting algorithms, data structures, and optimization techniques while working within strict constraints.*
