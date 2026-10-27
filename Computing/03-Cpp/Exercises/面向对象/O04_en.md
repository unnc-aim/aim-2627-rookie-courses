# O04 Reject an invalid mutation

Lesson 2 · Chapter 04 · From struct to the Band class

## Problem

Magazine starts at 5. reload(n) accepts n>=0 only if the total stays <=10; success returns true, failure changes nothing. Test +4 and +2.

## Sample input

```text
(no input)
```

## Sample output

```text
1 0 9
```

## Step-by-step reasoning

Reach nine after adding four, then reject the second request without a partial update.

## Rules and boundaries

Validate all conditions before committing the mutation.

## Complete single-file reference program

```cpp
#include <iostream>

class Magazine {
    int rounds_ = 5;

  public:
    bool reload(int n) {
        if (n < 0 || n > 10 - rounds_)
            return false;
        rounds_ += n;
        return true;
    }
    int rounds() const { return rounds_; }
};

int main() {
    Magazine m;
    std::cout << m.reload(4) << ' ' << m.reload(2) << ' ' << m.rounds() << '\n';
    return 0;
}
```

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
