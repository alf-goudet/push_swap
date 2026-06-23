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

### Execution
