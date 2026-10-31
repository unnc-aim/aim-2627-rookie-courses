# O21 Compose two motors

Lesson 2 · Section 2.4

## Problem

Chassis owns left and right Motor objects. drive(2,3) updates them; print their speeds.

## Sample input

```text
(no input)
```

## Sample output

```text
2 3
```

## Step-by-step reasoning

Keep left and right states in separate member objects and coordinate them through the chassis interface.

## Rules and boundaries

Composition models ownership of a part, with member lifetimes managed by the containing object.

## Complete single-file reference program

```cpp
#include <iostream>

struct Motor {
    int speed = 0;
    void set(int v) { speed = v; }
};
class Chassis {
    Motor left_, right_;

  public:
    void drive(int l, int r) {
        left_.set(l);
        right_.set(r);
    }
    void print() const { std::cout << left_.speed << ' ' << right_.speed << '\n'; }
};

int main() {
    Chassis c;
    c.drive(2, 3);
    c.print();
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
