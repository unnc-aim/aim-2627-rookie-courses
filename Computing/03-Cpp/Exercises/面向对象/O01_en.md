# O01 A first class

Lesson 2 · Section 2.1

## Problem

Define Robot with public id and greet(). Create id=7 and print Robot 7 through greet.

## Sample input

```text
(no input)
```

## Sample output

```text
Robot 7
```

## Step-by-step reasoning

Define the type, create an instance, set its id, and let the method read that object’s field.

## Rules and boundaries

A class defines a type; an instance supplies a concrete object.

## Complete single-file reference program

```cpp
#include <iostream>

class Robot {
  public:
    int id = 0;
    void greet() const { std::cout << "Robot " << id << '\n'; }
};

int main() {
    Robot robot;
    robot.id = 7;
    robot.greet();
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
