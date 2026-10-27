# O08 Delegating construction

Lesson 2 · Chapter 05 · Constructing and initializing Band

## Problem

Timer() defaults to 100 ms. Timer(int) keeps positive values and changes nonpositive ones to 1. Print default and Timer(0) intervals.

## Sample input

```text
(no input)
```

## Sample output

```text
100 1
```

## Step-by-step reasoning

Delegate the default constructor and centralize interval normalization in the parameterized constructor.

## Rules and boundaries

Delegating construction reuses another constructor’s initialization rules.

## Complete single-file reference program

```cpp
#include <algorithm>
#include <iostream>

class Timer {
    int interval_;

  public:
    Timer() : Timer(100) {}
    explicit Timer(int ms) : interval_(std::max(1, ms)) {}
    int interval() const { return interval_; }
};

int main() {
    Timer a;
    Timer b(0);
    std::cout << a.interval() << ' ' << b.interval() << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
