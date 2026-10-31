# S08 Identify failure stages

Lesson 1 · Section 1.1

## Problem

Read x in [-1000,1000] and print its square. Explain where a missing semicolon, a declared but undefined function, and an incorrect result are detected.

## Sample input

```text
7
```

## Sample output

```text
49
```

## Step-by-step reasoning

Verify the square, then introduce one compilation, linking, or logic fault at a time.

## Rules and boundaries

These correspond to compilation, linking, and program logic respectively.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    int x = 0;
    std::cin >> x;
    std::cout << x * x << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
