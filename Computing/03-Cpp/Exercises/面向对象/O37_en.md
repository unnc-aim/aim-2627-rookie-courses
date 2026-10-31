# O37 Rule of Zero

Lesson 2 · Section 2.5

## Problem

Log wraps `vector<string>`. Use default copying and destruction, add only to copy b, then compare sizes.

## Sample input

```text
(no input)
```

## Sample output

```text
1 2
```

## Step-by-step reasoning

Delegate storage to the container and keep each copied collection independent.

## Rules and boundaries

Prefer standard-library members for resource management over handwritten raw-pointer copying and destruction.

## Complete single-file reference program

```cpp
#include <cstddef>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Log {
    std::vector<std::string> data_;

  public:
    void add(std::string s) { data_.push_back(std::move(s)); }
    std::size_t size() const { return data_.size(); }
};

int main() {
    Log a;
    a.add("start");
    Log b = a;
    b.add("stop");
    std::cout << a.size() << ' ' << b.size() << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
