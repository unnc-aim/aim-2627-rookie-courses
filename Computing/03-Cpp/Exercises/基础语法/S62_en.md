# S62 Read-only reference traversal

Lesson 1 · Section 1.9

## Problem

Implement sum(const `vector<int>`&) without copying the vector. Read n<=1000 integers of magnitude at most 1000 and print their sum.

## Sample input

```text
3 1 2 3
```

## Sample output

```text
6
```

## Step-by-step reasoning

Borrow the vector read-only, accumulate in a local long long, and return the numeric result by value.

## Rules and boundaries

A const reference expresses a read-only borrow whose target must remain alive for the call.

## Complete single-file reference program

```cpp
#include <iostream>
#include <vector>

long long sum(const std::vector<int> &a) {
    long long result = 0;
    for (int x : a)
        result += x;
    return result;
}

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x : a)
        std::cin >> x;
    std::cout << sum(a) << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
