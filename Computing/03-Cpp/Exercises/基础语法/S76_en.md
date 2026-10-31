# S76 Heat simulation

Lesson 1 · Section 1.4

## Problem

Read n, initial heat h, cooling c, shot heat d, and n binary requests. Each step cools to at least zero, then fires only if requested and h+d<=100. Print shots and final heat. Nonnegative parameters are at most 100 and n<=1000.

## Sample input

```text
3 90 10 20 1 1 1
```

## Sample output

```text
2 100
```

## Step-by-step reasoning

Cool before checking each shot. The sample ends at heat 100, not its intermediate heat 90.

## Rules and boundaries

Operation order is part of the contract. Firing before cooling changes boundary behavior.

## Complete single-file reference program

```cpp
#include <algorithm>
#include <iostream>

int main() {
    int n = 0, h = 0, cool = 0, delta = 0, shots = 0;
    std::cin >> n >> h >> cool >> delta;
    for (int i = 0; i < n; ++i) {
        int fire = 0;
        std::cin >> fire;
        h = std::max(0, h - cool);
        if (fire && h + delta <= 100) {
            h += delta;
            ++shots;
        }
    }
    std::cout << shots << ' ' << h << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
