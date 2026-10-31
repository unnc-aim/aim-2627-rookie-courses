# O07 A const data member

Lesson 2 · Section 2.2

## Problem

Sensor has const int `id_`. Initialize it with 7 in construction and print it through a getter.

## Sample input

```text
(no input)
```

## Sample output

```text
7
```

## Step-by-step reasoning

Initialize `id_` after the constructor’s colon rather than assigning to a const member in the body.

## Rules and boundaries

A const member needs initialization before the constructor body.

## Complete single-file reference program

```cpp
#include <iostream>

class Sensor {
    const int id_;

  public:
    explicit Sensor(int id) : id_(id) {}
    int id() const { return id_; }
};

int main() {
    Sensor s(7);
    std::cout << s.id() << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
