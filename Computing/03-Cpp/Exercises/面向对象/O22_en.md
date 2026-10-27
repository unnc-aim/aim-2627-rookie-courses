# O22 Compose a battery and movement

Lesson 2 · Chapter 09 · Original-course integration and engineering extensions

## Problem

Robot owns a Battery initially charged to two. Each successful step consumes one and increments x. Call three times and print x and remaining charge.

## Sample input

```text
(no input)
```

## Sample output

```text
2 0
```

## Step-by-step reasoning

The first two steps consume and move; the third has insufficient energy and changes neither value.

## Rules and boundaries

Resource consumption and movement belong to one action; failure must not partly update state.

## Complete single-file reference program

```cpp
#include <iostream>

class Battery {
    int charge_ = 2;

  public:
    bool consume() {
        if (!charge_)
            return false;
        --charge_;
        return true;
    }
    int charge() const { return charge_; }
};
class Robot {
    Battery battery_;
    int x_ = 0;

  public:
    void step() {
        if (battery_.consume())
            ++x_;
    }
    void print() const { std::cout << x_ << ' ' << battery_.charge() << '\n'; }
};

int main() {
    Robot r;
    r.step();
    r.step();
    r.step();
    r.print();
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
