# S49 Parameters and a return value

Lesson 1 · Section 1.8

## Problem

Read two integers in [-1000,1000], call add, and print its returned sum.

## Sample input

```text
4 5
```

## Sample output

```text
9
```

## Step-by-step reasoning

Keep I/O in main and calculation in add; distinguish parameter values, returned values, and printing.

## Rules and boundaries

Parameters are local to the function; return supplies a value to the caller.

## Complete single-file reference program

```cpp
#include <iostream>

int add(int a, int b) { return a + b; }

int main() {
    int a = 0, b = 0;
    std::cin >> a >> b;
    std::cout << add(a, b) << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
