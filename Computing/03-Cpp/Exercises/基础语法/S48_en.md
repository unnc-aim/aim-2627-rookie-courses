# S48 Palindrome text

Lesson 1 · Section 1.6

## Problem

Read one ASCII line and test it byte by byte for a palindrome. An empty string is a palindrome. Print YES or NO.

## Sample input

```text
level
```

## Sample output

```text
YES
```

## Step-by-step reasoning

Compare symmetric positions from the first half and reject any mismatched pair.

## Rules and boundaries

Inspect only the first half. Empty input never evaluates size()-1 inside the loop.

## Complete single-file reference program

```cpp
#include <cstddef>
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    bool yes = true;
    for (std::size_t i = 0; i < s.size() / 2; ++i)
        if (s[i] != s[s.size() - 1 - i])
            yes = false;
    std::cout << (yes ? "YES" : "NO") << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
