# S63 Return by value to avoid dangling

Lesson 2 · Chapter 02 · References, addresses, and pointers

## Problem

Return a locally created vector {1,2,3} by value. Print its size and first element in the caller.

## Sample input

```text
(no input)
```

## Sample output

```text
3 1
```

## Step-by-step reasoning

Return the container as a value so the caller owns a valid result rather than referring to a destroyed local.

## Rules and boundaries

Do not return a reference or pointer to a local. Value returns can benefit from copy elision or movement.

## Complete single-file reference program

```cpp
#include <iostream>
#include <vector>

std::vector<int> make_values() { return {1, 2, 3}; }

int main() {
    std::vector<int> values = make_values();
    std::cout << values.size() << ' ' << values.front() << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
