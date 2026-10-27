# O25 Collect diagnostic messages

Lesson 2 · Chapter 09 · Original-course integration and engineering extensions

## Problem

Diagnostics saves nonempty messages and reports one per line. Add OK, an empty string, and LOW.

## Sample input

```text
(no input)
```

## Sample output

```text
OK
LOW
```

## Step-by-step reasoning

Filter empty messages at insertion and retain the others in order; reporting does not mutate the collection.

## Rules and boundaries

Standard container members can provide a clear responsibility without an inheritance hierarchy.

## Complete single-file reference program

```cpp
#include <iostream>
#include <string>
#include <vector>

class Diagnostics {
    std::vector<std::string> messages_;

  public:
    void add(const std::string &s) {
        if (!s.empty())
            messages_.push_back(s);
    }
    void report() const {
        for (const std::string & s : messages_)
            std::cout << s << '\n';
    }
};

int main() {
    Diagnostics d;
    d.add("OK");
    d.add("");
    d.add("LOW");
    d.report();
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
