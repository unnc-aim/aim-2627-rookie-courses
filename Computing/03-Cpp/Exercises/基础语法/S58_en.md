# S58 Swap through references

Lesson 2 · Chapter 03 · Understanding parameter passing through swapping

## Problem

Implement swap_ref with int& parameters, read two integers, and print them after swapping.

## Sample input

```text
10 20
```

## Sample output

```text
20 10
```

## Step-by-step reasoning

Save the original a, assign b to a, and write the saved value into b.

## Rules and boundaries

A reference aliases an existing object and normally binds at initialization without later rebinding.

## Complete single-file reference program

```cpp
#include <iostream>

void swap_ref(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int a = 0, b = 0;
    std::cin >> a >> b;
    swap_ref(a, b);
    std::cout << a << ' ' << b << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
