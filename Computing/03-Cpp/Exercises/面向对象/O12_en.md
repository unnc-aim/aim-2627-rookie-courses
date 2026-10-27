# O12 this and a shadowed parameter

Lesson 2 · Chapter 06 · Instances, methods, and a collection of bands

## Problem

Pose::set_x(int x) uses this->x=x. Set five and read it back.

## Sample input

```text
(no input)
```

## Sample output

```text
5
```

## Step-by-step reasoning

Read the parameter on the right and select the current object’s member with this on the left.

## Rules and boundaries

this identifies the current object; member naming conventions can also avoid shadowing.

## Complete single-file reference program

```cpp
#include <iostream>

class Pose {
    int x = 0;

  public:
    void set_x(int x) { this->x = x; }
    int get_x() const { return x; }
};

int main() {
    Pose p;
    p.set_x(5);
    std::cout << p.get_x() << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
