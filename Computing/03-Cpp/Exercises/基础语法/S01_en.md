# S01 Hello and exit status

Lesson 1 · Section 1.1

## Problem

Print AIM and C++17 on separate lines, then exit successfully.

## Sample input

```text
(no input)
```

## Sample output

```text
AIM
C++17
```

## Step-by-step reasoning

Use one main; terminate both output lines with newlines. The return value sets process status rather than printing another line.

## Rules and boundaries

Return 0 indicates success. Use a newline escape to end each line.

## Complete single-file reference program

```cpp
#include <iostream>

int main() {
    std::cout << "AIM\nC++17\n";
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
