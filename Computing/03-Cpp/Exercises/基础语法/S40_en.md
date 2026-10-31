# S40 Rotate right

Lesson 1 · Section 1.5

## Problem

Read n>=1, k>=0, and n integers, where n<=1000 and k<=10^9. Rotate right by k positions and print one value per line.

## Sample input

```text
3 4 1 2 3
```

## Sample output

```text
3
1
2
```

## Step-by-step reasoning

Move element i to (i+k)%n after reducing k modulo n.

## Rules and boundaries

Reduce k modulo n and use separate result storage to avoid overwriting unread data.

## Complete single-file reference program

```cpp
#include <iostream>
#include <vector>

int main() {
    int n = 0, k = 0;
    std::cin >> n >> k;
    std::vector<int> a(n), b(n);
    for (int &x : a)
        std::cin >> x;
    k %= n;
    for (int i = 0; i < n; ++i)
        b[(i + k) % n] = a[i];
    for (int x : b)
        std::cout << x << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
