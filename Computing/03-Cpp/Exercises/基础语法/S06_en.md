# S06 Detect failed input

Lesson 1 · Chapter 03 · Input, variables, and output formatting

## Problem

Read an integer. Print INVALID if extraction fails; otherwise print twice the value. The magnitude is at most 1000.

## Sample input

```text
robot
```

## Sample output

```text
INVALID
```

## Step-by-step reasoning

Test the extraction itself. Only the successful branch uses the value in multiplication.

## Rules and boundaries

A failed extraction changes the stream state. Do not treat an initialized variable as a valid reading.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    int value = 0;
    if (!(std::cin >> value)) {
        std::cout << "INVALID\n";
    } else {
        std::cout << 2 * value << '\n';
    }
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
