# S41 String length and endpoints

Lesson 1 · Section 1.6

## Problem

Read one line of ASCII text. Print its length and, if nonempty, its first and last characters. An empty line prints only zero.

## Sample input

```text
robot
```

## Sample output

```text
5
r t
```

## Step-by-step reasoning

Print the length first and call front and back only for a nonempty string.

## Rules and boundaries

string size counts char units; UTF-8 byte length is not a Chinese character count.

## Complete single-file reference program

```cpp
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::cout << s.size() << '\n';
    if (!s.empty())
        std::cout << s.front() << ' ' << s.back() << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
