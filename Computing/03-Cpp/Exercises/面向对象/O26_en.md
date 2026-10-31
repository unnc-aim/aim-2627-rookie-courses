# O26 Public inheritance

Lesson 2 · Section 2.6

## Problem

Robot provides id 7. Sentry publicly derives from it and adds patrol. Print 7 and PATROL.

## Sample input

```text
(no input)
```

## Sample output

```text
7
PATROL
```

## Step-by-step reasoning

Call the inherited operation and then the added operation, identifying where each interface originates.

## Rules and boundaries

Public inheritance expresses a substitutable base relationship and exposes inherited public operations.

## Complete single-file reference program

```cpp
#include <iostream>

class Robot {
  public:
    int id() const { return 7; }
};
class Sentry : public Robot {
  public:
    void patrol() const { std::cout << "PATROL\n"; }
};

int main() {
    Sentry s;
    std::cout << s.id() << '\n';
    s.patrol();
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
