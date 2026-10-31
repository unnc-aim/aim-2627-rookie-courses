# S78 Dropped-frame alarms

Lesson 1 · Section 1.5

## Problem

Read n>=0 increasing timestamps, each at most 10^9. Print the later timestamp for each adjacent gap strictly greater than 10.

## Sample input

```text
4 0 10 25 26
```

## Sample output

```text
25
```

## Step-by-step reasoning

Use the first frame only to establish prev, then compare and update it for each later frame.

## Rules and boundaries

The first frame has no predecessor. A gap of exactly ten is not an alarm.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    long long prev = 0;
    for (int i = 0; i < n; ++i) {
        long long ts = 0;
        std::cin >> ts;
        if (i > 0 && ts - prev > 10)
            std::cout << ts << '\n';
        prev = ts;
    }
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
