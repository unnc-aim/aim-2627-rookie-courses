# O13 Return a reference for chaining

Lesson 2 · Chapter 06 · Instances, methods, and a collection of bands

## Problem

Config setters return Config&. Chain speed=3 and id=7, then print id:speed.

## Sample input

```text
(no input)
```

## Sample output

```text
7:3
```

## Step-by-step reasoning

Return the same object by reference after each setter so the next call does not target a temporary copy.

## Rules and boundaries

Returning `*this` by reference keeps subsequent calls on the same object.

## Complete single-file reference program

```cpp
#include <iostream>

class Config {
    int speed_ = 0, id_ = 0;

  public:
    Config &set_speed(int v) {
        speed_ = v;
        return *this;
    }
    Config &set_id(int id) {
        id_ = id;
        return *this;
    }
    void print() const { std::cout << id_ << ':' << speed_ << '\n'; }
};

int main() {
    Config c;
    c.set_speed(3).set_id(7).print();
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
