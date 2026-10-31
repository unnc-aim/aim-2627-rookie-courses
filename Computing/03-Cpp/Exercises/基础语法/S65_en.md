# S65 A telemetry structure

Lesson 1 · Section 1.11

## Problem

Define Frame(id,hp,speed). Read the fields and print id:hp:speed with speed formatted to one decimal place.

## Sample input

```text
7 80 1.5
```

## Sample output

```text
7:80:1.5
```

## Step-by-step reasoning

Read all fields into one Frame and print them with explicit separators.

## Rules and boundaries

A struct groups related fields and defaults to public member access.

## Complete single-file reference program

```cpp
#include <iomanip>
#include <iostream>

struct Frame {
    int id = 0;
    int hp = 0;
    double speed = 0.0;
};

int main() {
    Frame frame = {};
    std::cin >> frame.id >> frame.hp >> frame.speed;
    std::cout << frame.id << ':' << frame.hp << ':' << std::fixed
              << std::setprecision(1) << frame.speed << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
