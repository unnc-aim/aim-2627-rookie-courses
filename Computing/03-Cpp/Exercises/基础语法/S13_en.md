# S13 Convert Celsius to Fahrenheit

Lesson 1 · Section 1.2

## Problem

Read C in [-100,200] and compute F=C*9/5+32. Print one decimal place.

## Sample input

```text
25
```

## Sample output

```text
77.0
```

## Step-by-step reasoning

Preserve the formula order, use floating-point constants, and apply one-decimal formatting only when printing.

## Rules and boundaries

Use floating-point constants to avoid an unintended integer ratio.

## Complete single-file reference program

```cpp
#include <iomanip>
#include <iostream>

int main() {
    double c = 0.0;
    std::cin >> c;
    std::cout << std::fixed << std::setprecision(1) << c * 9.0 / 5.0 + 32.0 << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
