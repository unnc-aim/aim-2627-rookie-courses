# S38 Adjacent differences

Lesson 1 · Section 1.5

## Problem

Read n>=1 integers, where n<=1000 and each magnitude is at most 1000. Print each next-minus-previous difference on its own line.

## Sample input

```text
3 2 5 3
```

## Sample output

```text
3
-2
```

## Step-by-step reasoning

Compute a[i]-a[i-1] starting at index one.

## Rules and boundaries

Start at index 1. A single-element input produces no differences.

## Complete single-file reference program

```cpp
#include <iostream>
#include <vector>

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x : a)
        std::cin >> x;
    for (int i = 1; i < n; ++i)
        std::cout << a[i] - a[i - 1] << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
