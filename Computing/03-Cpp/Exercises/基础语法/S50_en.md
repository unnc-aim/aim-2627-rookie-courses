# S50 Declaration and definition

Lesson 2 · Chapter 01 · Functions: arguments, computation, and return

## Problem

Declare square before main and provide its definition. Read x in [-1000,1000] and print its square.

## Sample input

```text
5
```

## Sample output

```text
25
```

## Step-by-step reasoning

Match the name, parameters, and return type between declaration and definition, then call from main.

## Rules and boundaries

The call needs a declaration, and linking needs a matching definition.

## Complete single-file reference program

```cpp
#include <iostream>

int square(int x);
int square(int x) { return x * x; }

int main() {
    int x = 0;
    std::cin >> x;
    std::cout << square(x) << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
