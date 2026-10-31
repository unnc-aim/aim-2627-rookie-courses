# O28 Protected access

Lesson 2 · Section 2.6

## Problem

Base has protected hp=10. Derived::damage subtracts 3. Read seven through a public getter.

## Sample input

```text
(no input)
```

## Sample output

```text
7
```

## Step-by-step reasoning

Let the derived method perform the permitted mutation and let main use the public reader.

## Rules and boundaries

The declaring class and permitted derived members can access protected data; ordinary external callers cannot.

## Complete single-file reference program

```cpp
#include <iostream>

class Base {
  protected:
    int hp_ = 10;

  public:
    int hp() const { return hp_; }
};
class Derived : public Base {
  public:
    void damage() { hp_ -= 3; }
};

int main() {
    Derived d;
    d.damage();
    std::cout << d.hp() << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
