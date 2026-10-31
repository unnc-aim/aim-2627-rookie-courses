# O11 A const member function

Lesson 2 · Section 2.3

## Problem

Counter has value() const and tick(). Read const Counter(8); it cannot call tick.

## Sample input

```text
(no input)
```

## Sample output

```text
8
```

## Step-by-step reasoning

Use only observational methods on the const object and treat mutation as a separate compilation-failure experiment.

## Rules and boundaries

A trailing const restricts modification of ordinary members through that invocation.

## Complete single-file reference program

```cpp
#include <iostream>

class Counter {
    int value_;

  public:
    explicit Counter(int n) : value_(n) {}
    int value() const { return value_; }
    void tick() { ++value_; }
};

int main() {
    const Counter c(8);
    std::cout << c.value() << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
