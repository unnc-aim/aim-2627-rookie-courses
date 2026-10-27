# O14 Copies and read-only views

Lesson 2 · Chapter 06 · Instances, methods, and a collection of bands

## Problem

Buffer wraps a vector. copy() returns a value and view() a const reference. Set the copy’s first item to 9 and print the view and copy first items.

## Sample input

```text
(no input)
```

## Sample output

```text
1 9
```

## Step-by-step reasoning

Modify only the independent copy; the view still observes the owner’s original value.

## Rules and boundaries

A returned reference avoids copying but cannot outlive its owner.

## Complete single-file reference program

```cpp
#include <iostream>
#include <vector>

class Buffer {
    std::vector<int> values_ = {1, 2};

  public:
    std::vector<int> copy() const { return values_; }
    const std::vector<int> &view() const { return values_; }
};

int main() {
    Buffer b;
    std::vector<int> c = b.copy();
    c[0] = 9;
    std::cout << b.view()[0] << ' ' << c[0] << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
