# O38 Cleanup during exceptions

Lesson 2 · Section 2.8

## Problem

Guard prints ACQUIRE in construction and RELEASE in destruction. Throw runtime_error in its scope and print CAUGHT from an outer handler.

## Sample input

```text
(no input)
```

## Sample output

```text
ACQUIRE
RELEASE
CAUGHT
```

## Step-by-step reasoning

Construct the guard, throw, destroy it during unwinding, then print from the handler.

## Rules and boundaries

Exception unwinding destroys fully constructed automatic objects, illustrating RAII.

## Complete single-file reference program

```cpp
#include <iostream>
#include <stdexcept>

struct Guard {
    Guard() { std::cout << "ACQUIRE\n"; }
    ~Guard() { std::cout << "RELEASE\n"; }
};

int main() {
    try {
        Guard guard;
        throw std::runtime_error("demo");
    } catch (const std::runtime_error &) {
        std::cout << "CAUGHT\n";
    }
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
