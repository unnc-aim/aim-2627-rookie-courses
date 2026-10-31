# O15 A static member function

Lesson 2 · Section 2.3

## Problem

Limits::valid checks [-3,3] without an object. Test speeds 3 and 4.

## Sample input

```text
(no input)
```

## Sample output

```text
1 0
```

## Step-by-step reasoning

Call through the class name and compute solely from the argument without an unnecessary instance.

## Rules and boundaries

A static member function has no this and cannot directly read per-object state.

## Complete single-file reference program

```cpp
#include <iostream>

class Limits {
  public:
    static bool valid(int speed) { return speed >= -3 && speed <= 3; }
};

int main() {
    std::cout << Limits::valid(3) << ' ' << Limits::valid(4) << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
