# S45 Uppercase ASCII letters

Lesson 1 · Section 1.6

## Problem

Read one ASCII line and change only a..z to A..Z.

## Sample input

```text
aim-07
```

## Sample output

```text
AIM-07
```

## Step-by-step reasoning

Visit each character by reference and modify only lowercase ASCII letters.

## Rules and boundaries

This rule is limited to ASCII and does not provide general multilingual case conversion.

## Complete single-file reference program

```cpp
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    for (char &c : s)
        if (c >= 'a' && c <= 'z')
            c = char(c - 'a' + 'A');
    std::cout << s << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
