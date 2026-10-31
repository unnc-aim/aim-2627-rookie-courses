# O24 A value snapshot

Lesson 2 · Section 2.4

## Problem

Robot::snapshot returns State by value. Set the snapshot x to 99; the original remains 3.

## Sample input

```text
(no input)
```

## Sample output

```text
3 99
```

## Step-by-step reasoning

Modify the returned value and observe it separately from the original object.

## Rules and boundaries

A value snapshot separates external observation from internal mutation.

## Complete single-file reference program

```cpp
#include <iostream>

struct State {
    int x = 0;
};
class Robot {
    State state_ = {3};

  public:
    State snapshot() const { return state_; }
};

int main() {
    Robot r;
    State state = r.snapshot();
    state.x = 99;
    std::cout << r.snapshot().x << ' ' << state.x << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
