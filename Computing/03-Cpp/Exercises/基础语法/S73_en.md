# S73 Statistics on valid readings

Lesson 1 · Section 1.4

## Problem

Read n<=1000 values. Only [0,100] is valid. Print the valid count and total.

## Sample input

```text
4 -1 0 100 101
```

## Sample output

```text
2 100
```

## Step-by-step reasoning

Update count and sum together only when both range checks succeed.

## Rules and boundaries

Both boundaries are valid; entirely invalid input gives zero count and sum.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    int n = 0, valid = 0, sum = 0, x = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        if (0 <= x && x <= 100) {
            ++valid;
            sum += x;
        }
    }
    std::cout << valid << ' ' << sum << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
