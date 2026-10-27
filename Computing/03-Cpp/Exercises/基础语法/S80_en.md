# S80 An integrated unit report

Lesson 1 · Chapter 08 · Lesson 1 integration and a preview of structures

## Problem

Read n<=1000 unique id,hp records. Clamp hp to [0,100], print id:hp in ascending id order, then ALIVE=<living count>.

## Sample input

```text
2 7 120 2 -5
```

## Sample output

```text
2:0
7:100
ALIVE=1
```

## Step-by-step reasoning

Normalize health while reading, count living units from that value, then sort and print.

## Rules and boundaries

Use the same normalized health for display and classification.

## Complete single-file reference program

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

struct Unit {
    int id = 0;
    int hp = 0;
};

int main() {
    int n = 0, alive = 0;
    std::cin >> n;
    std::vector<Unit> units(n);
    for (Unit & u : units) {
        std::cin >> u.id >> u.hp;
        u.hp = std::clamp(u.hp, 0, 100);
        alive += u.hp > 0;
    }
    std::sort(units.begin(), units.end(),
              [](const Unit &a, const Unit &b) { return a.id < b.id; });
    for (const Unit & u : units)
        std::cout << u.id << ':' << u.hp << '\n';
    std::cout << "ALIVE=" << alive << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
