# C++ 面向对象入门（一）

## 一、经典写法

假设现在有个很简单的需求：记录一只宠物的种类和名字，然后打印出来。

打开 [proc.cpp](proc.cpp) 的前半段，代码很直白：

```cpp
#include <iostream>
#include <string>

void print_name(const std::string &name)
{
    std::cout << "Its name is: " << name << '\n';
}

void print_kind(const std::string &kind)
{
    std::cout << "It is a " << kind << '\n';
}

int main()
{
    std::string kind = "cat";
    std::string name = "xiaohui";

    print_kind(kind);
    print_name(name);

    return 0;
}
```

运行输出：

```text
It is a cat
Its name is: xiaohui
```

说实话，如果需求就到这儿为止，这段代码写得挺好的，要是硬为了"面向对象"去包个 `class`，反而是瞎折腾。

不过仔细看一眼，这里藏着一个小隐患：程序里只有两个各自独立的 `std::string`。你知道 `kind` 和 `name` 描述的是同一只猫，但编译器不知道。万一哪天手滑写成 `print_kind(name)`，类型完全对得上，编译照样能过，跑出来就是 `It is a xiaohui`。

只有一只猫的时候，这点隐患根本算不上事。但需求很少会停在原地。

### 需求加码：管一群宠物

现在要求变了：

1. 同时管理多只宠物，还要加上年龄；
2. 能给某只宠物改名；
3. 能按名字查到对应的宠物。

如果还是沿用刚才的思路，没有"对象"这个概念，最顺手的写法就是每种属性建一个 `vector`，靠**下标一样**来表示它们属于同一只宠物（[proc.cpp](proc.cpp) 后半段）：

```cpp
void print_all(const std::vector<std::string> &kinds,
               const std::vector<std::string> &names,
               const std::vector<int> &ages)
{
    for (std::size_t i = 0; i < names.size(); ++i)
    {
        std::cout << names[i] << " is a " << kinds[i]
                  << ", age " << ages[i] << '\n';
    }
}

void rename(std::vector<std::string> &names, std::size_t index,
            const std::string &new_name)
{
    names[index] = new_name;
}

std::size_t find_by_name(const std::vector<std::string> &names,
                         const std::string &target)
{
    for (std::size_t i = 0; i < names.size(); ++i)
    {
        if (names[i] == target)
        {
            return i;
        }
    }
    return names.size(); // 约定返回 size() 表示没找到
}
```

`main` 里用起来是这样：

```cpp
std::vector<std::string> kinds{"cat", "dog", "rabbit"};
std::vector<std::string> names{"xiaohui", "wangcai", "tuanzi"};
std::vector<int> ages{3, 5, 1};

print_all(kinds, names, ages);

rename(names, 0, "huihui");
print_all(kinds, names, ages);

const std::size_t idx = find_by_name(names, "wangcai");
if (idx != names.size())
{
    std::cout << "found: " << names[idx] << " is a " << kinds[idx] << '\n';
}
```

这段代码能正常跑，逻辑也没写错。但你试着设想一下，后面再继续往里加功能会发生什么：

- **三个数组对齐全靠人肉维护。** 新增宠物要连续 `push_back` 三次，删宠物要同时删三个数组里的同一位。只要哪次漏了一行，或者顺序差了一位，`wangcai` 就莫名其妙变成一只兔子，而且程序不会崩溃，排查起来非常头疼。

- **加一个字段，到处跟着改。** 明天需求说要记录宠物的体重 `weight`，`print_all` 得加参数，所有调用它的地方也得跟着改。属性一多，函数参数列表越拖越长。

- **数据的约定全靠记性。** 假如约定"宠物名字不能为空"，即使你在 `rename` 里加了判断，`names` 本质上还是个普通的 `vector<string>`。过两周再加个"从用户输入批量修改名字"的功能，顺手直接改了 names[i] 却忘了判空，编译器不会有任何提醒，脏数据就这么混进去了。

---

## 二、换个思路

既然问题在于"数据太散"，那解决办法就很直接了：干脆自己定义一种新类型 `Pet`，把属于同一只宠物的数据和常用操作打包在一起。

按照 C++ 项目的常见组织方式，我们把这个版本拆成了三个文件：

- [Pet.hpp](Pet.hpp)：头文件，放 `Pet` 类的**声明**（有哪些数据、提供哪些接口）；
- [Pet.cpp](Pet.cpp)：源文件，放 `Pet` 成员函数的**具体实现**；
- [main.cpp](main.cpp)：主程序，引入 `"Pet.hpp"` 后创建并使用 `Pet` 对象。

先看 [Pet.hpp](Pet.hpp)：

```cpp
#include <string>

class Pet
{
private:
    std::string kind_;
    std::string name_;
    int age_;

public:
    Pet(const std::string &kind, const std::string &name, int age);

    const std::string &name() const;
    const std::string &kind() const;
    int age() const;

    // 唯一的改名入口，校验规则收口在这里
    void rename(const std::string &new_name);

    void print() const;
};
```

再看 [Pet.cpp](Pet.cpp)，里面用 `Pet::` 指明这些函数属于 `Pet` 类，并给出具体实现：

```cpp
#include "Pet.hpp"
#include <iostream>

Pet::Pet(const std::string &kind, const std::string &name, int age)
    : kind_(kind), name_(name), age_(age) {}

const std::string &Pet::name() const
{
    return name_;
}

void Pet::rename(const std::string &new_name)
{
    if (new_name.empty())
    {
        std::cout << "!! empty name rejected\n";
        return;
    }
    name_ = new_name;
}

void Pet::print() const
{
    std::cout << name_ << " is a " << kind_
              << ", age" << age_ << '\n';
}
```

> 注：本例的 [main.cpp](main.cpp) 没有调用 `kind()` 和 `age()`，所以 [Pet.cpp](Pet.cpp) 里暂时只实现了实际用到的成员函数；如果后续要调用它们，照着 `Pet::name()` 的写法补上定义即可。

有了 `Pet` 之后，[main.cpp](main.cpp) 里的辅助函数和 `main` 一下子清爽了很多：

```cpp
#include "Pet.hpp"

void print_all(const std::vector<Pet> &pets)
{
    for (const Pet &pet : pets)
    {
        pet.print();
    }
}

std::size_t find_by_name(const std::vector<Pet> &pets, const std::string &target)
{
    for (std::size_t i = 0; i < pets.size(); ++i)
    {
        if (pets[i].name() == target)
        {
            return i;
        }
    }
    return pets.size();
}
```

```cpp
Pet cat("cat", "xiaohui", 3);
cat.print();

std::cout << "----------------\n";

std::vector<Pet> pets{
    Pet("cat", "xiaohui", 3),
    Pet("dog", "wangcai", 5),
    Pet("rabbit", "tuanzi", 1),
};

print_all(pets);

pets[0].rename("huihui");
pets[0].rename(""); // 会被拦下来，名字保持不变
std::cout << "---- after rename ----\n";
print_all(pets);

const std::size_t idx = find_by_name(pets, "wangcai");
if (idx != pets.size())
{
    std::cout << "found: ";
    pets[idx].print();
}
```

因为拆成了多个源文件，编译时需要把 [main.cpp](main.cpp) 和 [Pet.cpp](Pet.cpp) 一起交给编译器：

```bash
g++ -std=c++17 -Wall -Wextra -o main main.cpp Pet.cpp && ./main
```

回头对照刚才那几个痛点，看看发生了什么变化：

1. **不会再错位了。** `kind_`、`name_`、`age_` 绑在同一个 `Pet` 对象里，增删改查都是以"一整只宠物"为单位。

2. **加字段影响范围变小了。** 以后要给 `Pet` 加个 `weight_`，改 `Pet` 内部和创建它的地方就行，`print_all`、`find_by_name` 这些外围函数的签名一个字都不用动。

3. **规则有了统一的入口。** `name_` 设成了 `private`，外面没法直接写 `pets[0].name_ = ""`，想改名字只能走 `rename()`。

乍一看，好像只是把数据和函数全部塞到了大括号里。

但是实际上，当你这么做的时候，你已经把所有相同类型的东西全部绑在了一起，和外部调用解耦开来，从而变得更加易用且更加容易维护。

---

## 三、拆开看看

刚才那段 `Pet` 代码虽然不长，但几乎涵盖了写第一个 C++ 类所需的全部核心语法。我们逐块拆开来看。

### 3.1 类和对象

```cpp
Pet                           // 类（class）：一种类型定义，相当于图纸
Pet cat("cat", "xiaohui", 3); // 对象（object）/ 实例（instance）：按图纸造出来的具体个体
```

可以简单类比成 `int` 和 `int x = 3;`。`Pet` 本身只是个类型名，描述"一只宠物应该包含哪些数据、能做哪些操作"；每定义一个 `Pet` 变量，才真正在内存里多出了一只独立的宠物。

平时设计类的时候，脑子里（或者草稿纸上）可以先列个极简清单，分清哪些是内部数据（`-` 表示私有），哪些是对外操作（`+` 表示公有）：

```text
┌──────────────────────┐
│         Pet          │
├──────────────────────┤
│ - kind_ : string     │
│ - name_ : string     │
│ - age_  : int        │
├──────────────────────┤
│ + Pet(kind,name,age) │
│ + name()  : string   │
│ + kind()  : string   │
│ + age()   : int      │
│ + rename(new_name)   │
│ + print()            │
└──────────────────────┘
```

那又有一个问题，什么是私有，什么是公有？

### 3.2 `private` 和 `public`

类里的变量叫**成员变量**，函数叫**成员函数**。`private:` 和 `public:` 用来划定访问权限：

- `private:` 后面的成员，只有类自己的成员函数能碰，外面（比如 `main`）一碰就会**编译报错**。
- `public:` 后面的成员是对外开放的接口，谁都可以调用。

关于访问控制，有三个需要注意的点：

1. `class` 默认是 `private` 的（`struct` 默认是 `public` 的），所以不写 `public:` 的话，连构造函数在外面都调不到。
2. `private` 是在**编译期**做检查的，它防的是写代码时手滑破坏数据约束，不是什么加密手段。
3. 习惯上把数据成员放在 `private` 里，通过 `public` 函数去读或改，这样哪天想加校验逻辑或者换底层存储方式，调用方不用跟着大改。

### 3.3 构造函数与初始化列表

```cpp
// Pet.hpp 中声明
Pet(const std::string &kind, const std::string &name, int age);

// Pet.cpp 中实现
Pet::Pet(const std::string &kind, const std::string &name, int age)
    : kind_(kind), name_(name), age_(age) {}
```

这个长得有点特别的函数叫**构造函数（constructor）**，用来保证对象一创建出来就有合理的初始值。它有几个特点：

- **名字必须和类名完全一致，而且不能写返回类型**（连 `void` 都不能写）。
- **对象创建时自动执行**，比如写下 `Pet cat("cat", "xiaohui", 3);` 的那一刻，它就会被调用。
- **冒号后面的是初始化列表**。尽量用初始化列表给成员赋初值，而不是全塞在 `{}` 函数体里赋值；拆分成头文件和源文件时，初始化列表写在 `.cpp` 的实现处。
- **写了带参构造，编译器就不送默认构造了。** 如果你一个构造函数都不写，编译器会自动生成一个无参的默认构造函数；但只要你自己写了带参的构造函数（哪怕只带一个没有默认值的参数），编译器就不再自动生成无参版本了——这时候再去写 `Pet p;` 就会报错。

### 3.4 成员函数与 `const`

调用成员函数用点号 `.`：

```cpp
cat.print();
cat.rename("huihui");
```

你可能注意到了，`name()`、`print()` 这些函数的小括号后面多了一个 `const`：

```cpp
// Pet.hpp 中声明
const std::string &name() const;
//                        ^^^^^ 表示这个函数承诺不会修改对象内部的数据

// Pet.cpp 中实现（声明和实现处都必须写 const）
const std::string &Pet::name() const
{
    return name_;
}
```

为什么要多写这个 `const`？看回 [main.cpp](main.cpp) 里的 `print_all`：

```cpp
void print_all(const std::vector<Pet> &pets)
{
    for (const Pet &pet : pets)
    {
        pet.print(); // pet 是 const 引用，只能调用带 const 的成员函数
    }
}
```

C++ 的规矩很死：**`const` 对象（包括 `const` 引用）只能调用标了 `const` 的成员函数**。如果 `print()` 忘了加 `const`，上面那行 `pet.print()` 直接编译不过。而且当声明和实现拆开写时，`.hpp` 和 `.cpp` 两边都必须加上 `const`，少写一边编译器就会认为它们是不同的函数。所以养成习惯：只要一个成员函数只读数据、不改对象状态，随手在后面加上 `const`。

### 3.5 声明与实现分离（`.hpp` 与 `.cpp`）

第一次看到一个类被拆成 [Pet.hpp](Pet.hpp) 和 [Pet.cpp](Pet.cpp) 两个文件，可能会觉得有点绕，其实分工非常直观：

- **头文件（`.hpp` / `.h`）放声明**：相当于"接口说明书"，告诉外界 `Pet` 有哪些成员、提供哪些函数，但只写函数签名、不写函数体。需要用到 `Pet` 的地方（比如 [main.cpp](main.cpp)）写一句 `#include "Pet.hpp"` 就行。
- **源文件（`.cpp`）放实现**：先 `#include "Pet.hpp"`，再用**作用域解析运算符 `::`**（`Pet::name`、`Pet::rename`、`Pet::print`）指明这些函数归属于 `Pet` 类，并补齐具体的函数体。
- **编译时要带上所有 `.cpp`**：头文件是被 `#include` 直接展开进源文件的，不需要出现在编译命令里；但 [main.cpp](main.cpp) 和 [Pet.cpp](Pet.cpp) 都是源文件，必须一起传给 `g++`：
  ```bash
  g++ -std=c++17 -Wall -Wextra -o main main.cpp Pet.cpp
  ```
  如果只编译 `main.cpp`，编译阶段能通过（因为 `Pet.hpp` 里有声明），但链接阶段会报错 `undefined reference`（找不到 `Pet.cpp` 里的函数实现）。

> 小贴士：实际工程里通常还会在 `.hpp` 的最开头加上一句 `#pragma once`（头文件保护），防止同一个头文件被间接 `#include` 多次时引发类重复定义错误。下一篇的 `pet.hpp` 里就会见到它。

### 3.6 内存里到底长什么样？

写完两个对象后，很多人会有个直觉上的疑问：

```cpp
Pet cat("cat", "xiaohui", 3);
Pet dog("dog", "wangcai", 5);
cat.print();
dog.print();
```

`cat.print()` 和 `dog.print()` 调的都是 `Pet::print`，它怎么知道这次要打 `xiaohui`，下次要打 `wangcai`？

看一眼内存里的排布：

```text
栈区（每个对象各存一份数据）：
  cat : [ kind_="cat" | name_="xiaohui" | age_=3 ]
  dog : [ kind_="dog" | name_="wangcai" | age_=5 ]

代码区（所有 Pet 共用同一份函数代码）：
  Pet::print()   Pet::rename()   Pet::name() ...
```

- **成员变量一人一份**：每造一个对象，就多一块存放 `kind_`、`name_`、`age_` 的内存。
- **成员函数全员共用**：函数代码在程序里只有一份，不会因为你创建了一万只猫就复制一万份 `print()`。

至于函数怎么区分当前在操作谁——编译器在背后悄悄帮我们多传了一个隐藏参数，也就是指向当前对象的指针 `this`：

```cpp
cat.print();       // 我们写的
Pet::print(&cat);  // 编译器大致会翻译成这样
```

所以在 `print()` 里写的 `name_`，本质上就是 `this->name_`。现在先记住"数据按对象分份、函数大家共用、靠 `this` 对号入座"就够了，下一篇引入堆内存、继承和多态后，我们还会继续把这套内存模型展开讲透。

### 3.7 顺便一提：命名习惯

[Pet.hpp](Pet.hpp)、[Pet.cpp](Pet.cpp) 和 [main.cpp](main.cpp) 里用了一些 C++ 项目里很常见的命名风格，提前说一声——**这些都是习惯，不是语法要求**：

- 类名首字母大写：`Pet`、`Subject`
- 变量和函数名小写：`cat`、`print()`、`rename()`
- 成员变量末尾加下划线：`kind_`、`name_`（一眼就能区分它是成员变量还是函数参数，也不会撞名）
- 类对应的头文件和源文件通常成对命名，比如 `Pet.hpp` / `Pet.cpp`（或全小写 `pet.hpp` / `pet.cpp`）

---

## 四、退后一步：什么是编程范式？

看完了 [proc.cpp](proc.cpp) 和面向对象版本（[Pet.hpp](Pet.hpp) / [Pet.cpp](Pet.cpp) / [main.cpp](main.cpp)）两套写法，现在再回头看"编程范式"这个词，就好懂多了。

**编程范式（programming paradigm）**说白了就是"组织代码的套路"。同一个问题，你可以按不同的视角去拆解：

- **面向过程（Procedural）**：把程序看成"数据 + 一连串操作步骤"。先想好数据怎么存，再一步步写函数去处理它。
- **面向对象（Object-Oriented）**：把程序看成"一群各自管好自己数据的对象"。先想好系统里有哪些角色（对象），每个角色有什么状态、能干什么事，再让它们互相配合。

如果把视野再拉远一点，常见的编程范式大致分两大阵营：

```text
编程范式
├─ 命令式（告诉计算机"一步步怎么做"）
│  ├─ 面向过程   C、Pascal
│  └─ 面向对象   C++、Java、C#
└─ 声明式（告诉计算机"我要什么结果"）
   ├─ 函数式     Haskell、Lisp
   └─ 逻辑式     Prolog
```

这里有两点值得记住：

1. **面向过程和面向对象其实都属于命令式**，都在一步步改状态、下指令，区别只是命令按"流程步骤"组织，还是按"对象"组织。
2. **C++ 不是纯面向对象语言，而是多范式语言。** 它同时支持面向过程、面向对象、泛型（模板/STL）和一定的函数式写法（lambda）。所以别走极端，觉得学了 OOP 以后所有函数都必须塞进 `class` 里——就像 [main.cpp](main.cpp) 里的 `print_all` 和 `find_by_name`，做成普通自由函数反而更干净。

---

## 五、动手练一下

接下来，让我们进入紧张刺激的练习环节 (*^_^*)

### 题目：设计一个 `Subject`（学科）类

要求：

1. 至少包含两个 `private` 成员变量（比如学科名、任课老师）；
2. 提供构造函数，让对象一创建就有确定的初始状态；
3. 至少提供一个 `public` 成员函数用来打印信息；
4. 在 `main` 函数里创建"计算机科学"和"数学"两个对象并打印出来。

---

如果感觉有一些困难，可以尝试先跑通下面这个代码，然后尝试进行一些修改：

```cpp
#include <iostream>
#include <string>

class Subject
{
private:
    std::string name_;
    std::string teacher_;

public:
    Subject(const std::string &name, const std::string &teacher)
        : name_(name), teacher_(teacher)
    {
    }

    void print() const
    {
        std::cout << name_ << " / " << teacher_ << '\n';
    }
};

int main()
{
    Subject cs("Computer Science", "Prof. Wang");
    Subject math("Mathematics", "Prof. Li");

    cs.print();
    math.print();

    return 0;
}
```

完整参考实现见 [exercise/answer_subject.cpp](exercise/answer_subject.cpp)（练习为了方便写在了单个文件里，你也可以试着按 `Pet.hpp` / `Pet.cpp` 的方式拆分）。

---

## 六、阶段小结

到这里，你已经用上了面向对象最基础的那一层：**把数据和规则装进自定义类型里，并用 `.hpp` / `.cpp` 把接口声明与实现分开**。

其实这一篇里已经偷偷摸到了 OOP 四个核心概念的边——用 `Pet` 提炼出我们关心的属性是**抽象**，用 `private` 和 `rename()` 守住数据规矩是**封装**。后面继续往下学，我们会遇到新的问题：如果猫和狗各有各的行为怎么办（**继承**）？如果希望 `pets[i]->print()` 对不同动物自动表现出不同行为怎么办（**多态**）？对象销毁时怎么清理资源（**析构函数**），以及继承和多态在内存里到底是怎么落地的（**内存模型**）？这些都在下一篇 [tutorial2.md](../02_four_pillars/tutorial2.md) 里展开。
