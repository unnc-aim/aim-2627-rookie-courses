# S57 Value parameters do not swap callers

Lesson 1 · Section 1.8

## Problem

Swap the local copies in swap_value. Read a and b, call it, and print the original arguments.

## Sample input

```text
10 20
```

## Sample output

```text
10 20
```

## Step-by-step reasoning

Trace the caller and parameter objects separately rather than inferring caller state from internal output.

## Rules and boundaries

The code compiles, but its assignments affect parameter copies.

## Complete single-file reference program

```cpp
#include <iostream>

void swap_value(int a, int b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int a = 0, b = 0;
    std::cin >> a >> b;
    swap_value(a, b);
    std::cout << a << ' ' << b << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
