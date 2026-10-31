# S53 Function overloading

Lesson 1 · Section 1.8

## Problem

Overload label(int) and label(double) to return INT and DOUBLE. Print label(3) and label(3.0).

## Sample input

```text
(no input)
```

## Sample output

```text
INT DOUBLE
```

## Step-by-step reasoning

Identify each literal’s type before selecting its matching overload.

## Rules and boundaries

Argument types choose overloads; return-type differences alone cannot distinguish overloads.

## Complete single-file reference program

```cpp
#include <iostream>
#include <string>

std::string label(int) { return "INT"; }
std::string label(double) { return "DOUBLE"; }

int main() {
    std::cout << label(3) << ' ' << label(3.0) << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
