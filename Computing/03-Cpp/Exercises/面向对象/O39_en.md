# O39 A noncopyable device

Lesson 2 · Chapter 09 · Original-course integration and engineering extensions

## Problem

Device deletes copy construction and copy assignment but permits default construction and id()==7. Explain why copying should fail compilation.

## Sample input

```text
(no input)
```

## Sample output

```text
7
```

## Step-by-step reasoning

Use one device in the runnable example and test the forbidden copy in a separate compilation experiment.

## Rules and boundaries

=delete expresses an ownership restriction at compile time.

## Complete single-file reference program

```cpp
#include <iostream>

class Device {
  public:
    Device() = default;
    Device(const Device &) = delete;
    Device &operator=(const Device &) = delete;
    int id() const { return 7; }
};

int main() {
    Device d;
    std::cout << d.id() << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
