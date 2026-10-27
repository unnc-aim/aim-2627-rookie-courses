# S34 Maximum element

Lesson 1 · Chapter 06 · Arrays, std::array, and range iteration

## Problem

Read n>=1 integers in [-1000,1000], with n<=1000. Print the maximum.

## Sample input

```text
3 -9 -2 -7
```

## Sample output

```text
-2
```

## Step-by-step reasoning

Initialize the maximum from the first stored element and compare each value against it.

## Rules and boundaries

Initialize from the first element rather than zero so all-negative input works.

## Complete single-file reference program

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x : a)
        std::cin >> x;
    int best = a[0];
    for (int x : a)
        best = std::max(best, x);
    std::cout << best << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
