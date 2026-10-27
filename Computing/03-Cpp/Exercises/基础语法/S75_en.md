# S75 A restricted command interpreter

Lesson 1 · Chapter 08 · Lesson 1 integration and a preview of structures

## Problem

Read lines containing ADD integer or RESET. Apply only exact valid formats and ignore other lines. Print the final accumulator. Values and line counts have magnitude at most 1000.

## Sample input

```text
ADD 5
BAD 9
RESET
ADD 3
```

## Sample output

```text
3
```

## Step-by-step reasoning

Parse the operation and argument and reject trailing data before updating state.

## Rules and boundaries

Validate a whole line before changing state so malformed input cannot partially apply.

## Complete single-file reference program

```cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;
    long long value = 0;
    while (std::getline(std::cin, line)) {
        std::istringstream in(line);
        std::string op, extra;
        int x = 0;
        if (!(in >> op))
            continue;
        if (op == "ADD" && (in >> x) && !(in >> extra))
            value += x;
        else if (op == "RESET" && !(in >> extra))
            value = 0;
    }
    std::cout << value << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
