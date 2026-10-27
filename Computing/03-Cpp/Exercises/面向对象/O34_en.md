# O34 A virtual destructor

Lesson 2 · Chapter 09 · Original-course integration and engineering extensions

## Problem

Let `unique_ptr<Base>` own Derived. Derived’s destructor prints D and Base’s prints B.

## Sample input

```text
(no input)
```

## Sample output

```text
D
B
```

## Step-by-step reasoning

Let scope exit destroy the owned object, invoking derived destruction before base destruction.

## Rules and boundaries

A base destructor must be virtual when derived objects are destroyed through that base ownership interface.

## Complete single-file reference program

```cpp
#include <iostream>
#include <memory>

struct Base {
    virtual ~Base() { std::cout << "B\n"; }
};
struct Derived : Base {
    ~Derived() override { std::cout << "D\n"; }
};

int main() {
    std::unique_ptr<Base> p = std::make_unique<Derived>();
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
