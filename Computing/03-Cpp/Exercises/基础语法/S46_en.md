# S46 Count whitespace-delimited words

Lesson 1 · Section 1.7

## Problem

Read one line and print the number of whitespace-delimited words.

## Sample input

```text
  AIM   Sentry  07
```

## Sample output

```text
3
```

## Step-by-step reasoning

Count successful word extractions rather than counting individual spaces.

## Rules and boundaries

istringstream extraction naturally skips repeated whitespace.

## Complete single-file reference program

```cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line, word;
    std::getline(std::cin, line);
    std::istringstream stream(line);
    int count = 0;
    while (stream >> word)
        ++count;
    std::cout << count << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
