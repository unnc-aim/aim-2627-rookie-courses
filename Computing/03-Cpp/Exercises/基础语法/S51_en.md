# S51 A clamping function

Lesson 2 · Chapter 01 · Functions: arguments, computation, and return

## Problem

Implement clamp_speed(v,limit). Read v and a nonnegative limit and return the value clamped to [-limit,limit].

## Sample input

```text
8 3
```

## Sample output

```text
3
```

## Step-by-step reasoning

Apply an upper and lower bound while preserving requests already inside the interval.

## Rules and boundaries

A pure calculation function isolates boundaries from input and output.

## Complete single-file reference program

```cpp
#include <algorithm>
#include <iostream>

int clamp_speed(int v, int limit) { return std::max(-limit, std::min(v, limit)); }

int main() {
    int v = 0, limit = 0;
    std::cin >> v >> limit;
    std::cout << clamp_speed(v, limit) << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
