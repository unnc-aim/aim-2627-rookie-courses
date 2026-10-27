# S29 Enumerate factors

Lesson 1 · Chapter 05 · Conditions and for loops

## Problem

Read n in [1,1000]. Print its positive factors in increasing order, one per line.

## Sample input

```text
6
```

## Sample output

```text
1
2
3
6
```

## Step-by-step reasoning

Scan candidates from 1 through n and output those with zero remainder, preserving increasing order.

## Rules and boundaries

An O(n) scan is sufficient for this range; square-root enumeration is an extension.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    for (int d = 1; d <= n; ++d) {
        if (n % d == 0)
            std::cout << d << '\n';
    }
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
