# O40 Declare and define members separately

Lesson 2 · Chapter 09 · Original-course integration and engineering extensions

## Problem

Separate Motor declarations from member definitions. set clamps to [-3,3]; request 8 and print 3. A multi-file split is a local project extension only.

## Sample input

```text
(no input)
```

## Sample output

```text
3
```

## Step-by-step reasoning

Declare in the class and define with Motor:: outside it, keeping all parts in one platform source file.

## Rules and boundaries

Use Motor:: for out-of-class definitions. CPP-Classroom still receives one complete source file.

## Complete single-file reference program

```cpp
#include <algorithm>
#include <iostream>

class Motor {
    int speed_ = 0;

  public:
    void set(int v);
    int speed() const;
};
void Motor::set(int v) { speed_ = std::clamp(v, -3, 3); }
int Motor::speed() const { return speed_; }

int main() {
    Motor m;
    m.set(8);
    std::cout << m.speed() << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
