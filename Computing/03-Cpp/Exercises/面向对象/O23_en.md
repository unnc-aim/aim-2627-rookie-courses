# O23 Inject a configuration

Lesson 2 · Chapter 09 · Original-course integration and engineering extensions

## Problem

Policy contains max_speed. Controller copies it and clamps requests. Compare policies 2 and 5 for request 4.

## Sample input

```text
(no input)
```

## Sample output

```text
2 4
```

## Step-by-step reasoning

Apply the same request through each object’s independent configuration rather than a shared overwritten global limit.

## Rules and boundaries

Pass varying configuration explicitly rather than relying on global state. max_speed is nonnegative.

## Complete single-file reference program

```cpp
#include <algorithm>
#include <iostream>

struct Policy {
    int max_speed = 1;
};
class Controller {
    Policy policy_;

  public:
    explicit Controller(Policy p) : policy_(p) {}
    int command(int v) const {
        return std::clamp(v, -policy_.max_speed, policy_.max_speed);
    }
};

int main() {
    Controller a(Policy{2}), b(Policy{5});
    std::cout << a.command(4) << ' ' << b.command(4) << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
