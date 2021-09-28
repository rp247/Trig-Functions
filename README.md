Ruchit Patel

rpatel18

Spring 2021

Assignment 2: A Small Numerical Library

---------------------
DESCRIPTION

- A number of mathematical functions, namely arcSin(x), arcCos(x), arcTan(x), and Log(x) (natural log), are implemented in this lab. 
- The arcSin(x), arcCos(x) are implemented using the inverse method with Newton’s method.
- The arcTan(x) is implemented using the arcCos(x) and a trigonometric property. 
- The Log(x) is also implemented using the inverse method with Newton’s method.
- Arguments: One could run the program with -a (runs all functions), -s (runs arcSin(x) function),  -c (runs arcCos(x) function),  -t (runs arcTan(x) function), and  -l (runs Log(x) function). All the 
 flags can be used with each other but if passed as an argument a function would only be run 
 regardless of how many times it has been passed as an argument.


---------------------
FILES

1. mathlib.c

- This file has the source code and implementation of all the functions described above.

2. matlib-test.c 

- This file contains the code for parsing the arguments, calling the functions in mathlib.c and comparing the output to math libraries’ output (acts as a test harness)

3. mathlib.h

- This header file declares all the math functions mentioned above.

4. DESIGN.pdf 

- This PDF explains the design for this lab. It includes a brief description of the lab, flowchart, and pseudocode alongwith implementation description.

5. WRITEUP.pdf

- This file contains the analysis of differences between my output of the math functions and output of the math library function.

6. Makefile

- This is a Makefile that can be used with the make utility to build the executable.



---------------------
INSTRUCTIONS

Manually:
1. Keep the mathlib.c mathlib-test.c and mathlib.h files in the same directory and compile the sources file using clang compiler in Ubuntu 20.04.

2. The documented compilation command is as follows: clang -Wall -Wextra -Wpedantic -Wshadow -o matlib-test matlib-test.c mathlib.c -lm

3. Finally, execute ./mathlib-test -[arguments] in a terminal. 

4. The program would run and print the functions based on the arguments. 


With make:
1. Keep the Makefile in the same directory as all other files mentioned above.

2. Execute “make” or “make all” in terminal in order to produce the mathlib-test executable. 

3. Finally, execute ./mathlib-test -[arguments] in a terminal. 

4. The program would run and print the functions based on the arguments. 

5. In order to scan-build the source file, run “make scan-build” in the terminal.

6. In order to clean up (remove object and executable files), run “make clean” in the terminal.



