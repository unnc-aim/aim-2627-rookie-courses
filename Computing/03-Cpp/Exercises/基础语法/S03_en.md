# S03 Read two integers

Lesson 1 · Chapter 03 · Input, variables, and output formatting

## Problem

Read two integers in [-1000,1000]. Print their sum and difference, separated by one space.

## Sample input

```text
8 4
```

## Sample output

```text
12 4
```

## Step-by-step reasoning

Extract into a and then b. Compute a+b and a-b in that order without reversing the operands.

## Rules and boundaries

Formatted extraction skips whitespace, so spaces and newlines can separate the integers.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    int a = 0, b = 0;
    std::cin >> a >> b;
    std::cout << a + b << ' ' << a - b << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
