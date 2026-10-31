# S67 Scoped direction enumeration

Lesson 1 · Section 1.11

## Problem

Use enum class with UP=0,RIGHT=1,DOWN=2,LEFT=3. Read 0..3, turn right, and print the new integer code.

## Sample input

```text
3
```

## Sample output

```text
0
```

## Step-by-step reasoning

Add one modulo four, then explicitly convert the enum back to an integer.

## Rules and boundaries

enum class does not implicitly convert to int. A cast itself does not validate input.

## Complete single-file reference program

```cpp
#include <iostream>

enum class Facing { Up, Right, Down, Left };

int main() {
    int raw = 0;
    std::cin >> raw;
    Facing facing = static_cast<Facing>(raw);
    facing = static_cast<Facing>((static_cast<int>(facing) + 1) % 4);
    std::cout << static_cast<int>(facing) << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
