# S68 Row sums in a fixed matrix

Lesson 1 · Chapter 08 · Lesson 1 integration and a preview of structures

## Problem

Read a 2x3 integer matrix with element magnitudes at most 1000. Print one sum per row.

## Sample input

```text
1 2 3 4 5 6
```

## Sample output

```text
6
15
```

## Step-by-step reasoning

Start a fresh accumulator for each outer-loop row and sum only that row’s elements.

## Rules and boundaries

The outer array represents rows and the inner array represents columns.

## Complete single-file reference program

```cpp
#include <array>
#include <iostream>

int main() {
    std::array<std::array<int, 3>, 2> grid = {};
    for (std::array<int, 3> & row : grid)
        for (int &x : row)
            std::cin >> x;
    for (const std::array<int, 3> & row : grid) {
        int sum = 0;
        for (int x : row)
            sum += x;
        std::cout << sum << '\n';
    }
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
