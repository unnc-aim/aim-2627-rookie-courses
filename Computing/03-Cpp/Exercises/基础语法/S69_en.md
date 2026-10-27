# S69 Update a 2D position

Lesson 1 · Chapter 08 · Lesson 1 integration and a preview of structures

## Problem

Read a word containing UDLR. Start at (0,0); U increases y and R increases x. Print the final position.

## Sample input

```text
UURDLR
```

## Sample output

```text
1 1
```

## Step-by-step reasoning

Each command changes one coordinate by one unit, accumulated in input order.

## Rules and boundaries

State the coordinate convention; screen coordinates often use a different y direction.

## Complete single-file reference program

```cpp
#include <iostream>
#include <string>

int main() {
    std::string commands;
    std::cin >> commands;
    int x = 0, y = 0;
    for (char c : commands) {
        if (c == 'U')
            ++y;
        else if (c == 'D')
            --y;
        else if (c == 'L')
            --x;
        else if (c == 'R')
            ++x;
    }
    std::cout << x << ' ' << y << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
