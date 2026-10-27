# S02 Output with multiple fields

Lesson 1 · Chapter 02 · Namespaces and first output

## Problem

Print identifier 7 and name Sentry exactly as id=7 name=Sentry.

## Sample input

```text
(no input)
```

## Sample output

```text
id=7 name=Sentry
```

## Step-by-step reasoning

Store an integer id and a string name, then insert the literal prefixes, values, and separating space into one stream.

## Rules and boundaries

Use single quotes for character literals and double quotes for string literals.

## Complete single-file reference program

```cpp
#include <iostream>
#include <string>

int main() {
    int id = 7;
    std::string name("Sentry");
    std::cout << "id=" << id << " name=" << name << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
