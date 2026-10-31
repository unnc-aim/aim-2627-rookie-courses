# S59 Read and write through a pointer

Lesson 1 · Section 1.10

## Problem

Set x=5, point to it, change the target to 9, and print x and whether the pointer equals &x.

## Sample input

```text
(no input)
```

## Sample output

```text
9 true
```

## Step-by-step reasoning

Store &x in the pointer, write through `*p`, and compare addresses rather than fixed hexadecimal text.

## Rules and boundaries

Actual addresses vary, so compare address equality rather than requiring a fixed address string.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    int x = 5;
    int *p = &x;
    *p = 9;
    std::cout << x << ' ' << std::boolalpha << (p == &x) << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
