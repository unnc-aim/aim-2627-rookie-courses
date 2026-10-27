---
marp: true
theme: aim-classroom
paginate: true
size: 16:9
---

<!-- _class: cover -->

## C++ Functions and Classes

Lesson 2 / Parameters and collaborating objects

<!--
Recall the reference loop that changed array elements. Keep asking which object each line changes. Use the band model throughout the second half.
Suggested time: 1 min
-->

---

<!-- _class: question -->

## What happens after a swap?

```cpp
int x = 10, y = 20;
swap1(x, y);
std::cout << x << ' ' << y << '\n';
```

Keep your prediction. We will return to it.

<!--
Do not show swap1 yet or require an implementation guess. Elicit that the name alone cannot tell us whether caller data changes. Resolve the question through parameter types.
Suggested time: 2 min
-->

---

<!-- _class: section -->

## Functions

How a call expression receives a result

<!--
Introduce the next problem and give students a moment to switch context.
Suggested time: 1 min
-->

---

<!-- _class: code -->

## The test_add interface

```cpp
int test_add(int a, int b) {
    int sum = a + b;
    return sum;
}

int result = test_add(1, 2);
```

Parameters a and b receive 1 and 2. result receives 3.

<!--
Point out the return type, name, parameters, arguments, and return value. sum is local and its lifetime ends after the call. Its integer value has already been delivered to the caller.
Full demo: Examples/L2_C01_D01.cpp
Suggested time: 3 min
-->

---

<!-- _class: trace -->

## Local state during one call

```text
call                a    b    sum
test_add(1, 2)      1    2      3
return 3           local objects end
caller             result = 3
```

The result value returns. Local variables do not become globals.

<!--
Trace a second call test_add(4,5). Calls have separate local state and do not reuse the prior sum. Keep the discussion on simple value returns.
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Output and return values

```cpp
int test_add(int a, int b) {
    std::cout << "adding\n";
    return a + b;
}

int result = test_add(2, 3);
```

The screen shows adding. result receives 5.

<!--
Ask whether 5 appears without printing result. It does not. Explain why cout alone cannot replace the return required by this non-void function.
Suggested time: 3 min
-->

---

<!-- _class: code -->

## A return value can join another expression

```cpp
int total = test_add(2, 3) * 10;
std::cout << total << '\n';
```

Receive 5, multiply by 10, then print 50.

<!--
Use the version of test_add without diagnostic output. Try test_add(test_add(1,2),3). The inner result supplies an outer argument. Avoid broad evaluation-order claims for side effects.
Suggested time: 2 min
-->

---

<!-- _class: code -->

## Declarations, definitions, and void

```cpp
int test_add(int a, int b);

void hello() {
    std::cout << "Hello\n";
}
```

A declaration gives the interface. A definition supplies the body.  
void means no return value.

<!--
Use the full file to show a declaration before a call. A void call cannot initialize an int. Keep one main in the single-file classroom platform.
Full demo: Examples/L2_C01_D02.cpp
Suggested time: 2 min
-->

---

<!-- _class: code -->

## Local names do not share storage

```cpp
void change(int value) {
    value = 99;
}

int value = 10;
change(value);
```

The same name in separate scopes still names separate objects.

<!--
The caller value is local to main, whose wrapper is omitted. It stays 10. Ask students to explain parameter initialization rather than alias binding.
Suggested time: 3 min
-->

---

<!-- _class: section -->

## References and pointers

Names, addresses, and the objects at those addresses

<!--
Introduce the next problem and give students a moment to switch context.
Suggested time: 1 min
-->

---

<!-- _class: question -->

## A reference aliases an object

```cpp
std::string band1("poppin party");
std::string& live1 = band1;
live1 = "afterglow";
```

What does band1 contain now?

<!--
It contains afterglow. band1 and live1 name the same object. Compare &band1==&live1 to observe true. A reference cannot be rebound after initialization.
Full demo: Examples/L2_C02_D01.cpp
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Assignment through a reference does not rebind it

```cpp
int a = 10, b = 20;
int& r = a;
r = b;
b = 30;
```

Finally a=20, b=30, r=20.

<!--
r=b assigns b’s value to a. It does not make r refer to b. Contrast this with changing a pointer’s address using p=&b.
Suggested time: 2 min
-->

---

<!-- _class: code -->

## A pointer stores an address

```cpp
std::string* anime1 = &band1;

std::cout << *anime1 << '\n';
*anime1 = "roselia";
```

&band1 takes an address. *anime1 accesses the target object.

<!--
Distinguish * in a declaration from dereferencing in an expression. anime1 is itself an object that stores an address. band1 and live1 now both see roselia.
Full demo: Examples/L2_C02_D02.cpp
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Declaration, address-of, and dereference

```cpp
int value = 10;
int* p = &value;

// int*    : type of p
// &value  : address of value
// *p      : object at that address
```

Read the syntax context before interpreting the symbol.

<!--
Ask students to describe p and *p, including their types and relationship. A printed address is not a stable expected value. Use the board for the relationship.
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Changing a pointer or its target

```cpp
std::string a("A"), b{"B"};
std::string* p = &a;
p = &b;
*p = "X";
```

a is A. b is X.  
p changes its stored address, then writes to the new target.

<!--
Ask students to name the target after every line. Use the board to track names and addresses. p=&b does not copy b into a.
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Null pointers and lifetimes

```cpp
std::string* p = nullptr;
if (p != nullptr) {
    std::cout << *p << '\n';
}
```

Check for a target before dereferencing.

<!--
Nothing prints. A null check is only part of validity: a non-null dangling pointer is still invalid. Do not return a local variable’s address. Mention const string* for read-only access without listing every const combination.
Full demo: Examples/L2_C02_D03.cpp
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Read-only borrowing and lifetime

```cpp
const std::string& view = band1;
const std::string* ptr = &band1;

// view = "X"; // not allowed
// *ptr = "X"; // not allowed
```

const restricts mutation through this access path.  
The original object must remain alive while borrowed.

<!--
If band1 itself is mutable, another valid access path can change it and view observes that change. A const borrow is not a snapshot or a universal lifetime extension.
Suggested time: 3 min
-->

---

<!-- _class: practice -->

## Practice: trace the objects

```cpp
int a = 10, b = 20;
int& r = a;
int* p = &b;
r = 11;
*p = r;
p = &a;
```

What are the final values of a, b, r, and *p?

<!--
All four are 11. Require a line-by-line explanation. Ask whether p=&a changes b. It does not.
Suggested time: 5 min
-->

---

<!-- _class: trace -->

## Line-by-line results of the trace

```text
operation     a    b    r    *p
r = 11       11   20   11    20
*p = r       11   11   11    11
p = &a       11   11   11    11
```

The final line changes the pointer target, not a or b.

<!--
The values match after the last line but the relationship changes. Ask what *p=99 would affect next: a and r see 99 while b stays 11.
Suggested time: 2 min
-->

---

<!-- _class: section -->

## The swap experiment

Parameter types determine which data a function can access

<!--
Introduce the next problem and give students a moment to switch context.
Suggested time: 1 min
-->

---

<!-- _class: code -->

## swap1 exchanges local copies

```cpp
void swap1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

swap1(x, y);
```

<!--
Return to the opening prediction. Draw caller x/y and local a/b on separate rows. Trace the updates. After return, a/b cease to exist and x/y remain 10/20.
Full demo: Examples/L2_C03_D01.cpp
Suggested time: 4 min
-->

---

<!-- _class: trace -->

## The state trace of swap1

```text
step        x    y    a    b    temp
call       10   20   10   20      -
temp=a     10   20   10   20     10
a=b        10   20   20   20     10
b=temp     10   20   20   10     10
```

No step writes to x or y.

<!--
Circle the left side of every assignment. Neither x nor y is assigned. Destroying the parameters does not automatically copy their values back.
Suggested time: 3 min
-->

---

<!-- _class: code -->

## swap2 writes through addresses

```cpp
void swap2(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

swap2(&x, &y);
```

Parameters copy addresses. *a and *b access the originals.

<!--
Reset x=10,y=20. Observe 20/10 after the call. Pointer parameters still pass by value: the copied values are addresses. This function requires valid pointers, so nullptr is outside its precondition.
Full demo: Examples/L2_C03_D02.cpp
Suggested time: 4 min
-->

---

<!-- _class: trace -->

## The state trace of swap2

```text
step          target of a   target of b
call              x=10          y=20
temp=*a           x=10          y=20
*a=*b             x=20          y=20
*b=temp           x=20          y=10
```

The pointers are copies, but their targets are the caller’s objects.

<!--
Keep a=&x and b=&y on the board. Distinguish assigning the local pointer from assigning through it. Verify each step with a debugger or temporary output.
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Swapping with reference parameters

```cpp
void swap_ref(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

swap_ref(x, y);
```

a and b directly alias x and y.

<!--
Only two & symbols differ from swap1. This is a comparison alongside the original swap1/swap2 sequence. Compare the three call expressions.
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Choosing a parameter interface

```cpp
void f(int value);        // independent copy
void f(int& value);       // may modify caller
void f(const int& value); // read-only borrow
void f(int* value);       // pointer value
```

An interface should clarify mutation and whether no target is allowed.

<!--
A pointer can represent an optional target, but nullability depends on the contract. A pointer is not automatically nullable. Read-only int parameters usually work well by value, while const& is useful for larger objects.
Suggested time: 3 min
-->

---

<!-- _class: practice -->

## Practice: repair a function that cannot write back

```cpp
void add_bonus(int score) {
    score += 5;
}
```

After add_bonus(score), the caller’s score must increase by 5.  
What needs to change?

<!--
Use int& score. Verify 60 becomes 65 and explain why the original left it unchanged. A version returning a new value is also valid but requires a different call.
Suggested time: 5 min
-->

---

<!-- _class: code -->

## Mutation and returning a new value

```cpp
void add_bonus(int& score) {
    score += 5;
}

int with_bonus(int score) {
    return score + 5;
}
```

add_bonus(score) mutates directly.  
score = with_bonus(score) explicitly stores a new value.

<!--
Have students write both calls and explain why with_bonus(score) alone leaves the original unchanged. Discuss how the interface communicates intent.
Suggested time: 2 min
-->

---

<!-- _class: section -->

## Break

10 minutes  
Next: extend Band and trace the integrated program

<!--
Have students save the reduced Band exercise. Review construction and access briefly before inheritance.
Suggested time: 10 min
-->

---

<!-- _class: section -->

## Band: data and behavior

Each band has its own members and operations

<!--
Introduce the next problem and give students a moment to switch context.
Suggested time: 1 min
-->

---

<!-- _class: code -->

## From a record to Band

```cpp
class Band {
private:
    std::string keyboard;
public:
    void set_keyboard_anon() {
        keyboard = "anon";
    }
};
```

Public methods change internal state.

<!--
Recall the public fields of the record. Band places operations in the type. Only keyboard is visible here. The full model retains guitar, vocal, drum, and bass. This setter does not itself enforce a business validation rule.
Full demo: Examples/L2_C04_D02.cpp
Suggested time: 3 min
-->

---

<!-- _class: trace -->

## Five fields belong to one band

```text
guitar    mutsumi
vocal     hatsune
drum      nyamu
bass      umiri
keyboard  saki
```

Field names belong to the type. Each object holds its own values.

<!--
Restore the five-member context after the keyboard-only view. Ask how parallel variables could be kept associated with one band, motivating encapsulation.
Suggested time: 2 min
-->

---

<!-- _class: question -->

## Objects have independent state

```cpp
Band a;
Band b;
a.set_keyboard_anon();
```

Does changing a automatically change b?

<!--
Use the preceding minimal class with its implicit default constructor and initially empty string. b is unaffected. Once the parameterized constructor is introduced, this default-construction syntax will no longer apply.
Suggested time: 3 min
-->

---

<!-- _class: trace -->

## Independent state in two objects

```text
before       a.keyboard=""   b.keyboard=""
a.set_keyboard_anon()
after        a.keyboard="anon"
             b.keyboard=""
```

Matching member names do not imply shared storage.

<!--
Use the minimal Band with implicit default construction. Band a; does not work with the later full five-argument constructor. Object names identify call targets.
Suggested time: 2 min
-->

---

<!-- _class: code -->

## private and public

```cpp
a.keyboard = "anon";  // error
a.set_keyboard_anon(); // OK
```

Member functions can access their class’s private members.

<!--
The first line is an intentional compile error. Test it separately. private restricts direct access outside the class while member functions retain access.
Full demo: Examples/L2_C04_D02.cpp
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Encapsulation provides one update interface

```cpp
void set_keyboard(const std::string& name) {
    if (name.empty()) return;
    keyboard = name;
}
```

The caller requests a change. The class decides whether to accept it.

<!--
This extra method illustrates a constraint. The original setter does not validate. Empty names are rejected here. Discuss whether silent rejection is sufficient or a bool return would help.
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Constructors establish initial state

```cpp
Band(std::string key) {
    keyboard = key;
}

Band a("saki");
```

The constructor has the class name and no return type.

<!--
Place the constructor in Band’s public section. The full Band accepts five member names. This reduced view uses one. Show assignment in the body before comparing member initialization.
Full demo: Examples/L2_C05_D01.cpp
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Parameterized and default construction

```cpp
Band a("saki"); // OK in the reduced class
// Band b;      // no matching constructor
```

Declaring this constructor prevents an implicit default constructor.

<!--
This is the reduced one-key constructor. If default creation is required, design a default constructor or default arguments and a valid initial state. Constructors need not always be public; this interface chooses public.
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Member initializer lists

```cpp
Band(std::string key)
    : keyboard(key) {}
```

keyboard is initialized directly from key.  
Members initialize in declaration order.

<!--
Contrast direct initialization with default construction followed by assignment. Declaration order controls member initialization. const and reference members need initialization. Keep the std::move detail in notes without promising speed.
Full demo: Examples/L2_C05_D02.cpp
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Declaration order controls initialization

```cpp
class Example {
    int first;
    int second;
public:
    Example() : second(2), first(1) {}
};
```

first still initializes before second.  
Writing the list in declaration order makes this clear.

<!--
Both initializers are independent constants. Reorder the list and show the compiler warning. Avoid a demonstration that reads an uninitialized member.
Suggested time: 2 min
-->

---

<!-- _class: code -->

## Reading and changing state

```cpp
void print_info() const {
    std::cout << keyboard << '\n';
}

void set_keyboard_anon() {
    keyboard = "anon";
}
```

The trailing const prevents changes to ordinary members.

<!--
Explain this for the class used here, which has no mutable members. A const Band can call print_info but not the setter. In the source model, get_guitar prints a name rather than returning a string.
Full demo: Examples/L2_C06_D01.cpp
Suggested time: 3 min
-->

---

<!-- _class: code -->

## What can a const object call?

```cpp
const Band band("saki");
band.print_info();       // OK
// band.set_keyboard_anon(); // error
```

Read-only access becomes part of the callable interface.

<!--
Use the one-field Band. Uncomment the setter call and read the diagnostic. The trailing const constrains access through this, unlike const on a parameter.
Suggested time: 2 min
-->

---

<!-- _class: practice -->

## Practice: complete a small Band

Keep one private string: keyboard  
Accept its initial value in a constructor  
Provide print and update methods  
Create two objects and change only one

<!--
Use initial values saki and eve. After modifying a, expect anon/eve. Require headers, the class terminator, and main. Return to the full five-member Band after the exercise.
Suggested time: 10 min
-->

---

<!-- _class: statement -->

## Reviewing the Band exercise

a starts as saki, b as eve  
After changing only a: anon / eve  
A const object can print  
Direct keyboard access outside the class fails to compile

<!--
Run successful and intentionally failing tests separately. Ask which rule each test checks. Confirm understanding beyond copying a class definition.
Suggested time: 3 min
-->

---

<!-- _class: code -->

## The five members of the full Band

```cpp
Band ave_mujica(
    "mutsumi", "hatsune", "nyamu",
    "umiri", "saki"
);
ave_mujica.print_info();
ave_mujica.live();
```

guitar, vocal, drum, bass, keyboard

<!--
Return to the full class definition in the demo file. Follow class_band: construct ave_mujica, then print_info and live. They print the member list and LIVE respectively.
Full demo: Examples/L2_C09_D01.cpp
Suggested time: 3 min
-->

---

<!-- _class: code -->

## A vector of bands

```cpp
std::vector<Band> live_bands;
live_bands.emplace_back(
    "hina", "aya", "maya", "chisato", "eve");
live_bands.emplace_back(
    "sayo", "yukina", "ako", "lisa", "rinko");
```

vector manages the collection. Band defines each object.

<!--
Include vector. emplace_back constructs an element at the end from the supplied arguments. Briefly mention that growth can invalidate existing references and pointers without adding an allocation lecture.
Full demo: Examples/L2_C06_D02.cpp
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Vector size and element access

```cpp
std::cout << live_bands.size() << '\n';
live_bands[0].print_info();
live_bands.at(1).print_info();
```

After two appends, size is 2 and valid indices are 0 and 1.

<!--
[] does not check bounds. at throws for an invalid index. emplace_back changes the size and constructs a new object, unlike assigning an existing element.
Suggested time: 2 min
-->

---

<!-- _class: code -->

## Which object does a loop change?

```cpp
for (Band band : live_bands) {
    band.set_keyboard_anon();
}

for (Band& band : live_bands) {
    band.set_keyboard_anon();
}
```

The first loop changes copies. The second changes stored objects.

<!--
Reuse the rule from Lesson 1. Use const Band& for read-only printing. Reset the data when comparing loops so that changes from the reference loop do not confuse the result.
Full demo: Examples/L2_C06_D02.cpp
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Read-only iteration over bands

```cpp
for (const Band& band : live_bands) {
    band.print_info();
}
```

Borrow each stored object and read through its const interface.

<!--
Compare copying Band, modifying through Band&, and reading through const Band&. Explain why print_info needs const and the setter cannot be called here.
Suggested time: 2 min
-->

---

<!-- _class: question -->

## Classes and containers checkpoint

What does a value, reference, or pointer parameter provide?  
When is an object’s initial state established?  
Why can a read-only method be const?

<!--
Ask students to explain these points using their own code, rather than only give final answers.
Suggested time: 5 min
-->

---

<!-- _class: section -->

## Inheritance

Extend Band with vocal_actor

<!--
Introduce the next problem and give students a moment to switch context.
Suggested time: 1 min
-->

---

<!-- _class: code -->

## MofoBand inherits Band

```cpp
class MofoBand : public Band {
protected:
    std::string vocal_actor;
public:
    void print_mofo_info() const {
        print_info();
        std::cout << vocal_actor << '\n';
    }
};
```

Reuse Band behavior and add the voice actor.

<!--
This view focuses on inheritance and a method. Add the constructor next. Derived code cannot directly access Band’s private fields, but can call its public methods. public inheritance permits use as a Band.
Full demo: Examples/L2_C07_D01.cpp
Suggested time: 3 min
-->

---

<!-- _class: code -->

## The base initializes first

```cpp
MofoBand(std::string gt, std::string vo,
         std::string dr, std::string ba,
         std::string key, std::string actor)
    : Band(gt, vo, dr, ba, key),
      vocal_actor(actor) {}
```

Band first, then vocal_actor, then the constructor body.

<!--
This is a constructor fragment inside the class. Open the complete demo to connect the five band member arguments. Band(...) in the body creates a temporary and cannot replace base initialization.
Full demo: Examples/L2_C07_D02.cpp
Suggested time: 4 min
-->

---

<!-- _class: statement -->

## Access to a protected member

MofoBand member functions: allowed  
MofoBand_New member functions: allowed under inheritance rules  
Direct object.vocal_actor in main: not allowed

<!--
Correct the misconception that only derived classes can access protected members. The declaring class can too. Object-expression and inheritance rules also matter. This page concerns the established public inheritance chain.
Full demo: Examples/L2_C08_D01.cpp
Suggested time: 3 min
-->

---

<!-- _class: code -->

## this points to the current object

```cpp
void change_actor(
    const std::string& new_actor) {
    this->vocal_actor = new_actor;
}
```

The left side is a member of this object. The right side is a parameter.

<!--
Demonstrate in MofoBand_New. const& borrows the parameter read-only. Assigning it to vocal_actor still assigns a string. this-> is optional here, not required for every member access.
Full demo: Examples/L2_C08_D02.cpp
Suggested time: 3 min
-->

---

<!-- _class: practice -->

## Practice: change the actor

Construct an object with actor amane  
Call change_actor("ayane")  
Print the updated information  
Explain why main cannot directly change the protected field

<!--
Have students edit main in the full demo rather than retype all constructor parameters. Verify that only the target object’s actor field changes.
Full demo: Examples/L2_C08_D02.cpp
Suggested time: 8 min
-->

---

<!-- _class: statement -->

## Tracing class_band

ave_mujica: construct, print_info, live  
live_bands: append two bands, iterate  
ave_mujica: get_guitar, change keyboard  
morfonica and lovelive: construct, change actor

<!--
Open class_band in the original integrated Lesson02.cpp. Step through in execution order and ask which object each call affects. ave_mujica is not in live_bands, so container updates do not update it.
Full demo: Examples/L2_C09_D01.cpp
Suggested time: 5 min
-->

---

<!-- _class: question -->

## Core lesson review

Which object owns this data?  
Does the function access a copy or the original?  
Which interface lets external code change it?

<!--
Use swap, the Band setter, and a vector reference loop as examples. Assign required Assessment-02 work. The following pages are optional extension material, so the core class can end here.
Suggested time: 3 min
-->

---

<!-- _class: section -->

## Optional extensions

Virtual functions, slicing, and ownership

<!--
Introduce the next problem and give students a moment to switch context.
Suggested time: 1 min
-->

---

<!-- _class: code -->

## Calling derived behavior through a base

```cpp
struct Base {
    virtual void live() const { /* ... */ }
    virtual ~Base() = default;
};
struct Derived : Base {
    void live() const override { /* ... */ }
};
```

A Base& referring to Derived dispatches live to Derived.

<!--
The original Band has no virtual members. Use these separate minimal types and demonstrate Base& b=d; b.live(). override checks matching. A virtual destructor supports deletion through a base pointer.
Full demo: Examples/L2_C09_D02.cpp
Suggested time: 4 min
-->

---

<!-- _class: code -->

## Copying by value can slice an object

```cpp
Derived d;
Base copied = d;
Base& borrowed = d;
```

copied contains only a Base object.  
borrowed still refers to the complete d.

<!--
Use the preceding types. copied.live calls Base and borrowed.live calls Derived. Connect this to choosing a container element type while retaining the existing vector<Band> teaching model.
Full demo: Examples/L2_C09_D02.cpp
Suggested time: 3 min
-->

---

<!-- _class: code -->

## Exclusive resource ownership

```cpp
std::unique_ptr<Band> owner = std::make_unique<Band>(
    "mutsumi", "hatsune", "nyamu",
    "umiri", "saki");
std::unique_ptr<Band> next = std::move(owner);
```

next receives ownership. owner becomes empty.  
The resource is released automatically at scope exit.

<!--
Include memory and utility. This is optional engineering material: the original Band values need no manual new/delete. unique_ptr is noncopyable. std::move is a cast; unique_ptr’s move constructor transfers ownership. An empty source is guaranteed here, not for every moved-from type.
Full demo: Examples/L2_C09_D03.cpp
Suggested time: 4 min
-->

---

<!-- _class: statement -->

## After class and challenge work

Required: Assessment-02 using the lesson interfaces  
Extra practice: choose weak topics from the exercise index  
Challenges: read the relevant extension material first

<!--
Remind students that public checks are not final grades and that they must actively submit. Refer to the notes and exercises for full explanations. Decide whether extensions are taught now or assigned as reading.
Suggested time: 2 min
-->
