_This project has been created as part of the 42 curriculum by agoudet-_

## Description

`push_swap` is a project that challenges students to write a program in C that
sorts a random list of integers read as arguments, using two stacks, a limited
set of instructions, and in the lowest possible amount of actions (instruction
executions).

The goal of this project is to introduce students to two concepts common in job
interviews: **sorting algorithms** and **complexity**. The project also aims to
teach students to not just explore different algorithms for the same thing, but
also to **optimize** the performance of their chosen algorithm.

### Overview

Students are armed with the following:

- Two stacks, `a` and `b`.
- A series of operations to reposition the integers:
	- *`sa`*: Swaps the top number in stack a and the number below it.
	- *`sb`*: Swaps the top number in stack b and the number below it.
	- *`ss`*: Executes both *`sa`* and *`sb`* in one operation.
	- *`pa`*: Pushes the top element in stack b to stack a, making it the top
		element in a.
	- *`pb`*: Pushes the top element in stack a to stack b, making it the top
		element in b.
	- *`ra`*: Switches all numbers' positions in stack a upwards by one. The
		top element becomes the bottom one.
	- *`rb`*: Switches all numbers' positions in stack b upwards by one. The
		top element becomes the bottom one.
	- *`rr`*: Executes both *`ra`* and *`rb`* in one operation.
	- *`rra`*: Switches all numbers' positions in stack a downwards by one.
		The bottom number becomes the top one.
	- *`rrb`*: Switches all numbers' positions in stack b downwards by one.
		The bottom number becomes the top one.
	- *`rrr`*: Executes both *`rra`* and *`rrb`* in one operation.
		
## Instructions

### Compilation

Run the following command on the Terminal:

```bash
make
```

This will:
1. Compile all source (**`.c`**) files into their corresponding binary object
files (**`.o`**).
2. Use the resulting `.a` static libraries (`libpushswap.a`, `libftprintf.a`
and `libft.a`) to compile everything into an executable binary program called
**`push_swap`**.

To remake the `push_swap` program (i.e. delete all `.o` files and `.a` libraries
and compile from scratch again), run:

```bash
make re
```

To clean up all resulting components (`.o` files, `.a` libraries, etc) and keep
the main executable program (`push_swap`), run:

```bash
make clean
```

To clean up everything, including the `push_swap` executable, and leave only the
source code as it was from the start, run:

```bash
make fclean
```

### Execution

***REALLY IMPORTANT***: Before running the `push_swap` program, it is
recommended that before testing the `push_swap` program, the following command
is ran to ensure normal expected behavior when testing with commands from the
eval sheet:

```
bash
```

This will ensure that the shell to run commands and programs on will be `bash`.

NOTE: The usual default shell on most 42 campus computers is `zsh`. This is
explained more in detail in the following sub-section:

#### The differences between `bash` and `zsh`
Both shells interpret certain
commands and special characters differently, and thus the same command can be
lead to different results in different shells. `bash` and `zsh` are a common
point of confusion among many evaluation sessions.

EXAMPLE: Let's take the following command:

```bash
ARG="1 2 3 4 5"; ./push_swap $ARG
```

When ran in `bash` the command translates to the following:
-  `./push_swap` takes 5 additional arguments besides the program name
`"./push_swap"`: `"1"`, `"2"`, `"3"`, `"4"` and `"5"`. This
is the normal expected way for the program to receive its input.

However, the same command, when run in `zsh` (Z shell), leads to a different
reception of input:
- `./push_swap` takes 1 additional argument: `"1 2 3 4 5"`. The program then
interprets this "string" of digits as a single integer, "1", and thus leads to
unexpected behavior.

To get the program to behave the same way in `zsh` as it would in `bash`, the
shell command must be rewritten like this:

```zsh
ARG=(1 2 3 4 5); ./push_swap $ARG
```

**To clarify**: The normal expected shell to work `push_swap` on is `bash`.

#### Execution commands

To run the `push_swap` program, there are various ways to run it to test for
different things:

1. Regular run: Execute `push_swap` giving a series of random numbers as
additional arguments. These will be the integers that `push_swap` will try to
sort.

```bash
./push_swap 7 3 1 4 2 0 5
```

2. Run with an `ARG` environment variable: flexible for large amounts of numbers
and for checking correct sorting with the `checker` program.

```bash
ARG="7 3 1 4 2 0 5"; ./push_swap $ARG
```

3. Test for number of actions: To check how many operations `push_swap` took to
sort the numbers, pipe the output of `push_swap` to a shell command to count
them:

```bash
ARG="7 3 1 4 2 0 5"; ./push_swap $ARG | wc -l
```

**What this does**: Counts the number of lines that `push_swap` outputted (Each
line being an operation that it ran, one after the other)

4. Test if sorted was correctly done with a `checker` program:

```bash
ARG="7 3 1 4 2 0 5"; ./push_swap $ARG | ./checker_[OS] $ARG
```

This will result in one of two outputs:
1. **OK**: If the command sequence generated by `push_swap` correctly sorts the
given integers.
2. **KO**: If the command sequence fails to sort the integers correctly.

## Resources

The following resources were used to learn the basics of sorting:
- [Sorting Algorithms](https://www.geeksforgeeks.org/dsa/sorting-algorithms/) by GeeksforGeeks
- [VisuAlgo Sorting Visualiser](https://visualgo.net/en/sorting)

### AI Usage

AI was used in the following aspects of the project:
- Step-by-Step Guided Assistance in Writing Code for the Chunk-Based Cost
Minimization sorting for 100 and 500 numbers. I wrote the code myself from there
and came up with the formulas myself.
