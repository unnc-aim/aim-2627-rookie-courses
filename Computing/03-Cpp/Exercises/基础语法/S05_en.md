# S05 Read a line after a number

Lesson 1 · Chapter 03 · Input, variables, and output formatting

## Problem

Read an identifier, then a full name on the next line. Names may contain spaces but have no significant leading spaces. Print id:name.

## Sample input

```text
7
AIM Sentry
```

## Sample output

```text
7:AIM Sentry
```

## Step-by-step reasoning

Extract the integer, consume the remaining leading whitespace, then read the complete name.

## Rules and boundaries

std::ws consumes all leading whitespace. If empty names are meaningful, use a selective ignore followed by getline instead.

## Complete single-file reference program

```cpp
#include <iostream>
#include <string>

int main() {
    int id = 0;
    std::string name;
    std::cin >> id;
    std::getline(std::cin >> std::ws, name);
    std::cout << id << ':' << name << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
