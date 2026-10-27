# O02 Independent object state

Lesson 2 · Chapter 04 · From struct to the Band class

## Problem

Create two Counters. Tick only the first twice, then print both values.

## Sample input

```text
(no input)
```

## Sample output

```text
2 0
```

## Step-by-step reasoning

Each object owns its `count_`; both ticks target a, leaving b unchanged.

## Rules and boundaries

Ordinary nonstatic data members belong to individual objects.

## Complete single-file reference program

```cpp
#include <iostream>

class Counter {
    int count_ = 0;

  public:
    void tick() { ++count_; }
    int value() const { return count_; }
};

int main() {
    Counter a, b;
    a.tick();
    a.tick();
    std::cout << a.value() << ' ' << b.value() << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
