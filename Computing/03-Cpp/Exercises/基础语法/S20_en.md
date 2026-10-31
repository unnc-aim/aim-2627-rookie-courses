# S20 Protect a division

Lesson 1 · Section 1.3

## Problem

Read a and b. Print INVALID if b is zero; otherwise print whether the integer quotient is greater than 2, using boolalpha.

## Sample input

```text
5 0
```

## Sample output

```text
INVALID
```

## Step-by-step reasoning

Branch on b before computing a quotient, and avoid using a placeholder result on invalid input.

## Rules and boundaries

Exclude zero divisors before evaluating the division.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    int a = 0, b = 0;
    std::cin >> a >> b;
    if (b == 0)
        std::cout << "INVALID\n";
    else
        std::cout << std::boolalpha << (a / b > 2) << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
