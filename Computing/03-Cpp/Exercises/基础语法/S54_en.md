# S54 Local scope

Lesson 1 · Section 1.8

## Problem

Set outer x=1 and inner-block x=2. Print the inner value and then the outer value.

## Sample input

```text
(no input)
```

## Sample output

```text
2
1
```

## Step-by-step reasoning

The inner x is a new object; leaving the block reveals the outer x again.

## Rules and boundaries

The inner declaration shadows the outer name and ends with its scope.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    int x = 1;
    {
        int x = 2;
        std::cout << x << '\n';
    }
    std::cout << x << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
