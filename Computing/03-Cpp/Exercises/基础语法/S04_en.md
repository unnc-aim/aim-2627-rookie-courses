# S04 Read a name containing spaces

Lesson 1 · Chapter 03 · Input, variables, and output formatting

## Problem

Read one complete line and print the original text inside square brackets.

## Sample input

```text
AIM Sentry 07
```

## Sample output

```text
[AIM Sentry 07]
```

## Step-by-step reasoning

Read the whole line into a string rather than only its first word, then surround it with brackets.

## Rules and boundaries

getline preserves spaces within a line and consumes its terminating newline.

## Complete single-file reference program

```cpp
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::getline(std::cin, name);
    std::cout << '[' << name << "]\n";
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
