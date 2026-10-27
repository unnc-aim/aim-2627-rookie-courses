# S07 Resolve namespace collisions

Lesson 1 · Chapter 02 · Namespaces and first output

## Problem

aim::speed is 3 and sim::speed is 8. Print both without a using-namespace directive.

## Sample input

```text
(no input)
```

## Sample output

```text
3 8
```

## Step-by-step reasoning

Keep the same spelling in two namespaces and select each variable through its namespace prefix.

## Rules and boundaries

Qualified names identify the intended declaration. Avoid broad using directives in public headers.

## Complete single-file reference program

```cpp
#include <iostream>

namespace aim {
int speed = 3;
}
namespace sim {
int speed = 8;
}

int main() {
    std::cout << aim::speed << ' ' << sim::speed << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
