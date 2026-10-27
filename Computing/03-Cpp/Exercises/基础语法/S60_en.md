# S60 Guard a null pointer

Lesson 2 · Chapter 02 · References, addresses, and pointers

## Problem

safe_increment accepts a possibly-null `int*`. Increment the target only when non-null. Call with nullptr and then &x, where x=7, and print x.

## Sample input

```text
(no input)
```

## Sample output

```text
8
```

## Step-by-step reasoning

Make the null call a no-op and increment exactly once for a valid address.

## Rules and boundaries

Dereferencing a null pointer is invalid; perform the check first.

## Complete single-file reference program

```cpp
#include <iostream>

void safe_increment(int *p) {
    if (p != nullptr)
        ++*p;
}

int main() {
    int x = 7;
    safe_increment(nullptr);
    safe_increment(&x);
    std::cout << x << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
