# S35 Append to a vector

Lesson 1 · Chapter 06 · Arrays, std::array, and range iteration

## Problem

Read integers until EOF, store them in a vector, and print them in reverse order, one per line.

## Sample input

```text
1 2 3
```

## Sample output

```text
3
2
1
```

## Step-by-step reasoning

Append successful readings, then count down from size while accessing i-1.

## Rules and boundaries

size_t is unsigned. Count down with i>0 and access i-1 to avoid underflow.

## Complete single-file reference program

```cpp
#include <cstddef>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> a;
    int value = 0;
    while (std::cin >> value)
        a.push_back(value);
    for (std::size_t i = a.size(); i > 0; --i)
        std::cout << a[i - 1] << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
