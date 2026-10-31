# S36 Validate an index

Lesson 1 · Section 1.5

## Problem

For the fixed array {10,20,30}, read a signed index. Print the selected element or INVALID.

## Sample input

```text
-1
```

## Sample output

```text
INVALID
```

## Step-by-step reasoning

Reject negative indexes and indexes at or beyond the length before accessing the element.

## Rules and boundaries

Check negativity before conversion to an unsigned type. [] does not provide bounds checking; at does.

## Complete single-file reference program

```cpp
#include <array>
#include <iostream>

int main() {
    std::array<int, 3> a = {10, 20, 30};
    int index = 0;
    std::cin >> index;
    if (index < 0 || index >= static_cast<int>(a.size()))
        std::cout << "INVALID\n";
    else
        std::cout << a.at(index) << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
