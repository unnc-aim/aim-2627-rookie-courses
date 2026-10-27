# S39 Stable filtering

Lesson 1 · Chapter 06 · Arrays, std::array, and range iteration

## Problem

Read n<=1000 integers. Print the nonnegative values in their original order, one per line.

## Sample input

```text
4 -2 0 4 -1
```

## Sample output

```text
0
4
```

## Step-by-step reasoning

Append only nonnegative values without sorting or reversing; retain zero.

## Rules and boundaries

Stable filtering retains relative input order.

## Complete single-file reference program

```cpp
#include <iostream>
#include <vector>

int main() {
    int n = 0, x = 0;
    std::cin >> n;
    std::vector<int> valid;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        if (x >= 0)
            valid.push_back(x);
    }
    for (int v : valid)
        std::cout << v << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
