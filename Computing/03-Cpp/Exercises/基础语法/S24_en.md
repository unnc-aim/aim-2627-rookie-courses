# S24 Priority in safety decisions

Lesson 1 · Chapter 05 · Conditions and for loops

## Problem

Read stop, hp, and enemy. Select the first applicable action in the order STOP, DEAD, TRACK, PATROL. stop and enemy are 0 or 1.

## Sample input

```text
1 0 1
```

## Sample output

```text
STOP
```

## Step-by-step reasoning

When several conditions hold, return only the highest-priority action through an exclusive chain.

## Rules and boundaries

Use an exclusive branch chain so multiple matches respect the required priority.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    int stop = 0, hp = 0, enemy = 0;
    std::cin >> stop >> hp >> enemy;
    if (stop)
        std::cout << "STOP\n";
    else if (hp <= 0)
        std::cout << "DEAD\n";
    else if (enemy)
        std::cout << "TRACK\n";
    else
        std::cout << "PATROL\n";
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
