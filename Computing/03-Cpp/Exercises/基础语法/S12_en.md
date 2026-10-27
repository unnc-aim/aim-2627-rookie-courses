# S12 Multiply large integers

Lesson 1 · Chapter 04 · Evaluating operators step by step

## Problem

Read two integers in [0,10^9] and print their product.

## Sample input

```text
1000000000 1000000000
```

## Sample output

```text
1000000000000000000
```

## Step-by-step reasoning

Declare both operands long long so the multiplication is wide from the outset.

## Rules and boundaries

Use a wide type during the multiplication rather than assigning an already-overflowed int result to long long.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    long long a = 0, b = 0;
    std::cin >> a >> b;
    std::cout << a * b << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
