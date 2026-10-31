# S42 Find a substring

Lesson 1 · Section 1.6

## Problem

Read a line of text and then a line containing a search key. Print the first match position or -1 if absent.

## Sample input

```text
AIM Sentry
Sentry
```

## Sample output

```text
4
```

## Step-by-step reasoning

Preserve the search result type and distinguish npos from a valid zero-based position.

## Rules and boundaries

npos is a special size_type value. Check it before narrowing to an integer.

## Complete single-file reference program

```cpp
#include <iostream>
#include <string>

int main() {
    std::string text, key;
    std::getline(std::cin, text);
    std::getline(std::cin, key);
    std::string::size_type pos = text.find(key);
    if (pos == std::string::npos)
        std::cout << -1 << '\n';
    else
        std::cout << pos << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
