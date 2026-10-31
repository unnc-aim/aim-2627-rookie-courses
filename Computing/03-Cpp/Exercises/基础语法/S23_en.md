# S23 Gregorian leap years

Lesson 1 · Section 1.3

## Problem

Read a year in [1,9999]. Print LEAP for a Gregorian leap year and COMMON otherwise.

## Sample input

```text
1900
```

## Sample output

```text
COMMON
```

## Step-by-step reasoning

Combine divisibility by 400 with divisibility by 4 but not by 100.

## Rules and boundaries

A century divisible by 100 must also be divisible by 400.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    int y = 0;
    std::cin >> y;
    bool leap = y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
    std::cout << (leap ? "LEAP" : "COMMON") << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
