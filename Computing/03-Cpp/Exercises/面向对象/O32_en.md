# O32 A pure virtual interface

Lesson 2 · Section 2.7

## Problem

Define abstract Sensor::read() const. FixedSensor returns 42. print_sensor accepts const Sensor& and prints read().

## Sample input

```text
(no input)
```

## Sample output

```text
42
```

## Step-by-step reasoning

Instantiate the concrete derived class and observe it through the common abstract interface.

## Rules and boundaries

A class with an unimplemented pure virtual operation is abstract and cannot be instantiated.

## Complete single-file reference program

```cpp
#include <iostream>

struct Sensor {
    virtual ~Sensor() = default;
    virtual int read() const = 0;
};
struct FixedSensor : Sensor {
    int read() const override { return 42; }
};
void print_sensor(const Sensor &s) { std::cout << s.read() << '\n'; }

int main() {
    FixedSensor s;
    print_sensor(s);
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
