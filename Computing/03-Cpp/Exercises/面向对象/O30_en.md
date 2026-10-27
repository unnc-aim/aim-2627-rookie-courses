# O30 Name hiding and qualification

Lesson 2 · Chapter 07 · MofoBand: inheritance and base construction

## Problem

Base::name returns BASE and Derived has a nonvirtual name returning DERIVED. Call d.name and d.Base::name.

## Sample input

```text
(no input)
```

## Sample output

```text
DERIVED BASE
```

## Step-by-step reasoning

Select the derived member normally and explicitly qualify the base member for the second call.

## Rules and boundaries

Nonvirtual name hiding differs from virtual overriding and dynamic dispatch.

## Complete single-file reference program

```cpp
#include <iostream>
#include <string>

struct Base {
    std::string name() const { return "BASE"; }
};
struct Derived : Base {
    std::string name() const { return "DERIVED"; }
};

int main() {
    Derived d;
    std::cout << d.name() << ' ' << d.Base::name() << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
