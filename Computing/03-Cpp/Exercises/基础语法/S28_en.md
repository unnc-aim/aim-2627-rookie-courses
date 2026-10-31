# S28 Sum decimal digits

Lesson 1 · Section 1.4

## Problem

Read an integer in [0,10^9] and print the sum of its decimal digits.

## Sample input

```text
507
```

## Sample output

```text
12
```

## Step-by-step reasoning

Repeatedly extract the last digit with a remainder and remove it with integer division.

## Rules and boundaries

A do-while loop executes once even for the input zero.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    int n = 0, sum = 0;
    std::cin >> n;
    do {
        sum += n % 10;
        n /= 10;
    } while (n != 0);
    std::cout << sum << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
