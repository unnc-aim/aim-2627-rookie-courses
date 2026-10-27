# S79 Debug a loop endpoint

Lesson 1 · Chapter 08 · Lesson 1 integration and a preview of structures

## Problem

Fix the old sum loop for(i=0;i<=n;++i). Read n<=1000 valid integers and print their sum.

## Sample input

```text
3 1 2 3
```

## Sample output

```text
6
```

## Step-by-step reasoning

Use i<n to read exactly n values and avoid a spurious final extraction.

## Rules and boundaries

The <= endpoint reads one extra value. Compare iteration count with the input size and valid index range.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        int value = 0;
        std::cin >> value;
        sum += value;
    }
    std::cout << sum << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
