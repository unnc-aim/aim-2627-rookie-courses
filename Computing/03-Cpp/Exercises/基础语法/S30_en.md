# S30 Primality test

Lesson 1 · Chapter 05 · Conditions and for loops

## Problem

Read an integer in [0,10^9]. Print YES if prime, otherwise NO.

## Sample input

```text
97
```

## Sample output

```text
YES
```

## Step-by-step reasoning

Exclude values below two, then search for a divisor up to the square root and stop at the first factor.

## Rules and boundaries

Use d<=n/d to avoid d*d overflow. Zero and one are not prime.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    bool prime = n >= 2;
    for (int d = 2; prime && d <= n / d; ++d) {
        if (n % d == 0)
            prime = false;
    }
    std::cout << (prime ? "YES" : "NO") << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
