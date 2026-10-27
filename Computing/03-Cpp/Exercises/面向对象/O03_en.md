# O03 A private speed boundary

Lesson 2 · Chapter 04 · From struct to the Band class

## Problem

Motor has private `speed_`. set_speed clamps to [-3,3] and speed() reads it. Request 9 and -9 and print the results.

## Sample input

```text
(no input)
```

## Sample output

```text
3
-3
```

## Step-by-step reasoning

Keep clamping inside the class and inspect the two boundary results through the getter.

## Rules and boundaries

Encapsulation routes state changes through a single constraint-enforcing interface.

## Complete single-file reference program

```cpp
#include <algorithm>
#include <iostream>

class Motor {
    int speed_ = 0;

  public:
    void set_speed(int v) { speed_ = std::clamp(v, -3, 3); }
    int speed() const { return speed_; }
};

int main() {
    Motor m;
    m.set_speed(9);
    std::cout << m.speed() << '\n';
    m.set_speed(-9);
    std::cout << m.speed() << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
