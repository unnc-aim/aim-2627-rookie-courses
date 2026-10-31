# S16 Ceiling division for nonnegative values

Lesson 1 · Section 1.2

## Problem

Read 0<=n<=10^9 and 1<=k<=10^9. Print the minimum number of boxes of capacity k needed for n items.

## Sample input

```text
11 5
```

## Sample output

```text
3
```

## Step-by-step reasoning

Use n/k full boxes, add one for a nonzero remainder, and keep n=0 at zero boxes.

## Rules and boundaries

A quotient plus a nonzero-remainder indicator avoids the addition in n+k-1.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    long long n = 0, k = 0;
    std::cin >> n >> k;
    std::cout << n / k + (n % k != 0) << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
