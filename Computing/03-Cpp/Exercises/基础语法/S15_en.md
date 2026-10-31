# S15 Compare with an absolute tolerance

Lesson 1 · Section 1.2

## Problem

Read two floating-point numbers in [-1000,1000]. Print SAME if their absolute difference is at most 1e-6, otherwise DIFF.

## Sample input

```text
0.3 0.3000001
```

## Sample output

```text
SAME
```

## Step-by-step reasoning

Take the absolute difference and include equality at the tolerance boundary.

## Rules and boundaries

This task explicitly uses an absolute tolerance. Real applications should choose tolerances for their scale and units.

## Complete single-file reference program

```cpp
#include <cmath>
#include <iostream>

int main() {
    double a = 0.0, b = 0.0;
    std::cin >> a >> b;
    std::cout << (std::abs(a - b) <= 1e-6 ? "SAME" : "DIFF") << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
