# S64 A non-owning pointer range

Lesson 1 · Section 1.10

## Problem

sum_span(p,n) sums n elements. p may be nullptr when n=0. Demonstrate a three-element array and an empty range.

## Sample input

```text
(no input)
```

## Sample output

```text
12 0
```

## Step-by-step reasoning

The empty range performs no dereference; nonempty ranges visit indexes 0 through n-1.

## Rules and boundaries

A pointer carries no length. For n>0 the caller must provide n valid elements.

## Complete single-file reference program

```cpp
#include <cstddef>
#include <iostream>

long long sum_span(const int *p, std::size_t n) {
    long long total = 0;
    for (std::size_t i = 0; i < n; ++i)
        total += p[i];
    return total;
}

int main() {
    int a[] = {2, 4, 6};
    std::cout << sum_span(a, 3) << ' ' << sum_span(nullptr, 0) << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
