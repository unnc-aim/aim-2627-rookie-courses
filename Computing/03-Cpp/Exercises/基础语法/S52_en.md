# S52 Default arguments

Lesson 1 · Section 1.8

## Problem

Implement scale(value,factor=2). Read value of magnitude at most 1000 and print results with the default factor and an explicit factor of 3.

## Sample input

```text
4
```

## Sample output

```text
8 12
```

## Step-by-step reasoning

Omit the second argument once and explicitly pass three in the second call.

## Rules and boundaries

Specify a default at the declaration, not redundantly at both declaration and definition.

## Complete single-file reference program

```cpp
#include <iostream>

int scale(int value, int factor = 2) { return value * factor; }

int main() {
    int value = 0;
    std::cin >> value;
    std::cout << scale(value) << ' ' << scale(value, 3) << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
