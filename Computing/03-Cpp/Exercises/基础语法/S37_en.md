# S37 Copy and modify a vector

Lesson 1 · Section 1.5

## Problem Copy(1,2,3) from a to b, set b[0]=9, and print a[0] and b[0].

## Sample input

```text
(no input)
```

## Sample output

```text
1 9
```

## Step-by-step reasoning

Copy first, change only b, and observe each object separately.

## Rules and boundaries

vector has value semantics; copies own independent element storage.

## Complete single-file reference program

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = a;
    b[0] = 9;
    std::cout << a[0] << ' ' << b[0] << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
