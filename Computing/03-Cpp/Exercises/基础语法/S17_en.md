# S17 Three health categories

Lesson 1 · Chapter 05 · Conditions and for loops

## Problem

Read hp in [0,100]. Print DEAD for 0, LOW for 1..30, and OK otherwise.

## Sample input

```text
30
```

## Sample output

```text
LOW
```

## Step-by-step reasoning

Handle zero first, then values at most 30. The remaining branch already implies the upper range.

## Rules and boundaries

Check the special case before the broader range; test 0 and 30 explicitly.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    int hp = 0;
    std::cin >> hp;
    if (hp == 0)
        std::cout << "DEAD\n";
    else if (hp <= 30)
        std::cout << "LOW\n";
    else
        std::cout << "OK\n";
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
