# S77 Grid collisions

Lesson 1 · Section 1.6

## Problem

Read width w, height h, and UDLR commands. Start at (0,0); U increases y. An out-of-bounds move stays in place and increments collisions. w,h>=1. Print x,y,collisions.

## Sample input

```text
2 2 RRUU
```

## Sample output

```text
1 1 2
```

## Step-by-step reasoning

Keep candidate and current positions separate; a boundary collision increments the count without committing movement.

## Rules and boundaries

Compute a candidate location, validate it, then commit the position.

## Complete single-file reference program

```cpp
#include <iostream>
#include <string>

int main() {
    int w = 0, h = 0, x = 0, y = 0, collisions = 0;
    std::string commands;
    std::cin >> w >> h >> commands;
    for (char c : commands) {
        int nx = x + (c == 'R') - (c == 'L');
        int ny = y + (c == 'U') - (c == 'D');
        if (nx < 0 || nx >= w || ny < 0 || ny >= h)
            ++collisions;
        else {
            x = nx;
            y = ny;
        }
    }
    std::cout << x << ' ' << y << ' ' << collisions << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
