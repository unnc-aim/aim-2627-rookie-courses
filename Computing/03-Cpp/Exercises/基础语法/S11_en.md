# S11 Average three measurements

Lesson 1 · Chapter 04 · Evaluating operators step by step

## Problem

Read three integers in [-1000,1000]. Print their mean with two decimal places.

## Sample input

```text
1 2 3
```

## Sample output

```text
2.00
```

## Step-by-step reasoning

Sum the three values and divide by 3.0. Formatting affects the display rather than the calculation.

## Rules and boundaries

The literal 3.0 selects floating-point division.

## Complete single-file reference program

```cpp
#include <iomanip>
#include <iostream>

int main() {
    int a = 0, b = 0, c = 0;
    std::cin >> a >> b >> c;
    std::cout << std::fixed << std::setprecision(2) << (a + b + c) / 3.0 << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
