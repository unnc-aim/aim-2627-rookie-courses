# O05 struct and class defaults

Lesson 2 · Chapter 04 · From struct to the Band class

## Problem

Define struct Point and class Hidden with an int x each. Read Point directly and Hidden through a getter; both print 3.

## Sample input

```text
(no input)
```

## Sample output

```text
3 3
```

## Step-by-step reasoning

Keep the default access distinction and use Hidden’s interface instead of exposing its field.

## Rules and boundaries

The main language differences are default member and inheritance access.

## Complete single-file reference program

```cpp
#include <iostream>

struct Point {
    int x = 3;
};
class Hidden {
    int x = 3;

  public:
    int value() const { return x; }
};

int main() {
    Point p;
    Hidden h;
    std::cout << p.x << ' ' << h.value() << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
