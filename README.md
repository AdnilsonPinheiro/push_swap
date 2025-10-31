# push_swap

push_swap is a sorting algorithm project that implements a program to sort data on a stack with a limited set of operations. The goal is to produce a sequence of operations that sorts the input numbers using as few operations as possible.

This repository contains an implementation in C (42-school style) that solves the push_swap challenge: given a list of integers, output a list of operations which will sort them in ascending order using two stacks (commonly named A and B) and a restricted set of stack operations.

## Table of contents

- [Project overview](#project-overview)
- [Rules & allowed operations](#rules--allowed-operations)
- [Build](#build)
- [Usage](#usage)
- [Examples](#examples)
- [Algorithmic approach](#algorithmic-approach)
- [Understanding Radix Sort](#understanding-radix-sort)
- [File structure](#file-structure)
- [Testing & checking](#testing--checking)
- [Performance notes](#performance-notes)
- [Contributing](#contributing)
- [Author](#author)
- [License](#license)

## Project overview

push_swap receives a list of integers (passed as command-line arguments) and prints to standard output a sequence of operations that will sort that list in ascending order. The operations must be valid and the resulting sequence, when applied to the initial stack A (with stack B empty), must yield a sorted stack A.

This implementation aims for correctness first and then to reduce the number of operations with a combination of strategies for small and large input sizes.

## Rules & allowed operations

You may only use the following operations. Each operation prints its name as the output command:

- sa — swap the first two elements at the top of stack A
- sb — swap the first two elements at the top of stack B
- ss — sa and sb at the same time
- pa — take the first element at the top of B and put it at the top of A
- pb — take the first element at the top of A and put it at the top of B
- ra — rotate A: shift up all elements of stack A by 1 (first becomes last)
- rb — rotate B: shift up all elements of stack B by 1
- rr — ra and rb at the same time
- rra — reverse rotate A: shift down all elements of stack A by 1 (last becomes first)
- rrb — reverse rotate B: shift down all elements of stack B by 1
- rrr — rra and rrb at the same time

Constraints the program enforces (typical for push_swap):
- Input must be integers (32-bit signed).
- No duplicate numbers.
- If the input is already sorted, the program should output nothing.

## Build

Requirements:
- GCC (or another C compiler)
- Make

To compile the project, run:

```bash
make
```

This will build the `push_swap` executable.

To clean build artifacts:

```bash
make fclean
```

To rebuild from scratch:

```bash
make re
```

## Usage

Basic usage:

```bash
./push_swap 3 2 1 6 5 4
```

This prints a series of operation names (one per line) that, if applied, will sort the numbers.

If you have a `checker` program available (common in push_swap projects), you can validate operations:

```bash
./push_swap 3 2 1 6 5 4 | ./checker 3 2 1 6 5 4
```

The `checker` reads the operations output by `push_swap` and prints `OK` if the operations sort the input stack, or `KO` otherwise.

## Examples

Example input:

```bash
./push_swap 2 1 3 6 5 4
```

Possible output (example):

```
sa
pb
ra
pa
rra
```

This sequence is only illustrative — the implementation will produce its own (optimized) sequence.

## Algorithmic approach

Strategies used in this repository include:

- Small sets (2–5 elements): handcrafted optimal sequences (insertion-like / minimal swaps).
- Medium to large sets: bitwise radix operations.

The implementation focuses on:
- Correctness and safe input parsing.
- Handling edge cases (already sorted, invalid input, duplicates).

## Understanding Radix Sort

Radix sort is a well-Known algorithmic approach to sorting numbers. In this approach, we divide numbers
from the LSD (least significant digit) to the MSD (most significant digit) before rearranging them together
and moving on the next digit.

### Sort per digit

Say we have regular decimal numbers. We start at the unitary digit (the first one to the right) and divide them
each in a separate box: a box for the 1's, another box for the 2's and so on — remember: we are looking at only
one digit at a time.

After that first division, we put them back together in ascending order, always looking at 
that particular digit, and move to next one (in our case, the 2nd to the right). We do the same operations
until we reach the leftmost digit.

Through radix sort, by the time we sort the higher digits, the lower digits are already sorted (when we reach
the thousands, both the hundreds, the tens and the units are already sorted).

### Using radix sort in this project

Since `push_swap` only allows us to use two stacks, in order to implement radix sort we must operate on binary.
Although for someone who hasn't had contact with binary operations it might seem overwhelming, once you 
understand how it works in C it is fairly straight-forward.

Instead of sorting the digits in the numbers (which would require ten different stacks), we sort the bits
that constitute those numbers in binary, applying the same logic: from LSD to MSD, one bit at a time.

## Project structure



## Testing & checking

This project provides a `test.sh` shell script. This script generates 100 random non-negative integers
between 0 and 1000 and runs push_swap with said integers as arguments. You can edit the script to extend
or diminish the number of integers generated.

The script does not check if the program sorts the numbers properly, though, either does it check the
program's output against the project's benchmark.

To use the tester simply run `./test.sh`

## Performance notes

The primary goal of push_swap is to minimize the number of operations. Different strategies perform better at different input sizes:

- Very small (<= 3–5): optimal hand-tuned sequences.
- Medium (up to ~100): chunking or insertion-based approaches can be effective.
- Large (hundreds): radix or binary partition strategies usually produce stable and competitive operation counts.

Tuning thresholds and chunk sizes can improve performance for your specific implementation.

## Contributing

Contributions are welcome. If you want to suggest improvements or submit fixes:

- Fork the repository.
- Create a feature branch.
- Open a pull request with a clear description of changes and motivation.
- Add tests where applicable.

Please respect the coding style used in the repository (norminette / project-specific style) and include clear commit messages.

## Author

Adnilson Pinheiro — https://github.com/AdnilsonPinheiro

## License

This repository is provided under the MIT License. See the LICENSE file for details.
