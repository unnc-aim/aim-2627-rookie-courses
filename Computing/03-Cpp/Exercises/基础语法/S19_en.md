# S19 Firing gate

Lesson 1 · Section 1.3

## Problem

Read hp, heat, and enemy, where enemy is 0 or 1. Print FIRE only when hp>0, heat<100, and enemy=1; otherwise WAIT.

## Sample input

```text
100 100 1
```

## Sample output

```text
WAIT
```

## Step-by-step reasoning

Combine the three conditions into one bool and verify that heat=100 requires waiting.

## Rules and boundaries

Each operand of && is a condition, and evaluation short-circuits from left to right.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    int hp = 0, heat = 0, enemy = 0;
    std::cin >> hp >> heat >> enemy;
    bool fire = hp > 0 && heat < 100 && enemy == 1;
    std::cout << (fire ? "FIRE" : "WAIT") << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
