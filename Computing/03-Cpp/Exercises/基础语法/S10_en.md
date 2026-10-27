# S10 Split a duration

Lesson 1 · Chapter 04 · Evaluating operators step by step

## Problem

Read a duration in [0,1000000] seconds. Print hours, remaining minutes, and remaining seconds without zero padding.

## Sample input

```text
3661
```

## Sample output

```text
1 1 1
```

## Step-by-step reasoning

Divide by 3600 for hours, take minutes modulo 60, and use the seconds remainder modulo 60.

## Rules and boundaries

Quotients count whole units; remainders keep the unconsumed portion.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    int seconds = 0;
    std::cin >> seconds;
    std::cout << seconds / 3600 << ' ' << seconds / 60 % 60 << ' ' << seconds % 60
              << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
