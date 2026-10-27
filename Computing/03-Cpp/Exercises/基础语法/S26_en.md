# S26 Sentinel-controlled input

Lesson 1 · Chapter 05 · Conditions and for loops

## Problem

Read integers until -1 or EOF. Print the sum before termination, excluding -1.

## Sample input

```text
1 2 3 -1 99
```

## Sample output

```text
6
```

## Step-by-step reasoning

Read first, test for the sentinel second, and add only values that satisfy both continuation conditions.

## Rules and boundaries

Both extraction success and the sentinel condition control continuation.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    int x = 0;
    long long total = 0;
    while (std::cin >> x && x != -1)
        total += x;
    std::cout << total << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
