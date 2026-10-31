# S31 Print a rectangle

Lesson 1 · Section 1.4

## Problem

Read row count r and column count c in [1,10]. Print r rows of c hash characters.

## Sample input

```text
2 3
```

## Sample output

```text
###
###
```

## Step-by-step reasoning

Print hashes in the inner loop and a newline after it; the outer loop controls the number of rows.

## Rules and boundaries

The inner loop prints one row; the newline belongs outside it.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    int r = 0, c = 0;
    std::cin >> r >> c;
    for (int y = 0; y < r; ++y) {
        for (int x = 0; x < c; ++x)
            std::cout << '#';
        std::cout << '\n';
    }
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
