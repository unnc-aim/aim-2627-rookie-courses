# S21 Dispatch with switch

Lesson 1 · Chapter 05 · Conditions and for loops

## Problem

Read F, L, or R and print FORWARD, LEFT, or RIGHT. Print UNKNOWN for any other character.

## Sample input

```text
L
```

## Sample output

```text
LEFT
```

## Step-by-step reasoning

Use one case per valid character, terminate each with break, and handle other characters in default.

## Rules and boundaries

break ends a switch branch; omission may cause fall-through.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    char op = '\0';
    std::cin >> op;
    switch (op) {
    case 'F':
        std::cout << "FORWARD\n";
        break;
    case 'L':
        std::cout << "LEFT\n";
        break;
    case 'R':
        std::cout << "RIGHT\n";
        break;
    default:
        std::cout << "UNKNOWN\n";
    }
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
