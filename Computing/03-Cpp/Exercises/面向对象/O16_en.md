# O16 Copy an object by value

Lesson 2 · Section 2.3

## Problem

Robot owns vector {1,2}. Copy a into b, set b’s first item to 9, then print both first items.

## Sample input

```text
(no input)
```

## Sample output

```text
1 9
```

## Step-by-step reasoning

Default member copying duplicates vector values, so changing b does not modify a.

## Rules and boundaries

Standard container members give independent element values with default copying.

## Complete single-file reference program

```cpp
#include <iostream>
#include <vector>

struct Robot {
    std::vector<int> values = {1, 2};
};

int main() {
    Robot a;
    Robot b = a;
    b.values[0] = 9;
    std::cout << a.values[0] << ' ' << b.values[0] << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
