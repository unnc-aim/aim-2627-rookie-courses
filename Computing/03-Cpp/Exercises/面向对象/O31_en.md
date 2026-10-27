# O31 Virtual dispatch

Lesson 2 · Chapter 09 · Original-course integration and engineering extensions

## Problem

Base::kind is virtual and returns BASE. Derived overrides it with SENTRY. Call through const Base&.

## Sample input

```text
(no input)
```

## Sample output

```text
SENTRY
```

## Step-by-step reasoning

The reference does not copy a base value, so the call uses the original object’s dynamic type.

## Rules and boundaries

A base reference or pointer preserves access to dynamic dispatch.

## Complete single-file reference program

```cpp
#include <iostream>
#include <string>

struct Base {
    virtual ~Base() = default;
    virtual std::string kind() const { return "BASE"; }
};
struct Derived : Base {
    std::string kind() const override { return "SENTRY"; }
};

int main() {
    Derived d;
    const Base &ref = d;
    std::cout << ref.kind() << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
