# O10 A non-default-constructible member

Lesson 2 · Chapter 05 · Constructing and initializing Band

## Problem

Robot owns Motor, whose only constructor takes an id. Initialize that member in Robot(4) and print its id.

## Sample input

```text
(no input)
```

## Sample output

```text
4
```

## Step-by-step reasoning

Construct `motor_` directly in Robot’s initializer list rather than assuming a default Motor exists.

## Rules and boundaries

Members are constructed before the outer constructor body; later assignment cannot replace missing initialization.

## Complete single-file reference program

```cpp
#include <iostream>

class Motor {
    int id_;

  public:
    explicit Motor(int id) : id_(id) {}
    int id() const { return id_; }
};
class Robot {
    Motor motor_;

  public:
    explicit Robot(int id) : motor_(id) {}
    int motor_id() const { return motor_.id(); }
};

int main() {
    Robot r(4);
    std::cout << r.motor_id() << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
