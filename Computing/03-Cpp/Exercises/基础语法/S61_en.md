# S61 Pointer to const

Lesson 2 · Chapter 02 · References, addresses, and pointers

## Problem

Set a=3 and b=7. Let const `int*` p point to a and then b, printing the pointed value each time.

## Sample input

```text
(no input)
```

## Sample output

```text
3
7
```

## Step-by-step reasoning

Redirection changes p’s stored address; the two observations read different unchanged target objects.

## Rules and boundaries

const `int*` can be redirected but cannot modify its target through that pointer. `int* const` fixes the pointer itself.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    int a = 3, b = 7;
    const int *p = &a;
    std::cout << *p << '\n';
    p = &b;
    std::cout << *p << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
