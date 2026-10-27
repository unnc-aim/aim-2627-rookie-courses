# S56 Boolean success and an output parameter

Lesson 2 · Chapter 01 · Functions: arguments, computation, and return

## Problem

Implement safe_divide(a,b,out). Return false without changing out when b=0; otherwise store the integer quotient. Inputs have magnitude at most 1000.

## Sample input

```text
5 0
```

## Sample output

```text
false 99
```

## Step-by-step reasoning

Reject zero first, then assign out only on success and return the status.

## Rules and boundaries

The failure path preserves the output argument; test that independently.

## Complete single-file reference program

```cpp
#include <iostream>

bool safe_divide(int a, int b, int &out) {
    if (b == 0)
        return false;
    out = a / b;
    return true;
}

int main() {
    int a = 0, b = 0, answer = 99;
    std::cin >> a >> b;
    bool ok = safe_divide(a, b, answer);
    std::cout << std::boolalpha << ok << ' ' << answer << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
