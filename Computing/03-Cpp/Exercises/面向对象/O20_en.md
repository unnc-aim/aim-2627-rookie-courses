# O20 Count live objects

Lesson 2 · Section 2.5

## Problem

Tracker increments static live in default and copy construction and decrements it in destruction. Observe two in scope and zero afterward.

## Sample input

```text
(no input)
```

## Sample output

```text
2
0
```

## Step-by-step reasoning

Count both default and copy construction, then both destructions, returning to zero.

## Rules and boundaries

Copy construction also creates an object. This example counts instances rather than managing a resource.

## Complete single-file reference program

```cpp
#include <iostream>

class Tracker {
  public:
    inline static int live = 0;
    Tracker() { ++live; }
    Tracker(const Tracker &) { ++live; }
    ~Tracker() { --live; }
};

int main() {
    {
        Tracker a;
        Tracker b = a;
        std::cout << Tracker::live << '\n';
    }
    std::cout << Tracker::live << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
