# S74 Run-length encoding

Lesson 1 · Chapter 08 · Lesson 1 integration and a preview of structures

## Problem

Read one ASCII line. Print each consecutive run as character:count on its own line. Empty input produces no output.

## Sample input

```text
aaabbc
```

## Sample output

```text
a:3
b:2
c:1
```

## Step-by-step reasoning

Fix a run start i, advance j to the first different character, emit j-i, and continue from j.

## Rules and boundaries

At the inner loop’s end, the half-open interval [i,j) contains exactly one run.

## Complete single-file reference program

```cpp
#include <cstddef>
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    for (std::size_t i = 0; i < s.size();) {
        std::size_t j = i + 1;
        while (j < s.size() && s[j] == s[i])
            ++j;
        std::cout << s[i] << ':' << j - i << '\n';
        i = j;
    }
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
