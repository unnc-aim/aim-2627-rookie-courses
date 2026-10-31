# O17 Object parameters by value and reference

Lesson 2 · Section 2.3

## Problem

Counter starts at zero. touch_copy increments a value parameter and touch_ref increments a reference parameter. Call both and print the original.

## Sample input

```text
(no input)
```

## Sample output

```text
1
```

## Step-by-step reasoning

The first call changes a parameter copy and the second changes the original, giving one net increment.

## Rules and boundaries

Parameter types specify whether the caller’s object may be modified.

## Complete single-file reference program

```cpp
#include <iostream>

struct Counter {
    int value = 0;
};
void touch_copy(Counter c) { ++c.value; }
void touch_ref(Counter &c) { ++c.value; }

int main() {
    Counter c;
    touch_copy(c);
    touch_ref(c);
    std::cout << c.value << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
