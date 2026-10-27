# Lesson 2: Slide-by-slide teaching guide

Each core lesson is planned for 180 minutes including demos, practice, discussion, and a 10-minute break. Lesson 2 adds about 14 optional minutes. Adjust timing to the class. Projected snippets show the current focus. Run complete files. Allow time for predictions before showing results or the worked trace.

## Teaching schedule

| Minutes | Block | First slide |
| --- | --- | --- |
| 000–003 | C++ Functions and Classes | 1 |
| 003–020 | Functions | 3 |
| 020–048 | References and pointers | 10 |
| 048–076 | The swap experiment | 20 |
| 076–086 | Break | 29 |
| 086–150 | Band: data and behavior | 30 |
| 150–180 | Inheritance | 51 |
| 180–194 | Optional extensions | 59 |

## 01. C++ Functions and Classes

Recall the reference loop that changed array elements. Keep asking which object each line changes. Use the band model throughout the second half.

Suggested time: 1 min

## 02. What happens after a swap?

Do not show swap1 yet or require an implementation guess. Elicit that the name alone cannot tell us whether caller data changes. Resolve the question through parameter types.

Suggested time: 2 min

## 03. Functions

Introduce the next problem and give students a moment to switch context.

Suggested time: 1 min

## 04. The test_add interface

Point out the return type, name, parameters, arguments, and return value. sum is local and its lifetime ends after the call. Its integer value has already been delivered to the caller.

Demo: [L2_C01_D01.cpp](Examples/L2_C01_D01.cpp)

Suggested time: 3 min

## 05. Local state during one call

Trace a second call test_add(4,5). Calls have separate local state and do not reuse the prior sum. Keep the discussion on simple value returns.

Suggested time: 3 min

## 06. Output and return values

Ask whether 5 appears without printing result. It does not. Explain why cout alone cannot replace the return required by this non-void function.

Suggested time: 3 min

## 07. A return value can join another expression

Use the version of test_add without diagnostic output. Try test_add(test_add(1,2),3). The inner result supplies an outer argument. Avoid broad evaluation-order claims for side effects.

Suggested time: 2 min

## 08. Declarations, definitions, and void

Use the full file to show a declaration before a call. A void call cannot initialize an int. Keep one main in the single-file classroom platform.

Demo: [L2_C01_D02.cpp](Examples/L2_C01_D02.cpp)

Suggested time: 2 min

## 09. Local names do not share storage

The caller value is local to main, whose wrapper is omitted. It stays 10. Ask students to explain parameter initialization rather than alias binding.

Suggested time: 3 min

## 10. References and pointers

Introduce the next problem and give students a moment to switch context.

Suggested time: 1 min

## 11. A reference aliases an object

It contains afterglow. band1 and live1 name the same object. Compare &band1==&live1 to observe true. A reference cannot be rebound after initialization.

Demo: [L2_C02_D01.cpp](Examples/L2_C02_D01.cpp)

Suggested time: 3 min

## 12. Assignment through a reference does not rebind it

r=b assigns b’s value to a. It does not make r refer to b. Contrast this with changing a pointer’s address using p=&b.

Suggested time: 2 min

## 13. A pointer stores an address

Distinguish * in a declaration from dereferencing in an expression. anime1 is itself an object that stores an address. band1 and live1 now both see roselia.

Demo: [L2_C02_D02.cpp](Examples/L2_C02_D02.cpp)

Suggested time: 3 min

## 14. Declaration, address-of, and dereference

Ask students to describe p and *p, including their types and relationship. A printed address is not a stable expected value. Use the board for the relationship.

Suggested time: 3 min

## 15. Changing a pointer or its target

Ask students to name the target after every line. Use the board to track names and addresses. p=&b does not copy b into a.

Suggested time: 3 min

## 16. Null pointers and lifetimes

Nothing prints. A null check is only part of validity: a non-null dangling pointer is still invalid. Do not return a local variable’s address. Mention const string* for read-only access without listing every const combination.

Demo: [L2_C02_D03.cpp](Examples/L2_C02_D03.cpp)

Suggested time: 3 min

## 17. Read-only borrowing and lifetime

If band1 itself is mutable, another valid access path can change it and view observes that change. A const borrow is not a snapshot or a universal lifetime extension.

Suggested time: 3 min

## 18. Practice: trace the objects

All four are 11. Require a line-by-line explanation. Ask whether p=&a changes b. It does not.

Suggested time: 5 min

## 19. Line-by-line results of the trace

The values match after the last line but the relationship changes. Ask what *p=99 would affect next: a and r see 99 while b stays 11.

Suggested time: 2 min

## 20. The swap experiment

Introduce the next problem and give students a moment to switch context.

Suggested time: 1 min

## 21. swap1 exchanges local copies

Return to the opening prediction. Draw caller x/y and local a/b on separate rows. Trace the updates. After return, a/b cease to exist and x/y remain 10/20.

Demo: [L2_C03_D01.cpp](Examples/L2_C03_D01.cpp)

Suggested time: 4 min

## 22. The state trace of swap1

Circle the left side of every assignment. Neither x nor y is assigned. Destroying the parameters does not automatically copy their values back.

Suggested time: 3 min

## 23. swap2 writes through addresses

Reset x=10,y=20. Observe 20/10 after the call. Pointer parameters still pass by value: the copied values are addresses. This function requires valid pointers, so nullptr is outside its precondition.

Demo: [L2_C03_D02.cpp](Examples/L2_C03_D02.cpp)

Suggested time: 4 min

## 24. The state trace of swap2

Keep a=&x and b=&y on the board. Distinguish assigning the local pointer from assigning through it. Verify each step with a debugger or temporary output.

Suggested time: 3 min

## 25. Swapping with reference parameters

Only two & symbols differ from swap1. This is a comparison alongside the original swap1/swap2 sequence. Compare the three call expressions.

Suggested time: 3 min

## 26. Choosing a parameter interface

A pointer can represent an optional target, but nullability depends on the contract. A pointer is not automatically nullable. Read-only int parameters usually work well by value, while const& is useful for larger objects.

Suggested time: 3 min

## 27. Practice: repair a function that cannot write back

Use int& score. Verify 60 becomes 65 and explain why the original left it unchanged. A version returning a new value is also valid but requires a different call.

Suggested time: 5 min

## 28. Mutation and returning a new value

Have students write both calls and explain why with_bonus(score) alone leaves the original unchanged. Discuss how the interface communicates intent.

Suggested time: 2 min

## 29. Break

Have students save the reduced Band exercise. Review construction and access briefly before inheritance.

Suggested time: 10 min

## 30. Band: data and behavior

Introduce the next problem and give students a moment to switch context.

Suggested time: 1 min

## 31. From a record to Band

Recall the public fields of the record. Band places operations in the type. Only keyboard is visible here. The full model retains guitar, vocal, drum, and bass. This setter does not itself enforce a business validation rule.

Demo: [L2_C04_D02.cpp](Examples/L2_C04_D02.cpp)

Suggested time: 3 min

## 32. Five fields belong to one band

Restore the five-member context after the keyboard-only view. Ask how parallel variables could be kept associated with one band, motivating encapsulation.

Suggested time: 2 min

## 33. Objects have independent state

Use the preceding minimal class with its implicit default constructor and initially empty string. b is unaffected. Once the parameterized constructor is introduced, this default-construction syntax will no longer apply.

Suggested time: 3 min

## 34. Independent state in two objects

Use the minimal Band with implicit default construction. Band a; does not work with the later full five-argument constructor. Object names identify call targets.

Suggested time: 2 min

## 35. private and public

The first line is an intentional compile error. Test it separately. private restricts direct access outside the class while member functions retain access.

Demo: [L2_C04_D02.cpp](Examples/L2_C04_D02.cpp)

Suggested time: 3 min

## 36. Encapsulation provides one update interface

This extra method illustrates a constraint. The original setter does not validate. Empty names are rejected here. Discuss whether silent rejection is sufficient or a bool return would help.

Suggested time: 3 min

## 37. Constructors establish initial state

Place the constructor in Band’s public section. The full Band accepts five member names. This reduced view uses one. Show assignment in the body before comparing member initialization.

Demo: [L2_C05_D01.cpp](Examples/L2_C05_D01.cpp)

Suggested time: 3 min

## 38. Parameterized and default construction

This is the reduced one-key constructor. If default creation is required, design a default constructor or default arguments and a valid initial state. Constructors need not always be public; this interface chooses public.

Suggested time: 3 min

## 39. Member initializer lists

Contrast direct initialization with default construction followed by assignment. Declaration order controls member initialization. const and reference members need initialization. Keep the std::move detail in notes without promising speed.

Demo: [L2_C05_D02.cpp](Examples/L2_C05_D02.cpp)

Suggested time: 3 min

## 40. Declaration order controls initialization

Both initializers are independent constants. Reorder the list and show the compiler warning. Avoid a demonstration that reads an uninitialized member.

Suggested time: 2 min

## 41. Reading and changing state

Explain this for the class used here, which has no mutable members. A const Band can call print_info but not the setter. In the source model, get_guitar prints a name rather than returning a string.

Demo: [L2_C06_D01.cpp](Examples/L2_C06_D01.cpp)

Suggested time: 3 min

## 42. What can a const object call?

Use the one-field Band. Uncomment the setter call and read the diagnostic. The trailing const constrains access through this, unlike const on a parameter.

Suggested time: 2 min

## 43. Practice: complete a small Band

Use initial values saki and eve. After modifying a, expect anon/eve. Require headers, the class terminator, and main. Return to the full five-member Band after the exercise.

Suggested time: 10 min

## 44. Reviewing the Band exercise

Run successful and intentionally failing tests separately. Ask which rule each test checks. Confirm understanding beyond copying a class definition.

Suggested time: 3 min

## 45. The five members of the full Band

Return to the full class definition in the demo file. Follow class_band: construct ave_mujica, then print_info and live. They print the member list and LIVE respectively.

Demo: [L2_C09_D01.cpp](Examples/L2_C09_D01.cpp)

Suggested time: 3 min

## 46. A vector of bands

Include vector. emplace_back constructs an element at the end from the supplied arguments. Briefly mention that growth can invalidate existing references and pointers without adding an allocation lecture.

Demo: [L2_C06_D02.cpp](Examples/L2_C06_D02.cpp)

Suggested time: 3 min

## 47. Vector size and element access

[] does not check bounds. at throws for an invalid index. emplace_back changes the size and constructs a new object, unlike assigning an existing element.

Suggested time: 2 min

## 48. Which object does a loop change?

Reuse the rule from Lesson 1. Use const Band& for read-only printing. Reset the data when comparing loops so that changes from the reference loop do not confuse the result.

Demo: [L2_C06_D02.cpp](Examples/L2_C06_D02.cpp)

Suggested time: 3 min

## 49. Read-only iteration over bands

Compare copying Band, modifying through Band&, and reading through const Band&. Explain why print_info needs const and the setter cannot be called here.

Suggested time: 2 min

## 50. Classes and containers checkpoint

Ask students to explain these points using their own code, rather than only give final answers.

Suggested time: 5 min

## 51. Inheritance

Introduce the next problem and give students a moment to switch context.

Suggested time: 1 min

## 52. MofoBand inherits Band

This view focuses on inheritance and a method. Add the constructor next. Derived code cannot directly access Band’s private fields, but can call its public methods. public inheritance permits use as a Band.

Demo: [L2_C07_D01.cpp](Examples/L2_C07_D01.cpp)

Suggested time: 3 min

## 53. The base initializes first

This is a constructor fragment inside the class. Open the complete demo to connect the five band member arguments. Band(...) in the body creates a temporary and cannot replace base initialization.

Demo: [L2_C07_D02.cpp](Examples/L2_C07_D02.cpp)

Suggested time: 4 min

## 54. Access to a protected member

Correct the misconception that only derived classes can access protected members. The declaring class can too. Object-expression and inheritance rules also matter. This page concerns the established public inheritance chain.

Demo: [L2_C08_D01.cpp](Examples/L2_C08_D01.cpp)

Suggested time: 3 min

## 55. this points to the current object

Demonstrate in MofoBand_New. const& borrows the parameter read-only. Assigning it to vocal_actor still assigns a string. this-> is optional here, not required for every member access.

Demo: [L2_C08_D02.cpp](Examples/L2_C08_D02.cpp)

Suggested time: 3 min

## 56. Practice: change the actor

Have students edit main in the full demo rather than retype all constructor parameters. Verify that only the target object’s actor field changes.

Demo: [L2_C08_D02.cpp](Examples/L2_C08_D02.cpp)

Suggested time: 8 min

## 57. Tracing class_band

Open class_band in the original integrated Lesson02.cpp. Step through in execution order and ask which object each call affects. ave_mujica is not in live_bands, so container updates do not update it.

Demo: [L2_C09_D01.cpp](Examples/L2_C09_D01.cpp)

Suggested time: 5 min

## 58. Core lesson review

Use swap, the Band setter, and a vector reference loop as examples. Assign required Assessment-02 work. The following pages are optional extension material, so the core class can end here.

Suggested time: 3 min

## 59. Optional extensions

Introduce the next problem and give students a moment to switch context.

Suggested time: 1 min

## 60. Calling derived behavior through a base

The original Band has no virtual members. Use these separate minimal types and demonstrate Base& b=d; b.live(). override checks matching. A virtual destructor supports deletion through a base pointer.

Demo: [L2_C09_D02.cpp](Examples/L2_C09_D02.cpp)

Suggested time: 4 min

## 61. Copying by value can slice an object

Use the preceding types. copied.live calls Base and borrowed.live calls Derived. Connect this to choosing a container element type while retaining the existing vector<Band> teaching model.

Demo: [L2_C09_D02.cpp](Examples/L2_C09_D02.cpp)

Suggested time: 3 min

## 62. Exclusive resource ownership

Include memory and utility. This is optional engineering material: the original Band values need no manual new/delete. unique_ptr is noncopyable. std::move is a cast; unique_ptr’s move constructor transfers ownership. An empty source is guaranteed here, not for every moved-from type.

Demo: [L2_C09_D03.cpp](Examples/L2_C09_D03.cpp)

Suggested time: 4 min

## 63. After class and challenge work

Remind students that public checks are not final grades and that they must actively submit. Refer to the notes and exercises for full explanations. Decide whether extensions are taught now or assigned as reading.

Suggested time: 2 min
