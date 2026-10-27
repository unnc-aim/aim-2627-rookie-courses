# O19 Store objects in a vector

Lesson 2 · Chapter 06 · Instances, methods, and a collection of bands

## Problem

Unit takes an id. emplace_back units 2 and 7, then print ids through const references.

## Sample input

```text
(no input)
```

## Sample output

```text
2
7
```

## Step-by-step reasoning

Finish both insertions before iterating, without growing the vector during observation.

## Rules and boundaries

Growth may invalidate element references and pointers; avoid retaining long-lived element addresses.

## Complete single-file reference program

```cpp
#include <iostream>
#include <vector>

class Unit {
    int id_;

  public:
    explicit Unit(int id) : id_(id) {}
    int id() const { return id_; }
};

int main() {
    std::vector<Unit> units;
    units.emplace_back(2);
    units.emplace_back(7);
    for (const Unit & u : units)
        std::cout << u.id() << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
