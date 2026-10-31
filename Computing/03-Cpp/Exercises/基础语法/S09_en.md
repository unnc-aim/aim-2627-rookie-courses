# S09 Integer and floating-point division

Lesson 1 · Section 1.2

## Problem

Read positive integers a and b. Print the integer quotient and the real quotient with two decimal places.

## Sample input

```text
3 2
```

## Sample output

```text
1 1.50
```

## Step-by-step reasoning

Keep the integer quotient as a comparison, then convert a before the second division and format two decimal places.

## Rules and boundaries

Convert an operand before division. Converting a/b afterward cannot recover its fractional part.

## Complete single-file reference program

```cpp
#include <iomanip>
#include <iostream>

int main() {
    int a = 0, b = 0;
    std::cin >> a >> b;
    std::cout << a / b << ' ' << std::fixed << std::setprecision(2)
              << static_cast<double>(a) / b << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
