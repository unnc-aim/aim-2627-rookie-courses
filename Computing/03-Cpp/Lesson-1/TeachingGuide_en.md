# Lesson 1: Slide-by-slide teaching guide

Each core lesson is planned for 180 minutes including demos, practice, discussion, and a 10-minute break. Lesson 2 adds about 14 optional minutes. Adjust timing to the class. Projected snippets show the current focus. Run complete files. Allow time for predictions before showing results or the worked trace.

## Teaching schedule

| Minutes | Block | First slide |
| --- | --- | --- |
| 000–021 | C++ Fundamentals | 1 |
| 021–044 | Input and types | 10 |
| 044–079 | Operators and decisions | 19 |
| 079–089 | Break | 32 |
| 089–133 | Loops and collections | 33 |
| 133–157 | Strings | 48 |
| 157–180 | Putting it together | 57 |

## 01. C++ Fundamentals

Ask who has run Hello World locally. Explain the predict, run, explain, change routine. Examples contains full programs. The screen shows only the current focus.

Suggested time: 1 min

## 02. Our program for today

Ask for a verbal Python solution. Put input, storage, loop, and condition on the board. Revisit them through the lesson.

Suggested time: 3 min

## 03. One complete program

Run first, then point out the header, main, braces, and semicolon. return 0 is an exit status, not printed output. Later snippets omit the unchanged wrapper. Always run the complete file.

Demo: [L1_C01_D01.cpp](Examples/L1_C01_D01.cpp)

Suggested time: 2 min

## 04. Python and C++ notation

Compare declaration, condition parentheses, braces, and semicolons. Indentation still helps readability but does not define C++ blocks. Connect the wrapper to program structure.

Suggested time: 3 min

## 05. Blocks and variable scope

Trace score from 85 to 90. Attempt to print bonus outside the block. Distinguish name scope from object lifetime, which end together for this simple local variable.

Suggested time: 3 min

## 06. Compilation and execution

Wait at least ten seconds, then remove the semicolon in the full demo. Compilation fails, so this source version does not run. Read the first diagnostic and repair it before running again.

Demo: [L1_C01_D01.cpp](Examples/L1_C01_D01.cpp)

Suggested time: 3 min

## 07. The first compiler diagnostic

Demonstrate a missing semicolon reported on the following line. The reported location is where the compiler notices the problem. Have a student read one diagnostic.

Suggested time: 2 min

## 08. std:: qualifies a name

Explain namespaces as a way to distinguish names. Use std:: in class and show using for recognition. Use the demo for name conflicts without adding a header-splitting detour.

Demo: [L1_C02_D01.cpp](Examples/L1_C02_D01.cpp)

Suggested time: 2 min

## 09. Output order

Elicit score=85. Quotes are not printed and variables contribute their values. Mention that endl also flushes the stream. Use \n for ordinary newlines.

Demo: [L1_C02_D02.cpp](Examples/L1_C02_D02.cpp)

Suggested time: 2 min

## 10. Input and types

Introduce the next problem and give students a moment to switch context.

Suggested time: 1 min

## 11. Variable types

Ask what each type can represent. string requires the string header. Contrast single quotes for char with double quotes for strings. bool prints 0 or 1 by default. boolalpha prints true or false.

Demo: [L1_C03_D02.cpp](Examples/L1_C03_D02.cpp)

Suggested time: 3 min

## 12. Initialization and later assignment

truncated is 3. Compare initialization and assignment. An explicit conversion expresses intent but can still lose information. Test -3.5 to observe truncation toward zero.

Suggested time: 2 min

## 13. Types determine representable values

Common systems use 4-byte int and 8-byte double, but the language does not guarantee those sizes. Signed overflow cannot be assumed to wrap. Introduce numeric_limits as a reference.

Suggested time: 2 min

## 14. Input follows extraction order

Prefill 8 4 and observe 4. Separate lines also give 4. Whitespace separates these integers. Try 8,4 and explain that a comma is not automatically accepted as a separator.

Demo: [L1_C03_D01.cpp](Examples/L1_C03_D01.cpp)

Suggested time: 3 min

## 15. Token extraction and line input

Run the two-token example, then use std::getline(std::cin,line). Mixing extraction and getline can leave a newline pending. std::ws can help when leading whitespace should be skipped.

Suggested time: 3 min

## 16. Failed input

Demonstrate inside main. Elicit the plain-language meaning: exit if reading an integer fails. Revisit if and ! later. Do not treat score as a valid result after failure.

Suggested time: 2 min

## 17. Practice: read and print

Start from the Hello World wrapper with iostream and string. Check extraction order and quotes. After two minutes, ask a student to explain the types, then run their solution. Keep the answer off screen.

Suggested time: 5 min

## 18. Read and print: review

Reveal after students attempt the exercise. Ask why the colon is quoted. Discuss reversed input order and whether a name containing spaces fits this interface.

Suggested time: 2 min

## 19. Operators and decisions

Introduce the next problem and give students a moment to switch context.

Suggested time: 1 min

## 20. The value of 3 / 2

Elicit 1, 1.5, and 1. Integer division truncates toward zero. % gives an integer remainder. The example uses positive values. Mention truncation toward zero for negatives too.

Demo: [L1_C04_D01.cpp](Examples/L1_C04_D01.cpp)

Suggested time: 3 min

## 21. When conversion happens

Write the integer result 1 before its conversion to double. Converting a first gives the division a floating operand. Ask whether static_cast<double>(a/b) recovers the fraction. It does not.

Demo: [L1_C04_D01.cpp](Examples/L1_C04_D01.cpp)

Suggested time: 3 min

## 22. Tracing three division expressions

Circle the subexpressions on the board. The final value is double 1. Default formatting may print 1 rather than 1.0. Separate numerical type from presentation.

Suggested time: 2 min

## 23. Assignment and comparison

Elicit x=3 and outputs 1 then 0. Explain that if(x=3) may compile while changing x. Successful compilation does not prove the intended behavior.

Demo: [L1_C04_D02.cpp](Examples/L1_C04_D02.cpp)

Suggested time: 2 min

## 24. Compound conditions and short-circuiting

Assume score and total are doubles. && skips the right side when the left is false. || skips it when the left is true. ! negates. Ask why reversing the conditions loses the zero-denominator guard.

Demo: [L1_C04_D03.cpp](Examples/L1_C04_D03.cpp)

Suggested time: 3 min

## 25. AND, OR, and NOT

Evaluate -1, 0, 100, and 101. Compare with score>=0 && score<=100. Explain both the logical relation and evaluation short-circuiting.

Suggested time: 2 min

## 26. Updating a variable

Pause after each line: 4, 6, 18. Keep ++ out of complex expressions. Mention cmath functions such as sqrt and abs as reference material rather than a catalog on screen.

Demo: [L1_C04_D04.cpp](Examples/L1_C04_D04.cpp)

Suggested time: 2 min

## 27. Math functions and result types

Run each expression through cout. floor and ceil return rounded floating values, unlike conversion to int. For -2.8, floor gives -3 while truncation toward zero gives -2.

Suggested time: 2 min

## 28. Mutually exclusive if branches

Only A prints. Compare with two independent if statements. Run 95, 60, and 59. Explain why the higher threshold comes first.

Demo: [L1_C05_D01.cpp](Examples/L1_C05_D01.cpp)

Suggested time: 3 min

## 29. Branch order and boundary cases

Move >=60 before >=90 and ask how 95 is classified. Trace then run the cases. If valid input is constrained to 0..100, validate that separately.

Suggested time: 2 min

## 30. Practice: average and pass check

Use iomanip with fixed and setprecision(1). Have students predict 59 60 60: 59.7 and no pass. Then test 60 60 60. Compare the numerical average before output formatting.

Suggested time: 7 min

## 31. Average: calculation and formatting

Include iostream and iomanip. Input 59 60 60 produces about 59.6667, displayed as 59.7 with no pass. Do not use rounded display text for the test. Stream formatting persists for later output.

Suggested time: 3 min

## 32. Break

Have students save their code. Note recurring questions and revisit one or two after the break.

Suggested time: 10 min

## 33. Loops and collections

Introduce the next problem and give students a moment to switch context.

Suggested time: 1 min

## 34. The execution cycle of for

Trace i/sum on the board: 1/1, 2/3, 3/6. The next test fails at i=4. Emphasize that the update follows the body.

Demo: [L1_C05_D02.cpp](Examples/L1_C05_D02.cpp)

Suggested time: 3 min

## 35. A loop state trace

For each row, ask where i came from and why sum changes or stays. Step with a debugger or board trace so students understand more than the final 6.

Suggested time: 3 min

## 36. Loop boundaries

It adds 3, changing three iterations to four. Connect the half-open interval [0,3) to the next array example.

Suggested time: 2 min

## 37. continue and break

Trace 0 through 4. continue still leads to the for update expression. break exits directly. Swap the tests and ask whether these particular results change.

Suggested time: 3 min

## 38. Array indices

Sketch the five positions on the board. Outputs are 94 and 0. scores[5] is out of bounds and causes undefined behavior. One observed run cannot establish its behavior.

Demo: [L1_C06_D01.cpp](Examples/L1_C06_D01.cpp)

Suggested time: 3 min

## 39. Initialization affects element values

These are automatic local arrays inside main, not global or static arrays. Do not rely on observed garbage output from c. Explicit zero initialization provides a defined starting state.

Suggested time: 2 min

## 40. Assigning a std::array

Include array. Contrast built-in arrays with std::array assignment. The copy has independent elements. Leave dynamic allocation for later.

Demo: [L1_C06_D02.cpp](Examples/L1_C06_D02.cpp)

Suggested time: 2 min

## 41. Copies hold independent elements

Point out the separate elements held by a and b. Connect this to the range-loop copy on the next slide without adding a memory-layout detour.

Suggested time: 2 min

## 42. Copies in a range loop

Vote, then run: it remains 60. Each score is a copy. The next slide changes one symbol for a direct comparison.

Demo: [L1_C06_D03.cpp](Examples/L1_C06_D03.cpp)

Suggested time: 3 min

## 43. Changing elements through a reference

Build an alias intuition here and explain references fully in Lesson 2. Mention const int& as a read-only borrowed element.

Demo: [L1_C06_D03.cpp](Examples/L1_C06_D03.cpp)

Suggested time: 3 min

## 44. Three range-loop forms

These are syntax comparisons and each needs a body. Ask for a use case: summing, applying a bonus, or reading a larger object. Copying an int is cheap, so a reference is not automatically better.

Suggested time: 2 min

## 45. Practice: count passing scores

Expect 3 passes and a sum of 291. Ask about initial values, the >= boundary, and floating division. Early finishers can read five inputs and discuss how a general interface would handle empty data.

Suggested time: 7 min

## 46. Two accumulators in the score task

scores has a fixed size of 5 here. A general interface allowing empty containers needs a zero-size guard. Ask why both accumulators start at 0 before reviewing the code.

Suggested time: 3 min

## 47. Loops and arrays checkpoint

Ask students to explain these points using their own code, rather than only give final answers.

Suggested time: 5 min

## 48. Strings

Introduce the next problem and give students a moment to switch context.

Suggested time: 1 min

## 49. Strings have indices too

Character positions are 0 through size()-1. These examples use ASCII names. Do not equate byte positions with arbitrary Chinese characters. Mention checked access with at briefly.

Demo: [L1_C07_D01.cpp](Examples/L1_C07_D01.cpp)

Suggested time: 2 min

## 50. find returns a position

Count soyo at 0..3, the comma at 4, and anon beginning at 5. Ask students to account for the comma rather than memorize the number.

Demo: [L1_C07_D02.cpp](Examples/L1_C07_D02.cpp)

Suggested time: 3 min

## 51. A missing match gives npos

Ask about find("soyo"): it returns 0, which if(pos) treats as false. A missing match gives npos. Compare against npos before using the position.

Demo: [L1_C07_D02.cpp](Examples/L1_C07_D02.cpp)

Suggested time: 3 min

## 52. Three search boundary cases

This is a result comparison, not standalone code. Verify with members.find in the full program. Ask which cases if(pos) misclassifies.

Suggested time: 2 min

## 53. replace shifts later positions

4 is the number of characters to replace, not an end index. Try the equal-length edit first, then tomori and observe later positions shifting.

Demo: [L1_C07_D03.cpp](Examples/L1_C07_D03.cpp)

Suggested time: 2 min

## 54. Appending and erasing

Run each line starting from soyo,anon,taki. erase(0,5) removes rana,. clear removes everything. Positions refer to the current string, not its earlier version.

Demo: [L1_C07_D04.cpp](Examples/L1_C07_D04.cpp)

Suggested time: 3 min

## 55. State after each string edit

Match the preceding three calls to these states. Identify the five erased characters rana,. Erasing only four leaves a leading comma.

Suggested time: 2 min

## 56. Practice: find and replace a member

Require one run with anon and one without. Ask whether a match at 0 also works. Expect soyo,tomori,taki. Avoid hard-coding index 5.

Suggested time: 6 min

## 57. Putting it together

Introduce the next problem and give students a moment to switch context.

Suggested time: 1 min

## 58. A single record

Connect to Band in Lesson 2. struct and class share the same mechanisms with different default access. The full record also has bass. This view focuses on two fields.

Demo: [L1_C08_D01.cpp](Examples/L1_C08_D01.cpp)

Suggested time: 3 min

## 59. A type and two records

Use the two-field record shown in class. b.guitar stays anon. The type defines structure. Lesson 2 will add operations to the class.

Suggested time: 2 min

## 60. Integrated task: a score report

Input 94 87 50 should give an average of 77.0 and 2 passes. Combine input, loops, conversion, conditions, and formatting. Ask students to explain a boundary case as well as run the code.

Suggested time: 10 min

## 61. Checking the integrated program

Have students exchange test cases and explain how they locate faults. Print intermediate values temporarily, then remove debug output. Revisit the Python plan from the opening.

Suggested time: 4 min

## 62. Lesson 1 review

Elicit main, input, types, conditions, and loop boundaries. Assign the required Assessment-01 tasks and explain challenges separately. Refer students to notes and the exercise index for detail.

Suggested time: 3 min
