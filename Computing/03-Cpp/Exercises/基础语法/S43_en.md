# S43 Replace the first match safely

Lesson 1 · Section 1.6

## Problem

Read a line. Replace the first anon with saki, leaving the line unchanged if anon is absent.

## Sample input

```text
soyo,anon,taki
```

## Sample output

```text
soyo,saki,taki
```

## Step-by-step reasoning

Replace only the first match, with no repeated-replacement loop, and leave absent matches unchanged.

## Rules and boundaries

Check find before replace; passing npos directly can throw.

## Complete single-file reference program

```cpp
#include <iostream>
#include <string>

int main() {
    std::string text;
    std::getline(std::cin, text);
    std::string::size_type pos = text.find("anon");
    if (pos != std::string::npos)
        text.replace(pos, 4, "saki");
    std::cout << text << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
