# 🔄 Push_swap

## 📋 Table of Contents

- [About](#-about)
- [Game Rules](#-game-rules)
- [Algorithm](#-algorithm)
- [Installation](#-installation)
- [Usage](#-usage)
- [Bonus - Checker](#-bonus---checker)
- [Performance](#-performance)
- [Project Structure](#-project-structure)

## 📖 About

**Push_swap** is a 42 school project that consists of sorting a stack of integers using a limited set of operations while minimizing the number of actions performed.

The challenge: sort data with only two stacks (A and B) and 11 possible operations.

## 🎮 Game Rules

### The Stacks

- **Stack A**: Initially contains the numbers to be sorted
- **Stack B**: Empty at the start, used as temporary workspace

### Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap A - Swaps the first 2 elements of stack A |
| `sb` | Swap B - Swaps the first 2 elements of stack B |
| `ss` | Swap A and B simultaneously |
| `pa` | Push A - Moves the first element from B to A |
| `pb` | Push B - Moves the first element from A to B |
| `ra` | Rotate A - Shifts all elements of A up by one |
| `rb` | Rotate B - Shifts all elements of B up by one |
| `rr` | Rotate A and B simultaneously |
| `rra` | Reverse Rotate A - Shifts all elements of A down by one |
| `rrb` | Reverse Rotate B - Shifts all elements of B down by one |
| `rrr` | Reverse Rotate A and B simultaneously |

## 🧠 Algorithm

### Overview

The implementation uses a **chunk-based sorting algorithm** inspired by quicksort, with several optimizations:

### 1. Data Normalization (Ranking)

Input values are converted to ranks (1 to N) to simplify comparisons:
```
Input:   [42, -5, 100, 0]
Ranks:   [3,   1,   4,  2]
```

### 2. Optimized Edge Cases

- **3 elements**: Direct sort with maximum 2 operations
- **5 elements**: Push 2 smallest to B, sort 3, then retrieve

### 3. Chunk Sort (General Case)

The algorithm recursively divides the stack into 3 parts:
- **High**: Largest values (top 1/3)
- **Mid**: Medium values
- **Low**: Smallest values (bottom 1/3)

```
┌─────────────────────────────────────────┐
│           SPLIT CHUNK                   │
│                                         │
│   TOP_A ──► High → BOT_A                │
│           │ Mid  → TOP_B                │
│           └ Low  → BOT_B                │
│                                         │
│   Then recursion on each part           │
└─────────────────────────────────────────┘
```

### 4. Circular Stack Structure

Stacks are implemented as circular arrays with `top` and `bot` pointers, enabling O(1) operations for rotate and reverse_rotate.

### 5. Quick Sort Optimizations

During sorting, the algorithm checks if elements can be placed directly in their final position, thus reducing the number of operations.

## 🔧 Installation

```bash
# Clone the repository
git clone https://github.com/your-username/push_swap.git

# Navigate to the directory
cd push_swap

# Compile the project
make

# Compile with bonus (checker)
make bonus
```

## 🚀 Usage

### Main Program

```bash
# With separate arguments
./push_swap 4 67 3 87 23

# With a string
./push_swap "4 67 3 87 23"

# With randomly generated numbers
ARG=$(shuf -i 1-100 | tr '\n' ' '); ./push_swap $ARG

# Count the number of operations
./push_swap 4 67 3 87 23 | wc -l
```

### Verification with Checker

```bash
# Check if sorting is correct
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
# Expected output: OK

# Interactive test
./checker 3 2 1
sa
rra
# Ctrl+D to finish
```

### Output Examples

```bash
$ ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
ra
pa
pa
pa
```

## 🎁 Bonus - Checker

The `checker` program verifies whether a sequence of instructions correctly sorts the stack.

### How it Works

1. Reads instructions from standard input
2. Executes each instruction on the stacks
3. Displays `OK` if stack A is sorted and B is empty
4. Displays `KO` otherwise
5. Displays `Error` for invalid instructions

### Recognized Instructions

```
sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
```

## 📊 Performance

### 42 School Objectives

| Size | Maximum for full grade | My Implementation |
|------|----------------------|-------------------|
| 3    | 3 operations         | ≤ 2               |
| 5    | 12 operations        | ≤ 8               |
| 100  | 700 operations       | ~550 average      |
| 500  | 5500 operations      | ~4200 average     |

### Test Script

```bash
# Run performance tests
chmod +x test.sh
./test.sh
```

## 📁 Project Structure

```
push_swap/
├── Makefile
├── include/
│   ├── push_swap.h          # Main header
│   ├── stack.h              # Data structures
│   ├── operations.h         # Operation prototypes
│   └── checker_bonus.h      # Checker header
├── srcs/
│   ├── main.c               # Entry point
│   ├── ft_parsing.c         # Argument parsing
│   ├── input_validation.c   # Input validation
│   ├── stack_initz.c        # Stack initialization
│   ├── ft_execute.c         # Sort orchestration
│   ├── sort_chunk.c         # Chunk sorting
│   ├── chunk_split.c        # Chunk division
│   ├── chunk_utils.c        # Chunk utilities
│   ├── sort_three.c         # 3-element sorting
│   ├── sort_optimize.c      # Optimizations
│   ├── split_utils.c        # Split utilities
│   ├── change_stack.c       # Inter-stack movements
│   ├── swap_op.c            # Swap operations
│   ├── push_op.c            # Push operations
│   ├── rotate_op.c          # Rotate operations
│   ├── reverse_rotate_op.c  # Reverse rotate operations
│   ├── op_utils.c           # Operation utilities
│   ├── error.c              # Error handling
│   └── print_stack.c        # Debug (stack display)
├── checker_bonus/
│   ├── checker_bonus.c      # Checker main
│   └── checker_utils_bonus.c # Instruction execution
├── libft/                   # Personal library
└── test.sh                  # Test script
```

## 🏗️ Data Structures

### t_stack - Circular Stack
```c
typedef struct s_stack
{
    int    *array;    // Value array
    int    size;      // Total allocated size
    int    top;       // Top index
    int    bot;       // Bottom index
}    t_stack;
```

### t_build - Global Data
```c
typedef struct s_build
{
    t_stack    a;      // Stack A
    t_stack    b;      // Stack B
    int        flag;   // Flag for push_swap vs checker
}    t_build;
```

### t_chunck - Chunk Definition
```c
typedef struct s_chunck
{
    t_loc    loc;     // Location (TOP_A, BOT_A, TOP_B, BOT_B)
    int      size;    // Number of elements
}    t_chunck;
```

### t_loc - Location Enum
```c
typedef enum s_loc
{
    TOP_A,    // Top of stack A
    BOT_A,    // Bottom of stack A
    TOP_B,    // Top of stack B
    BOT_B,    // Bottom of stack B
}    t_loc;
```

## 📝 Makefile Commands

| Command | Description |
|---------|-------------|
| `make` | Compiles the push_swap program |
| `make bonus` | Compiles the checker |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and executables |
| `make re` | Recompiles the entire project |

## ⚠️ Error Handling

The program displays `Error` on stderr in the following cases:
- Non-numeric argument
- Number outside int range
- Duplicate numbers
- Empty argument

## 🔍 Algorithm Deep Dive

### Chunk Splitting Strategy

The algorithm uses different pivot strategies depending on the source location:

**From Stack A:**
- Pivot 1: 2/3 of chunk size
- Pivot 2: 1/3 of chunk size

**From Stack B:**
- Pivot 1: 1/2 of chunk size
- Pivot 2: 1/3 of chunk size

This asymmetry optimizes the distribution of elements across both stacks.

### Destination Mapping

| Source | High → | Mid → | Low → |
|--------|--------|-------|-------|
| TOP_A  | BOT_A  | TOP_B | BOT_B |
| BOT_A  | TOP_A  | TOP_B | BOT_B |
| TOP_B  | TOP_A  | BOT_A | BOT_B |
| BOT_B  | TOP_A  | BOT_A | TOP_B |

### Quick Sort Optimization

During recursion, the algorithm checks if elements can be immediately placed in their final position:
- If the top of A equals chunk's first element + 1: immediate placement
- If the top of A equals chunk's second element + 1: swap then place

## 🧪 Testing

### Manual Testing

```bash
# Test with 3 numbers
./push_swap 3 2 1

# Test with 5 numbers
./push_swap 5 4 3 2 1

# Test already sorted
./push_swap 1 2 3 4 5
# Should output nothing (0 operations)

# Test with negative numbers
./push_swap -1 -5 3 0 2
```

### Automated Testing

```bash
# Run the test script
./test.sh

# Custom test with 100 numbers
for i in {1..100}; do
    ARG=$(shuf -i 1-100 | tr '\n' ' ')
    COUNT=$(./push_swap $ARG | wc -l)
    echo "Test $i: $COUNT operations"
done
```

### Verify with Checker

```bash
# Full verification pipeline
ARG=$(shuf -i 1-500 | tr '\n' ' ')
RESULT=$(./push_swap $ARG | ./checker $ARG)
COUNT=$(./push_swap $ARG | wc -l)
echo "Operations: $COUNT - Result: $RESULT"
```

## 👤 Author

**fducrot** - 42 School Lausanne

---

*Project completed as part of the 42 school curriculum*
