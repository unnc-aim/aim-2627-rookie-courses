---
marp: true
theme: aim-classroom
paginate: true
size: 16:9
---

<!-- _class: cover -->

## C++ Fundamentals

Lesson 1 / Input, decisions, and data

<!--
Ask who has run Hello World locally. Explain the predict, run, explain, change routine. Examples contains full programs. The screen shows only the current focus.
Suggested time: 1 min
-->

---

<!-- _class: statement -->

## Our program for today

```text
Input: 3 scores
Compute: sum and average
Decide: average at least 60?
Print: the report
```

How would you write this in Python?

<!--
Ask for a verbal Python solution. Put input, storage, loop, and condition on the board. Revisit them through the lesson.
Suggested time: 3 min
-->

---

<!-- _class: code -->

## One complete program

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, C++!\n";
    return 0;
}
```

Execution enters main. Statements end with a semicolon.

<!--
Run first, then point out the header, main, braces, and semicolon. return 0 is an exit status, not printed output. Later snippets omit the unchanged wrapper. Always run the complete file.
Full demo: Examples/L1_C01_D01.cpp
Suggested time: 2 min
-->

---

<!-- _class: code -->

## Python and C++ notation

```cpp
// Python: score = 85
int score = 85;

// Python: if score >= 60:
if (score >= 60) {
    std::cout << "pass\n";
}
```

The type precedes the name. Braces delimit a block.

<!--
Compare declaration, condition parentheses, braces, and semicolons. Indentation still helps readability but does not define C++ blocks. Connect the wrapper to program structure.
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Blocks and variable scope

```cpp
int score = 85;
{
    int bonus = 5;
    score += bonus;
}
std::cout << score << '\n';
// bonus is no longer in scope here
```

Inner code can use outer names. A local name ends with its block.

<!--
Trace score from 85 to 90. Attempt to print bonus outside the block. Distinguish name scope from object lifetime, which end together for this simple local variable.
Suggested time: 3 min
-->

---

<!-- _class: question -->

## Compilation and execution

```cpp
std::cout << "Hello\n"
```

A semicolon is missing. Will this version print Hello?

<!--
Wait at least ten seconds, then remove the semicolon in the full demo. Compilation fails, so this source version does not run. Read the first diagnostic and repair it before running again.
Full demo: Examples/L1_C01_D01.cpp
Suggested time: 3 min
-->

---

<!-- _class: statement -->

## The first compiler diagnostic

Read the file and line number  
Inspect that line and the line before it  
Fix the first cause, then compile again

<!--
Demonstrate a missing semicolon reported on the following line. The reported location is where the compiler notices the problem. Have a student read one diagnostic.
Suggested time: 2 min
-->

---

<!-- _class: code -->

## std:: qualifies a name

```cpp
std::cout << "AIM\n";

using std::cout;
cout << "AIM\n";
```

Both forms name the same standard library object.

<!--
Explain namespaces as a way to distinguish names. Use std:: in class and show using for recognition. Use the demo for name conflicts without adding a header-splitting detour.
Full demo: Examples/L1_C02_D01.cpp
Suggested time: 2 min
-->

---

<!-- _class: code -->

## Output order

```cpp
int score = 85;
std::cout << "score=" << score << '\n';
```

What appears on screen?

<!--
Elicit score=85. Quotes are not printed and variables contribute their values. Mention that endl also flushes the stream. Use \n for ordinary newlines.
Full demo: Examples/L1_C02_D02.cpp
Suggested time: 2 min
-->

---

<!-- _class: section -->

## Input and types

First decide what each value represents

<!--
Introduce the next problem and give students a moment to switch context.
Suggested time: 1 min
-->

---

<!-- _class: code -->

## Variable types

```cpp
int count = 3;
double average = 82.5;
char grade = 'A';
std::string name("anon");
bool passed = true;
```

Integer / fraction / character / string / condition

<!--
Ask what each type can represent. string requires the string header. Contrast single quotes for char with double quotes for strings. bool prints 0 or 1 by default. boolalpha prints true or false.
Full demo: Examples/L1_C03_D02.cpp
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Initialization and later assignment

```cpp
int count = 3;  // initialization
count = 5;      // assignment

double measured = 3.5;
int truncated = static_cast<int>(measured);
```

Initialization creates an object. Assignment changes an existing one.  
An explicit conversion may still discard a fractional part.

<!--
truncated is 3. Compare initialization and assignment. An explicit conversion expresses intent but can still lose information. Test -3.5 to observe truncation toward zero.
Suggested time: 2 min
-->

---

<!-- _class: code -->

## Types determine representable values

```cpp
int whole = 85;
double fraction = 85.5;

std::cout << sizeof(whole) << '\n';
std::cout << sizeof(fraction) << '\n';
```

Integers have bounds. Floating values have limited precision.  
Type sizes depend on the implementation.

<!--
Common systems use 4-byte int and 8-byte double, but the language does not guarantee those sizes. Signed overflow cannot be assumed to wrap. Introduce numeric_limits as a reference.
Suggested time: 2 min
-->

---

<!-- _class: code -->

## Input follows extraction order

```cpp
int a = 0, b = 0;
std::cin >> a >> b;
std::cout << a - b << '\n';
```

Input 8 4. What is printed? What if they are on separate lines?

<!--
Prefill 8 4 and observe 4. Separate lines also give 4. Whitespace separates these integers. Try 8,4 and explain that a comma is not automatically accepted as a separator.
Full demo: Examples/L1_C03_D01.cpp
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Token extraction and line input

```cpp
std::string first, second;
std::cin >> first >> second;
// Input: poppin party
// first = "poppin", second = "party"
```

>> reads whitespace-separated tokens. getline reads a line.

<!--
Run the two-token example, then use std::getline(std::cin,line). Mixing extraction and getline can leave a newline pending. std::ws can help when leading whitespace should be skipped.
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Failed input

```cpp
int score = 0;
if (!(std::cin >> score)) {
    std::cout << "invalid input\n";
    return 1;
}
```

Where does execution go for input abc?

<!--
Demonstrate inside main. Elicit the plain-language meaning: exit if reading an integer fails. Revisit if and ! later. Do not treat score as a valid result after failure.
Suggested time: 2 min
-->

---

<!-- _class: practice -->

## Practice: read and print

Read a name and a score  
Print anon:85  
Sample input: anon 85

<!--
Start from the Hello World wrapper with iostream and string. Check extraction order and quotes. After two minutes, ask a student to explain the types, then run their solution. Keep the answer off screen.
Suggested time: 5 min
-->

---

<!-- _class: code -->

## Read and print: review

```cpp
std::string name;
int score = 0;
std::cin >> name >> score;
std::cout << name << ':' << score << '\n';
```

Check types, extraction order, and output punctuation.

<!--
Reveal after students attempt the exercise. Ask why the colon is quoted. Discuss reversed input order and whether a name containing spaces fits this interface.
Suggested time: 2 min
-->

---

<!-- _class: section -->

## Operators and decisions

Predict a result, then explain the types

<!--
Introduce the next problem and give students a moment to switch context.
Suggested time: 1 min
-->

---

<!-- _class: question -->

## The value of 3 / 2

```cpp
std::cout << 3 / 2 << '\n';
std::cout << 3 / 2.0 << '\n';
std::cout << 3 % 2 << '\n';
```

What does each line print?

<!--
Elicit 1, 1.5, and 1. Integer division truncates toward zero. % gives an integer remainder. The example uses positive values. Mention truncation toward zero for negatives too.
Full demo: Examples/L1_C04_D01.cpp
Suggested time: 3 min
-->

---

<!-- _class: code -->

## When conversion happens

```cpp
int a = 3, b = 2;

double x = a / b;
double y = static_cast<double>(a) / b;
```

x is 1, y is 1.5  
The destination type does not redo the division.

<!--
Write the integer result 1 before its conversion to double. Converting a first gives the division a floating operand. Ask whether static_cast<double>(a/b) recovers the fraction. It does not.
Full demo: Examples/L1_C04_D01.cpp
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Tracing three division expressions

```cpp
3 / 2                         // 1
static_cast<double>(3) / 2     // 1.5
static_cast<double>(3 / 2)     // 1.0
```

Identify operand types, perform division, then convert the result.

<!--
Circle the subexpressions on the board. The final value is double 1. Default formatting may print 1 rather than 1.0. Separate numerical type from presentation.
Suggested time: 2 min
-->

---

<!-- _class: code -->

## Assignment and comparison

```cpp
int x = 10;
x = 3;

std::cout << (x == 3) << '\n';
std::cout << (x != 3) << '\n';
```

= changes a value. == tests equality.

<!--
Elicit x=3 and outputs 1 then 0. Explain that if(x=3) may compile while changing x. Successful compilation does not prove the intended behavior.
Full demo: Examples/L1_C04_D02.cpp
Suggested time: 2 min
-->

---

<!-- _class: code -->

## Compound conditions and short-circuiting

```cpp
if (total != 0 && score / total > 0.6) {
    std::cout << "pass\n";
}
```

If total is 0, is the right side evaluated?

<!--
Assume score and total are doubles. && skips the right side when the left is false. || skips it when the left is true. ! negates. Ask why reversing the conditions loses the zero-denominator guard.
Full demo: Examples/L1_C04_D03.cpp
Suggested time: 3 min
-->

---

<!-- _class: code -->

## AND, OR, and NOT

```cpp
true  && false   // false
true  || false   // true
!true            // false
!(score < 0 || score > 100)
```

The last expression means the score is in [0, 100].

<!--
Evaluate -1, 0, 100, and 101. Compare with score>=0 && score<=100. Explain both the logical relation and evaluation short-circuiting.
Suggested time: 2 min
-->

---

<!-- _class: code -->

## Updating a variable

```cpp
int count = 3;
++count;
count += 2;
count *= 3;
```

What is count after each line?

<!--
Pause after each line: 4, 6, 18. Keep ++ out of complex expressions. Mention cmath functions such as sqrt and abs as reference material rather than a catalog on screen.
Full demo: Examples/L1_C04_D04.cpp
Suggested time: 2 min
-->

---

<!-- _class: code -->

## Math functions and result types

```cpp
#include <cmath>

std::sqrt(9.0);   // 3.0
std::abs(-3);     // 3
std::floor(2.8);  // 2.0
std::ceil(2.1);   // 3.0
```

A call produces a value. Printing it still requires output.

<!--
Run each expression through cout. floor and ceil return rounded floating values, unlike conversion to int. For -2.8, floor gives -3 while truncation toward zero gives -2.
Suggested time: 2 min
-->

---

<!-- _class: code -->

## Mutually exclusive if branches

```cpp
if (score >= 90) {
    std::cout << "A\n";
} else if (score >= 60) {
    std::cout << "pass\n";
} else {
    std::cout << "retry\n";
}
```

For score=95, how many lines are printed?

<!--
Only A prints. Compare with two independent if statements. Run 95, 60, and 59. Explain why the higher threshold comes first.
Full demo: Examples/L1_C05_D01.cpp
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Branch order and boundary cases

```cpp
// Test cases for score:
// 59  -> retry
// 60  -> pass
// 89  -> pass
// 90  -> A
// 100 -> A
```

Testing both sides of each boundary catches more than testing only 80.

<!--
Move >=60 before >=90 and ask how 95 is classified. Trace then run the cases. If valid input is constrained to 0..100, validate that separately.
Suggested time: 2 min
-->

---

<!-- _class: practice -->

## Practice: average and pass check

Read 3 integer scores  
Print their average to 1 decimal place  
Print pass if the average is at least 60

<!--
Use iomanip with fixed and setprecision(1). Have students predict 59 60 60: 59.7 and no pass. Then test 60 60 60. Compare the numerical average before output formatting.
Suggested time: 7 min
-->

---

<!-- _class: code -->

## Average: calculation and formatting

```cpp
double average = (a + b + c) / 3.0;
std::cout << std::fixed
          << std::setprecision(1)
          << average << '\n';
if (average >= 60) {
    std::cout << "pass\n";
}
```

Displaying 1 decimal place does not change the stored average.

<!--
Include iostream and iomanip. Input 59 60 60 produces about 59.6667, displayed as 59.7 with no pass. Do not use rounded display text for the test. Stream formatting persists for later output.
Suggested time: 3 min
-->

---

<!-- _class: section -->

## Break

10 minutes  
Next: strings, then a complete program

<!--
Have students save their code. Note recurring questions and revisit one or two after the break.
Suggested time: 10 min
-->

---

<!-- _class: section -->

## Loops and collections

Let a loop handle repeated work

<!--
Introduce the next problem and give students a moment to switch context.
Suggested time: 1 min
-->

---

<!-- _class: code -->

## The execution cycle of for

```cpp
int sum = 0;
for (int i = 1; i <= 3; ++i) {
    sum += i;
}
```

Initialize once, test before the body, then update.

<!--
Trace i/sum on the board: 1/1, 2/3, 3/6. The next test fails at i=4. Emphasize that the update follows the body.
Full demo: Examples/L1_C05_D02.cpp
Suggested time: 3 min
-->

---

<!-- _class: trace -->

## A loop state trace

```text
i       condition       sum after body
1       true            1
2       true            3
3       true            6
4       false           6
```

The final test still runs, but its body does not.

<!--
For each row, ask where i came from and why sum changes or stays. Step with a debugger or board trace so students understand more than the final 6.
Suggested time: 3 min
-->

---

<!-- _class: question -->

## Loop boundaries

```cpp
for (int i = 0; i < 3; ++i) {
    std::cout << i << ' ' ;
}
```

Prints 0 1 2  
What appears if the test becomes <= 3?

<!--
It adds 3, changing three iterations to four. Connect the half-open interval [0,3) to the next array example.
Suggested time: 2 min
-->

---

<!-- _class: code -->

## continue and break

```cpp
for (int i = 0; i < 5; ++i) {
    if (i == 1) continue;
    if (i == 4) break;
    std::cout << i << ' ' ;
}
```

Prints 0 2 3  
continue skips this iteration. break exits the loop.

<!--
Trace 0 through 4. continue still leads to the for update expression. break exits directly. Swap the tests and ask whether these particular results change.
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Array indices

```cpp
int scores[5] = {94, 87, 50};

std::cout << scores[0] << '\n';
std::cout << scores[4] << '\n';
```

5 positions: 0, 1, 2, 3, 4  
The remaining elements are initialized to 0.

<!--
Sketch the five positions on the board. Outputs are 94 and 0. scores[5] is out of bounds and causes undefined behavior. One observed run cannot establish its behavior.
Full demo: Examples/L1_C06_D01.cpp
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Initialization affects element values

```cpp
int a[3] = {0};       // 0, 0, 0
int b[3] = {5};      // 5, 0, 0
int c[3];         // uninitialized local ints
```

Uninitialized local elements are not valid values to read.

<!--
These are automatic local arrays inside main, not global or static arrays. Do not rely on observed garbage output from c. Explicit zero initialization provides a defined starting state.
Suggested time: 2 min
-->

---

<!-- _class: code -->

## Assigning a std::array

```cpp
std::array<int, 3> a = {94, 87, 50};
std::array<int, 3> b = {};
b = a;
b[0] = 100;
```

a[0] remains 94  
Built-in arrays do not support b = a.

<!--
Include array. Contrast built-in arrays with std::array assignment. The copy has independent elements. Leave dynamic allocation for later.
Full demo: Examples/L1_C06_D02.cpp
Suggested time: 2 min
-->

---

<!-- _class: trace -->

## Copies hold independent elements

```text
a:  94  87  50
b:  94  87  50   // after b = a

b[0] = 100

a:  94  87  50
b: 100  87  50
```

A value copy creates a separate object. Later changes do not synchronize.

<!--
Point out the separate elements held by a and b. Connect this to the range-loop copy on the next slide without adding a memory-layout detour.
Suggested time: 2 min
-->

---

<!-- _class: question -->

## Copies in a range loop

```cpp
std::array<int, 3> scores = {60, 70, 80};

for (int score : scores) {
    score += 5;
}
```

After the loop, is scores[0] 60 or 65?

<!--
Vote, then run: it remains 60. Each score is a copy. The next slide changes one symbol for a direct comparison.
Full demo: Examples/L1_C06_D03.cpp
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Changing elements through a reference

```cpp
for (int& score : scores) {
    score += 5;
}
```

scores becomes 65, 75, 85  
Here & gives an alias for each element.

<!--
Build an alias intuition here and explain references fully in Lesson 2. Mention const int& as a read-only borrowed element.
Full demo: Examples/L1_C06_D03.cpp
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Three range-loop forms

```cpp
for (int value : scores)      // copy
for (int& value : scores)     // modify element
for (const int& value : scores) // read only
```

Choose the loop variable type based on whether elements should change.

<!--
These are syntax comparisons and each needs a body. Ask for a use case: summing, applying a bonus, or reading a larger object. Copying an int is cheap, so a reference is not automatically better.
Suggested time: 2 min
-->

---

<!-- _class: practice -->

## Practice: count passing scores

Given {94, 87, 50, 60, 0}  
Count the elements that are at least 60  
Then find the average, expected 58.2

<!--
Expect 3 passes and a sum of 291. Ask about initial values, the >= boundary, and floating division. Early finishers can read five inputs and discuss how a general interface would handle empty data.
Suggested time: 7 min
-->

---

<!-- _class: code -->

## Two accumulators in the score task

```cpp
int sum = 0, passed = 0;
for (int score : scores) {
    sum += score;
    if (score >= 60) ++passed;
}
double average =
    static_cast<double>(sum) / scores.size();
```

For this fixed input: sum=291, passed=3, average=58.2.

<!--
scores has a fixed size of 5 here. A general interface allowing empty containers needs a zero-size guard. Ask why both accumulators start at 0 before reviewing the code.
Suggested time: 3 min
-->

---

<!-- _class: question -->

## Loops and arrays checkpoint

Why does double x = 3 / 2 give 1?  
Why might score += 5 leave an array unchanged?

<!--
Ask students to explain these points using their own code, rather than only give final answers.
Suggested time: 5 min
-->

---

<!-- _class: section -->

## Strings

Locate and edit a name in a string

<!--
Introduce the next problem and give students a moment to switch context.
Suggested time: 1 min
-->

---

<!-- _class: code -->

## Strings have indices too

```cpp
std::string name("soyo");
std::cout << name.size() << '\n';
name[0] = 'S';
```

size is 4. The updated string is Soyo.

<!--
Character positions are 0 through size()-1. These examples use ASCII names. Do not equate byte positions with arbitrary Chinese characters. Mention checked access with at briefly.
Full demo: Examples/L1_C07_D01.cpp
Suggested time: 2 min
-->

---

<!-- _class: question -->

## find returns a position

```cpp
std::string members("soyo,anon,taki");
std::string::size_type pos = members.find("anon");
```

At which index does anon begin?

<!--
Count soyo at 0..3, the comma at 4, and anon beginning at 5. Ask students to account for the comma rather than memorize the number.
Full demo: Examples/L1_C07_D02.cpp
Suggested time: 3 min
-->

---

<!-- _class: code -->

## A missing match gives npos

```cpp
std::string::size_type pos = members.find("rana");
if (pos != std::string::npos) {
    std::cout << pos << '\n';
}
```

Position 0 is a match. if(pos) is not a match test.

<!--
Ask about find("soyo"): it returns 0, which if(pos) treats as false. A missing match gives npos. Compare against npos before using the position.
Full demo: Examples/L1_C07_D02.cpp
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Three search boundary cases

```cpp
members = "soyo,anon,taki";
find("soyo")  // 0: found at the start
find("taki")  // 10: found later
find("rana")  // npos: not found
```

Cover a match at 0, a later match, and no match.

<!--
This is a result comparison, not standalone code. Verify with members.find in the full program. Ask which cases if(pos) misclassifies.
Suggested time: 2 min
-->

---

<!-- _class: code -->

## replace shifts later positions

```cpp
std::string::size_type pos = members.find("anon");
if (pos != std::string::npos) {
    members.replace(pos, 4, "rana");
}
```

Result: soyo,rana,taki  
After a longer replacement, find later positions again.

<!--
4 is the number of characters to replace, not an end index. Try the equal-length edit first, then tomori and observe later positions shifting.
Full demo: Examples/L1_C07_D03.cpp
Suggested time: 2 min
-->

---

<!-- _class: code -->

## Appending and erasing

```cpp
members += ",tomori";
members.insert(0, "rana,");
members.erase(0, 5);
```

Who removes the separator when deleting a name?

<!--
Run each line starting from soyo,anon,taki. erase(0,5) removes rana,. clear removes everything. Positions refer to the current string, not its earlier version.
Full demo: Examples/L1_C07_D04.cpp
Suggested time: 3 min
-->

---

<!-- _class: trace -->

## State after each string edit

```text
start:    soyo,anon,taki
append:   soyo,anon,taki,tomori
insert:   rana,soyo,anon,taki,tomori
erase:    soyo,anon,taki,tomori
```

Each edit starts from the previous result.

<!--
Match the preceding three calls to these states. Identify the five erased characters rana,. Erasing only four leaves a leading comma.
Suggested time: 2 min
-->

---

<!-- _class: practice -->

## Practice: find and replace a member

Start with soyo,anon,taki  
Replace anon with tomori if found  
Keep the string unchanged if absent

<!--
Require one run with anon and one without. Ask whether a match at 0 also works. Expect soyo,tomori,taki. Avoid hard-coding index 5.
Suggested time: 6 min
-->

---

<!-- _class: section -->

## Putting it together

Related data can belong to one object

<!--
Introduce the next problem and give students a moment to switch context.
Suggested time: 1 min
-->

---

<!-- _class: code -->

## A single record

```cpp
struct BandRecord {
    std::string guitar;
    std::string vocal;
};

BandRecord band = {"mutsumi", "hatsune"};
std::cout << band.guitar << '\n';
```

A type describes the structure. An object stores one instance.

<!--
Connect to Band in Lesson 2. struct and class share the same mechanisms with different default access. The full record also has bass. This view focuses on two fields.
Full demo: Examples/L1_C08_D01.cpp
Suggested time: 3 min
-->

---

<!-- _class: code -->

## A type and two records

```cpp
BandRecord a = {"mutsumi", "hatsune"};
BandRecord b = {"anon", "tomori"};
a.guitar = "soyo";
```

Two objects of the same type hold their own fields.

<!--
Use the two-field record shown in class. b.guitar stays anon. The type defines structure. Lesson 2 will add operations to the class.
Suggested time: 2 min
-->

---

<!-- _class: practice -->

## Integrated task: a score report

Read 3 scores into a std::array  
Sum them in a loop and print the average to 1 decimal  
Print the number of passing scores

<!--
Input 94 87 50 should give an average of 77.0 and 2 passes. Combine input, loops, conversion, conditions, and formatting. Ask students to explain a boundary case as well as run the code.
Suggested time: 10 min
-->

---

<!-- _class: statement -->

## Checking the integrated program

94 87 50: average 77.0, 2 passes  
60 60 60: average 60.0, 3 passes  
0 0 0: average 0.0, 0 passes  
Check input, accumulators, division, then comparisons

<!--
Have students exchange test cases and explain how they locate faults. Print intermediate values temporarily, then remove debug output. Revisit the Python plan from the opening.
Suggested time: 4 min
-->

---

<!-- _class: question -->

## Lesson 1 review

Where do you look first in a new program?  
What do you inspect first when a result is wrong?  
Next: how can a function change the caller’s data?

<!--
Elicit main, input, types, conditions, and loop boundaries. Assign the required Assessment-01 tasks and explain challenges separately. Refer students to notes and the exercise index for detail.
Suggested time: 3 min
-->
