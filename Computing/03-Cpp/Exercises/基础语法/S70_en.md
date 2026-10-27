# S70 Fixed-window means

Lesson 1 · Chapter 08 · Lesson 1 integration and a preview of structures

## Problem

Read n>=k>=1 and n integers, with n<=1000 and magnitudes at most 1000. Print the mean of every length-k window with two decimal places.

## Sample input

```text
3 2 1 3 5
```

## Sample output

```text
2.00
4.00
```

## Step-by-step reasoning

Add the new item, remove the departing item, and begin output once k items have been seen.

## Rules and boundaries

Add the entering value and remove the leaving value for O(n) total work.

## Complete single-file reference program

```cpp
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    int n = 0, k = 0;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int &x : a)
        std::cin >> x;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (i >= k)
            sum -= a[i - k];
        if (i >= k - 1)
            std::cout << std::fixed << std::setprecision(2)
                      << static_cast<double>(sum) / k << '\n';
    }
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
