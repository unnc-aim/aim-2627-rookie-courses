# O18 Scope and destruction order

Lesson 2 · Section 2.5

## Problem

Tracer prints +name in construction and -name in destruction. Create outer a and inner b and predict all output.

## Sample input

```text
(no input)
```

## Sample output

```text
+a
+b
-b
-a
```

## Step-by-step reasoning

Place b’s destruction at the inner scope exit and a’s at main’s end to derive all four output lines.

## Rules and boundaries

Automatic objects die on scope exit, in reverse order of completed construction within a scope.

## Complete single-file reference program

```cpp
#include <iostream>
#include <string>
#include <utility>

class Tracer {
    std::string name_;

  public:
    explicit Tracer(std::string name) : name_(std::move(name)) {
        std::cout << '+' << name_ << '\n';
    }
    ~Tracer() { std::cout << '-' << name_ << '\n'; }
};

int main() {
    Tracer a("a");
    {
        Tracer b("b");
    }
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
