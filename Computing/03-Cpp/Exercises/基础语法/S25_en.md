# S25 Accumulate in a loop

Lesson 1 · Section 1.4

## Problem

Read n in [0,10000] and use a for loop to compute the sum from 1 through n.

## Sample input

```text
5
```

## Sample output

```text
15
```

## Step-by-step reasoning

Initialize the accumulator outside the loop and include both endpoints 1 and n.

## Rules and boundaries

For n=0, zero iterations leave the correct initial sum of zero.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    long long total = 0;
    for (int i = 1; i <= n; ++i)
        total += i;
    std::cout << total << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
