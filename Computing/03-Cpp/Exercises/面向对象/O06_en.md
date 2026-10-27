# O06 Member initializer list

Lesson 2 · Chapter 05 · Constructing and initializing Band

## Problem

Battery takes capacity and initial charge. Capacity is at least 1 and charge clamps to [0,capacity]. Construct (10,20) and print charge.

## Sample input

```text
(no input)
```

## Sample output

```text
10
```

## Step-by-step reasoning

Normalize capacity first, then bound charge using the already-initialized capacity.

## Rules and boundaries

Members initialize in declaration order, regardless of initializer-list order.

## Complete single-file reference program

```cpp
#include <algorithm>
#include <iostream>

class Battery {
    int capacity_;
    int charge_;

  public:
    Battery(int capacity, int initial)
        : capacity_(std::max(1, capacity)),
          charge_(std::clamp(initial, 0, capacity_)) {}
    int charge() const { return charge_; }
};

int main() {
    Battery b(10, 20);
    std::cout << b.charge() << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
