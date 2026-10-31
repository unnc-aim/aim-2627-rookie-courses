# O36 Transfer unique ownership

Lesson 2 · Section 2.8

## Problem

Create an owned integer 7, move ownership from a to b, and print whether a is empty and the value owned by b.

## Sample input

```text
(no input)
```

## Sample output

```text
true 7
```

## Step-by-step reasoning

Retain one owner after moving and test, rather than dereference, the empty source pointer.

## Rules and boundaries

unique_ptr cannot be copied and is guaranteed empty after moving from it. Do not generalize that guarantee to every type.

## Complete single-file reference program

```cpp
#include <iostream>
#include <memory>
#include <utility>

// std::unique_ptr and std::move come from the standard library.

int main() {
    std::unique_ptr<int> a = std::make_unique<int>(7);
    std::unique_ptr<int> b = std::move(a);
    std::cout << std::boolalpha << (a == nullptr) << ' ' << *b << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
