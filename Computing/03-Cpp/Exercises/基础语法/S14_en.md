# S14 Distance from the origin

Lesson 1 · Section 1.2

## Problem

Read x and y and print their Euclidean distance from the origin with two decimal places.

## Sample input

```text
3 4
```

## Sample output

```text
5.00
```

## Step-by-step reasoning

Read two doubles and call hypot(x,y) without prematurely converting the distance to an integer.

## Rules and boundaries

hypot expresses the distance and avoids some intermediate overflow issues of naive squaring.

## Complete single-file reference program

```cpp
#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    double x = 0.0, y = 0.0;
    std::cin >> x >> y;
    std::cout << std::fixed << std::setprecision(2) << std::hypot(x, y) << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
