# S72 Sorting with tie-breaking

Lesson 1 · Chapter 08 · Lesson 1 integration and a preview of structures

## Problem

Read n<=1000 records id,score. Print identifiers in descending score order, breaking ties by ascending identifier.

## Sample input

```text
3 9 10 7 20 2 20
```

## Sample output

```text
2
7
9
```

## Step-by-step reasoning

Compare score first and use id only for ties, expressing both ordering levels explicitly.

## Rules and boundaries

A sorting comparator must be strict; use > or < rather than >=. A lambda defines the local comparison operation.

## Complete single-file reference program

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

struct Record {
    int id = 0;
    int score = 0;
};

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<Record> records(n);
    for (Record & r : records)
        std::cin >> r.id >> r.score;
    std::sort(records.begin(), records.end(), [](const Record &a, const Record &b) {
        if (a.score != b.score)
            return a.score > b.score;
        return a.id < b.id;
    });
    for (const Record & r : records)
        std::cout << r.id << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
