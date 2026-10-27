# S32 Longest consecutive detection run

Lesson 1 · Chapter 05 · Conditions and for loops

## Problem

Read n values, each 0 or 1, with n in [0,1000]. Print the longest run of ones.

## Sample input

```text
7 1 1 0 1 1 1 0
```

## Sample output

```text
3
```

## Step-by-step reasoning

Extend the current run for one, reset it for zero, and update the historical maximum at every step.

## Rules and boundaries

run tracks the run ending at the current position; best tracks the historical maximum.

## Complete single-file reference program

```cpp
#include <algorithm>
#include <iostream>

int main() {
    int n = 0, value = 0, run = 0, best = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        run = value == 1 ? run + 1 : 0;
        best = std::max(best, run);
    }
    std::cout << best << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
