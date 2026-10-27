# O09 Prevent implicit conversion

Lesson 2 · Chapter 05 · Constructing and initializing Band

## Problem

Distance has an explicit meters constructor. Create Distance(3) and pass it to print_distance(const Distance&).

## Sample input

```text
(no input)
```

## Sample output

```text
3
```

## Step-by-step reasoning

Compare explicit construction with the invalid implicit call while retaining only the valid form in runnable code.

## Rules and boundaries

With explicit, print_distance(3) is rejected; construct the argument deliberately.

## Complete single-file reference program

```cpp
#include <iostream>

class Distance {
    int meters_;

  public:
    explicit Distance(int m) : meters_(m) {}
    int meters() const { return meters_; }
};
void print_distance(const Distance &d) { std::cout << d.meters() << '\n'; }

int main() {
    print_distance(Distance(3));
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
