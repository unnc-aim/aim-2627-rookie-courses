# S33 Initialize std::array

Lesson 1 · Chapter 06 · Arrays, std::array, and range iteration

## Problem

Create `std::array<int,5>` with explicit values 94,87,50 only. Print each element on its own line.

## Sample input

```text
(no input)
```

## Sample output

```text
94
87
50
0
0
```

## Step-by-step reasoning

Use the three explicit values and two zero-initialized values, then iterate over all five elements.

## Rules and boundaries

Omitted aggregate initializers become zero; uninitialized local integer arrays have no such guarantee.

## Complete single-file reference program

```cpp
#include <array>
#include <iostream>

int main() {
    std::array<int, 5> scores = {94, 87, 50};
    for (int score : scores)
        std::cout << score << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
