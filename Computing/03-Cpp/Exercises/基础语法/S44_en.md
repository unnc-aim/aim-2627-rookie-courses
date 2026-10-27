# S44 Split comma-delimited fields

Lesson 1 · Chapter 07 · Searching, replacing, inserting, and erasing strings

## Problem

Read one line. Print each comma-delimited field in square brackets on its own line. Preserve leading, trailing, and adjacent empty fields.

## Sample input

```text
a,,b,
```

## Sample output

```text
[a]
[]
[b]
[]
```

## Step-by-step reasoning

Track the field start, find the next comma, and emit the final field even when it is empty.

## Rules and boundaries

After the final delimiter, emit the final field. An empty line represents one empty field.

## Complete single-file reference program

```cpp
#include <cstddef>
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::size_t begin = 0;
    while (true) {
        std::string::size_type end = s.find(',', begin);
        std::cout << '[' << s.substr(begin, end - begin) << "]\n";
        if (end == std::string::npos)
            break;
        begin = end + 1;
    }
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
