# S27 Skip and stop

Lesson 1 · Chapter 05 · Conditions and for loops

## Problem

Read integers. Skip negatives, stop at 0, and sum the remaining values.

## Sample input

```text
3 -2 4 0 9
```

## Sample output

```text
7
```

## Step-by-step reasoning

Handle zero as termination, skip negatives, then add positive values.

## Rules and boundaries

continue starts the next iteration; break exits the loop.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    int x = 0;
    long long total = 0;
    while (std::cin >> x) {
        if (x == 0)
            break;
        if (x < 0)
            continue;
        total += x;
    }
    std::cout << total << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
