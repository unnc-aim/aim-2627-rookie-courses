# S66 Select the nearest target

Lesson 1 · Chapter 08 · Lesson 1 integration and a preview of structures

## Problem

Read n>=1 target records id,x,y, with n<=1000 and coordinates of magnitude at most 1000. Choose the minimum squared distance, breaking ties by smaller id.

## Sample input

```text
3 9 3 4 2 -3 -4 7 6 0
```

## Sample output

```text
2
```

## Step-by-step reasoning

Compare squared distance first, then id on a tie, and retain the whole best record.

## Rules and boundaries

Compare squared distances without square roots and encode the tie rule explicitly.

## Complete single-file reference program

```cpp
#include <iostream>
#include <limits>

struct Target {
    int id = 0;
    int x = 0;
    int y = 0;
};

int main() {
    int n = 0;
    std::cin >> n;
    Target best = {};
    long long best_d = std::numeric_limits<long long>::max();
    for (int i = 0; i < n; ++i) {
        Target t = {};
        std::cin >> t.id >> t.x >> t.y;
        long long d = 1LL * t.x * t.x + 1LL * t.y * t.y;
        if (d < best_d || (d == best_d && t.id < best.id)) {
            best = t;
            best_d = d;
        }
    }
    std::cout << best.id << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
