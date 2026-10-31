# S18 Closed-interval membership

Lesson 1 · Section 1.3

## Problem

Read a speed. Print SAFE if it lies in [-3,3], otherwise UNSAFE.

## Sample input

```text
-3
```

## Sample output

```text
SAFE
```

## Step-by-step reasoning

Check both bounds with AND and include both endpoints.

## Rules and boundaries

Write two comparisons joined by && rather than a chained mathematical inequality.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    double speed = 0.0;
    std::cin >> speed;
    std::cout << (speed >= -3 && speed <= 3 ? "SAFE" : "UNSAFE") << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
