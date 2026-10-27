# S71 Deduplicate timestamps

Lesson 1 · Chapter 08 · Lesson 1 integration and a preview of structures

## Problem

Read n timestamp-value records with timestamps in [0,100]. Retain the first record for each timestamp and print retained records in input order.

## Sample input

```text
3 2 10 2 99 1 7
```

## Sample output

```text
2 10
1 7
```

## Step-by-step reasoning

Initialize seen to false, mark and output the first occurrence, and ignore later duplicates.

## Rules and boundaries

A boolean array supports constant-time membership checks for this finite key range.

## Complete single-file reference program

```cpp
#include <array>
#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    std::array<bool, 101> seen = {};
    for (int i = 0; i < n; ++i) {
        int ts = 0, value = 0;
        std::cin >> ts >> value;
        if (!seen[ts]) {
            seen[ts] = true;
            std::cout << ts << ' ' << value << '\n';
        }
    }
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
