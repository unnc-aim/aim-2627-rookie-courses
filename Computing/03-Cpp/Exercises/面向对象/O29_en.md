# O29 Base and derived lifetimes

Lesson 2 · Chapter 07 · MofoBand: inheritance and base construction

## Problem

Base and Derived constructors print +B,+D; destructors print -D,-B. Create one Derived to verify order.

## Sample input

```text
(no input)
```

## Sample output

```text
+B
+D
-D
-B
```

## Step-by-step reasoning

Trace base-first construction and reverse destruction for a local object without dynamic allocation.

## Rules and boundaries

Construct the base first and destroy it last. This example does not delete through a base pointer.

## Complete single-file reference program

```cpp
#include <iostream>

struct Base {
    Base() { std::cout << "+B\n"; }
    ~Base() { std::cout << "-B\n"; }
};
struct Derived : Base {
    Derived() { std::cout << "+D\n"; }
    ~Derived() { std::cout << "-D\n"; }
};

int main() {
    Derived d;
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
