# S22 Median of three values

Lesson 1 · Section 1.3

## Problem

Read three integers in [-1000,1000] and print their median without sorting. Duplicates are allowed.

## Sample input

```text
9 4 4
```

## Sample output

```text
4
```

## Step-by-step reasoning

Find the minimum and maximum, then subtract one occurrence of each from the sum.

## Rules and boundaries

Removing one minimum and one maximum from the sum works with duplicates; consider range when generalizing.

## Complete single-file reference program

```cpp
#include <algorithm>
#include <iostream>

int main() {
    int a = 0, b = 0, c = 0;
    std::cin >> a >> b >> c;
    int lo = std::min(a, std::min(b, c));
    int hi = std::max(a, std::max(b, c));
    std::cout << a + b + c - lo - hi << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
