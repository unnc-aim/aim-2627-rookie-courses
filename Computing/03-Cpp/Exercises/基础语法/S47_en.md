# S47 Parse one integer strictly

Lesson 1 · Section 1.7

## Problem

Read a line allowing surrounding whitespace and exactly one int. Print INVALID for overflow or trailing non-whitespace data.

## Sample input

```text
12abc
```

## Sample output

```text
INVALID
```

## Step-by-step reasoning

Require integer extraction to succeed and a subsequent extra-character extraction to fail.

## Rules and boundaries

Checking only the first extraction incorrectly accepts prefixes such as 12 in 12abc.

## Complete single-file reference program

```cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream stream(line);
    int value = 0;
    char extra = '\0';
    if ((stream >> value) && !(stream >> extra))
        std::cout << value << '\n';
    else
        std::cout << "INVALID\n";
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
