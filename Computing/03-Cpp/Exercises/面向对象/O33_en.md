# O33 Object slicing

Lesson 2 · Section 2.7

## Problem

Derived::kind returns DERIVED and Base::kind BASE. Copy Derived into a Base value and compare with a base reference.

## Sample input

```text
(no input)
```

## Sample output

```text
BASE DERIVED
```

## Step-by-step reasoning

Compare a sliced base copy with a reference to the original derived object.

## Rules and boundaries

Copying into a base value discards the derived part, whereas a reference retains object identity.

## Complete single-file reference program

```cpp
#include <iostream>
#include <string>

struct Base {
    virtual ~Base() = default;
    virtual std::string kind() const { return "BASE"; }
};
struct Derived : Base {
    std::string kind() const override { return "DERIVED"; }
};

int main() {
    Derived d;
    Base value = d;
    const Base &ref = d;
    std::cout << value.kind() << ' ' << ref.kind() << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
