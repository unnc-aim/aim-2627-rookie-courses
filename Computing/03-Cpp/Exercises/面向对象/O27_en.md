# O27 Initialize the base

Lesson 2 · Section 2.6

## Problem

Robot requires an id. Sentry initializes its base from an id; construct 9 and print it.

## Sample input

```text
(no input)
```

## Sample output

```text
9
```

## Step-by-step reasoning

Pass the identifier to Robot in the initializer list rather than trying to initialize the base in the body.

## Rules and boundaries

A base subobject is initialized before derived members and the constructor body.

## Complete single-file reference program

```cpp
#include <iostream>

class Robot {
    int id_;

  public:
    explicit Robot(int id) : id_(id) {}
    int id() const { return id_; }
};
class Sentry : public Robot {
  public:
    explicit Sentry(int id) : Robot(id) {}
};

int main() {
    Sentry s(9);
    std::cout << s.id() << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
