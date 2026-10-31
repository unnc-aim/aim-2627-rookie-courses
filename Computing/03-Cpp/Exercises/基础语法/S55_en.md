# S55 Recursive factorial

Lesson 1 · Section 1.8

## Problem

Read n in [0,20]. Compute n! recursively with an unsigned long long result.

## Sample input

```text
5
```

## Sample output

```text
120
```

## Step-by-step reasoning

Return one for n<=1 and otherwise multiply n by the smaller recursive result.

## Rules and boundaries

Define a base case first. The upper bound keeps the result representable.

## Complete single-file reference program

```cpp
#include <iostream>

unsigned long long factorial(int n) {
    return n <= 1 ? 1ULL : static_cast<unsigned long long>(n) * factorial(n - 1);
}

int main() {
    int n = 0;
    std::cin >> n;
    std::cout << factorial(n) << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
