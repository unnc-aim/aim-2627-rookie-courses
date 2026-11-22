# C++ 面向对象入门（二）

上一篇 [tutorial1.md](../01_basics/tutorial1.md) 里，我们把散落的数组收拢进了一个 `Pet` 类，并拆成了 `Pet.hpp`、`Pet.cpp` 和 `main.cpp`，管理了三只宠物：`xiaohui`（猫）、`wangcai`（狗）和 `tuanzi`（兔子）。

但到目前为止，`Pet` 还只是个"能存数据、能校验名字的盒子"。这一篇我们继续顺着这个宠物程序往下加需求，看看代码在什么地方开始不够用——在这个过程中，面向对象最常提的四个词：**封装、继承、多态、抽象**，会一个接一个自然冒出来。最后，我们还会把前面用到却还没展开的两个底层关键拼图补齐：**析构函数**与**对象内存模型**。

> 本篇最终的完整代码拆成了三个文件：
> - [pet.hpp](pet.hpp)：抽象基类 `Pet` 与具体子类 `Cat` / `Dog` / `Rabbit` 的声明
> - [pet.cpp](pet.cpp)：所有类成员函数的具体实现
> - [main.cpp](main.cpp)：使用这些类的演示入口（`greet_all` 与 `main`）
>
> 在 `02_four_pillars` 目录下可以用下面这条命令编译运行：
>
> ```bash
> g++ -std=c++17 -Wall -Wextra -o oop2 main.cpp pet.cpp && ./oop2
> ```

---

## 一、封装

先回头看上一篇的 `Pet`，它里面存了 `int age_;`。

程序跑了一年之后，新问题来了：**存固定年龄是个坏主意**——跨过新年，所有宠物的 `age_` 全都过时了。更合理的做法是改存**出生年份 `birth_year_`**，需要年龄的时候拿当前年份减一下。

好在上一篇我们把 `age_` 放在了 `private` 里，外面所有地方读年龄调用的都是 `pet.age()`。所以现在改起来非常轻松（下面先用精简代码展示思路，完整分文件写法见 [pet.hpp](pet.hpp) 和 [pet.cpp](pet.cpp)）：

```cpp
// pet.cpp 中定义了当前年份常量
constexpr int kCurrentYear = 2026;

class Pet
{
private:
    std::string name_;
    int birth_year_; // 从 age_ 换成了 birth_year_

public:
    Pet(const std::string &name, int birth_year)
        : name_(name), birth_year_(birth_year)
    {
    }

    const std::string &name() const { return name_; }
    int age() const { return kCurrentYear - birth_year_; } // 对外接口不变

    void rename(const std::string &new_name)
    {
        if (new_name.empty())
        {
            std::cout << "!! empty name rejected\n";
            return;
        }
        name_ = new_name;
    }
};
```

注意：`Pet` 内部的存储结构变了，但外面所有调用 `pet.age()` 的代码**一行都不用改**。假如当初图省事把 `age_` 设成了 `public`，外面二十个地方都写了 `cat.age_`，现在就得一处处翻出来改。

这就是**封装（Encapsulation）**真正干的两件事：

1. **保护数据不变**：像"名字不能为空"这种约束收口在 `rename()` 里，外面没法绕过去直接改 `name_`，防止了意外修改。
2. **隔离内部变化**：只要对外暴露的函数签名（接口）不变，内部把 `age_` 换成 `birth_year_`，或者换别的数据结构，调用方完全感知不到，而且无需变更。

---

## 二、继承：猫和狗开始不一样了

接下来需求继续加码。现在的宠物不再只是"打印名字和年龄"，不同动物有了各自的特色：

- 每种宠物都会叫，但叫声不一样：猫 `Meow~`，狗 `Woof!`，兔子 `Squeak!`；
- 猫会抓老鼠（`catch_mouse()`），狗会捡球（`fetch()`），兔子既不抓老鼠也不捡球。

如果还硬把所有东西塞在一个 `Pet` 类里，代码很快就会长歪：

```cpp
// 硬塞在一个类里的丑陋写法
void Pet::speak() const
{
    if (kind_ == "cat")
        std::cout << name_ << ": Meow~\n";
    else if (kind_ == "dog")
        std::cout << name_ << ": Woof!\n";
    else if (kind_ == "rabbit")
        std::cout << name_ << ": Squeak!\n";
}
```

而且最尴尬的是：`catch_mouse()` 和 `fetch()` 写在哪儿？写在 `Pet` 里的话，一只狗也能调 `wangcai.catch_mouse()`，这明显不合理。以后每加一种新宠物，还得回来把 `Pet` 翻开，在每一个 `if-else` 里补一段。

既然猫、狗、兔子既有**共同点**（都有名字、出生年份、都能改名、都能算年龄），又有**各自独有的东西**，那就把它们拆开：

- 共有的部分留在**基类（父类）** `Pet` 里；
- 各自特有的部分放到**派生类（子类）** `Cat`、`Dog`、`Rabbit` 里，让它们**继承（Inheritance）** `Pet`。

写法长这样：

```cpp
class Cat : public Pet
{
public:
    Cat(const std::string &name, int birth_year)
        : Pet(name, birth_year) // 调用父类构造函数
    {
    }

    void catch_mouse() const
    {
        std::cout << name() << " caught a mouse!\n";
    }
};

class Dog : public Pet
{
public:
    Dog(const std::string &name, int birth_year)
        : Pet(name, birth_year)
    {
    }

    void fetch() const
    {
        std::cout << name() << " fetched the ball!\n";
    }
};
```

在 [main.cpp](main.cpp) 的前半段里，可以直接创建具体子类并调用它们各自的专属行为：

```cpp
Cat xiaohui("xiaohui", 2023);
Dog wangcai("wangcai", 2021);
xiaohui.catch_mouse();
wangcai.fetch();
```

这里有三个新语法点需要留意：

1. **`class Cat : public Pet`**：表示公有继承。继承之后，`Cat` 自动拥有 `Pet` 里的 `name()`、`age()`、`rename()`，不用重复写一遍。
2. **子类构造要先把父类构造好**：初始化列表里的 `: Pet(name, birth_year)` 就是在委托父类把 `name_` 和 `birth_year_` 初始化好。
3. **第三个访问说明符 `protected`**：
   - `private`：只有自己能碰（连子类也不能直接访问 `name_`，所以上面 `Cat` 里调的是公有的 `name()`）；
   - `protected`：自己和子类能碰，外面不能碰；
   - `public`：谁都能碰。

   一般经验是：成员变量依然尽量放 `private`，子类也通过父类提供的函数访问，免得以后改父类内部实现时把一堆子类全牵连坏；只有确实需要专门开放给子类用的辅助函数，再考虑放 `protected`。

---

## 三、多态

拆成 `Cat`、`Dog`、`Rabbit` 之后，各自调 `xiaohui.catch_mouse()`、`wangcai.fetch()` 都很顺手了。

但紧接着会碰到一个非常现实的问题：**怎么把它们重新放进同一个 `vector` 里统一管理？**

比如我想写一个 `greet_all`，遍历家里所有宠物，挨个打印信息并让它们叫一声。这里有两个坑：

### 坑 1：不能直接写 `std::vector<Pet>`

如果你试图把一个 `Cat` 按值放进 `std::vector<Pet>`，C++ 会发生**对象切片（object slicing）**——容器里每个格子只留了 `Pet` 那么大的空间，塞进去的 `Cat` 会被硬生生切掉子类那一部分，只剩一个光秃秃的 `Pet`（背后的内存原因会在第六节画图拆解）。

所以想要用基类统一存放不同的子类，必须用**指针**（现代 C++ 推荐智能指针 `std::unique_ptr<Pet>`）或者**引用**（函数参数用 `const Pet &`）。

### 坑 2：不加 `virtual`，调的永远是父类的函数

就算用了指针或引用，如果 `Pet::speak()` 只是普通成员函数，编译器在编译期看到指针类型是 `Pet*`，就会死板地去调 `Pet::speak()`，根本不管它实际指向的是猫还是狗。

解决办法是给 `Pet` 里需要"因子类而异"的函数加上 **`virtual`**（虚函数），子类重写的时候在后面加上 **`override`**：

```cpp
class Pet
{
    // ...
public:
    virtual ~Pet() = default; // 多态基类务必加虚析构函数（第五节详解）

    virtual std::string kind() const { return "pet"; }
    virtual void speak() const { std::cout << "...\n"; }

    void print() const
    {
        std::cout << name_ << " is a " << kind()
                  << ", age " << age() << '\n';
    }
};

class Cat : public Pet
{
public:
    Cat(const std::string &name, int birth_year) : Pet(name, birth_year) {}

    std::string kind() const override { return "cat"; }
    void speak() const override { std::cout << name() << ": Meow~\n"; }
    void catch_mouse() const { std::cout << name() << " caught a mouse!\n"; }
};
```

> **分文件写法注意点**：把声明和实现拆到 [pet.hpp](pet.hpp) 和 [pet.cpp](pet.cpp) 时，`virtual`、`override`（以及下一节的 `= 0`）**只能写在 `.hpp` 的类声明里**，在 `.cpp` 中类外实现时**不能重复写**：
>
> ```cpp
> // pet.hpp（声明）
> class Cat : public Pet
> {
> public:
>     Cat(const std::string &name, int birth_year);
>     std::string kind() const override;
>     void speak() const override;
>     void catch_mouse() const;
> };
>
> // pet.cpp（实现：不写 virtual / override）
> std::string Cat::kind() const { return "cat"; }
> void Cat::speak() const { std::cout << name() << ": Meow~\n"; }
> ```

现在再看 [main.cpp](main.cpp) 里的 `greet_all` 和 `main`：

```cpp
void greet_all(const std::vector<std::unique_ptr<Pet>> &pets)
{
    for (const auto &pet : pets)
    {
        pet->print();
        pet->speak();
    }
}

int main()
{
    // ...
    std::vector<std::unique_ptr<Pet>> pets;
    pets.push_back(std::make_unique<Cat>("xiaohui", 2023));
    pets.push_back(std::make_unique<Dog>("wangcai", 2021));
    pets.push_back(std::make_unique<Rabbit>("tuanzi", 2025));

    greet_all(pets);
}
```

`greet_all` 部分的运行输出：

```text
xiaohui is a cat, age 3
xiaohui: Meow~
wangcai is a dog, age 5
wangcai: Woof!
tuanzi is a rabbit, age 1
tuanzi: Squeak!
```

同一句 `pet->speak()`，指向猫就喵喵叫，指向狗就汪汪叫，指向兔子就吱吱叫——甚至 `Pet::print()` 内部调 `kind()` 时，也会自动跳到对应子类的 `kind()`。

这就是**多态（Polymorphism）**：**用同一套调用代码，根据对象运行时的真实类型，执行不同的行为。**

多态最大的好处体现在扩展上：哪天家里新来了一只鸭子，你只需要新写一个 `class Duck : public Pet`，实现它的 `kind()` 和 `speak()`，`greet_all` 这边一个字都不用改。

> 两个注意点：
> - **子类重写虚函数一律写上 `override`**。它不是语法强制的，但如果哪天你不小心把函数名拼错、或者漏了个 `const`，编译器会立刻报错提醒你，不会悄悄变成一个全新函数。
> - **多态基类的析构函数必须写成 `virtual ~Pet() = default;`**。为什么？下一节讲完抽象后，我们在第五节专门把析构函数讲透。

---

## 四、抽象

回头看一眼上面 `Pet` 里的这两行：

```cpp
virtual std::string kind() const { return "pet"; }
virtual void speak() const { std::cout << "...\n"; }
```

仔细琢磨一下，这两行其实挺勉强的：
- 现实里根本没有一种动物，它既不是猫、也不是狗，品种就叫 `"pet"`，叫声是 `"..."`；
- 万一有人在 `main` 里顺手写了 `Pet p("mystery", 2024);`，或者新写了个 `class Hamster : public Pet` 却忘了重写 `speak()`，程序照样能编译通过，跑出来就是莫名其妙的 `"pet"` 和 `"..."`。

更好的做法是把这两句改成**纯虚函数**（在末尾写 `= 0`），这也是 [pet.hpp](pet.hpp) 最终的写法：

```cpp
// pet.hpp
#pragma once

#include <string>

class Pet
{
private:
    std::string name_;
    int birth_year_;

public:
    Pet(const std::string &name, int birth_year);
    virtual ~Pet() = default;

    const std::string &name() const;
    int age() const;
    void rename(const std::string &new_name);

    // 纯虚函数：具体种类和叫声由子类实现
    virtual std::string kind() const = 0;
    virtual void speak() const = 0;

    void print() const;
};
```

加了 `= 0` 之后，`Pet` 就成了一个**抽象类（abstract class）**，带来两个实实在在的约束：

1. **禁止直接造出"泛泛的宠物"**：在 [main.cpp](main.cpp) 里写 `Pet p("mystery", 2024);` 会直接编译报错，想创建对象只能创建具体的 `Cat`、`Dog`、`Rabbit`。
2. **强制子类履约**：任何继承 `Pet` 的子类，必须自己把 `kind()` 和 `speak()` 实现出来，少写一个都编译不过。

这正是**抽象（Abstraction）**落地到代码里的样子：
- 在思考阶段，抽象意味着**提炼共性、忽略无关细节**（从各种动物里抽出"有名字、有年龄、会叫"这几个我们关心的特征）；
- 在代码层面，抽象类负责定下**"能做什么"的统一规范**（`kind()`、`speak()`），把**"具体怎么做"**彻底交给各个子类去实现。

顺带一提：如果一个抽象类里连成员变量都没有、全是 `= 0` 的纯虚函数（再加上一个虚析构函数），它就是 C++ 里最纯粹的**接口（interface）**——只定合同，不带任何数据和实现。

---

## 五、析构函数：对象离开时发生了什么？

上一篇我们学了构造函数——它负责对象**出生**时的初始化。那对象**销毁**的时候呢？这就轮到**析构函数（Destructor）**登场了。

### 5.1 什么是析构函数？

析构函数是在对象生命周期结束、内存即将被回收前的最后一刻，由编译器自动执行的"善后清理"函数——比如释放动态申请的内存、关闭打开的文件、断开网络连接等。

对照构造函数来看，析构函数有几个固定特征：

```cpp
class Pet
{
public:
    Pet(const std::string &name, int birth_year); // 构造函数：出生时调用
    virtual ~Pet() = default;                     // 析构函数：销毁前自动调用
};
```

- **名字是波浪号加类名**：`~Pet()`；
- **没有返回值**（连 `void` 都不能写）；
- **不能带参数**：因此一个类只能有一个析构函数，不能重载；
- **由系统自动调用**：平时不需要（也不要随便）手动去调 `cat.~Pet()`。

如果你自己不写析构函数，编译器会自动生成一个默认析构函数，按成员变量声明的**逆序**依次销毁每个成员——比如 `std::string name_` 自己带了析构函数，销毁时会自动把字符串占用的堆内存还给系统。

那为什么 [pet.hpp](pet.hpp) 里还要特意写一句 `virtual ~Pet() = default;`？
- `= default` 的意思是：**"清理逻辑交给编译器按默认规则生成就行，我不用手写"**；
- 特意把它写出来，是为了在前面加上 **`virtual`**。

### 5.2 构造与析构的顺序

理解对象什么时候"生"、什么时候"死"，记住三条规律：

1. **同一作用域内的局部对象：后构造的先析构（LIFO，先进后出）**。
   看 [main.cpp](main.cpp) 的开头：
   ```cpp
   Cat xiaohui("xiaohui", 2023); // 1. 先构造
   Dog wangcai("wangcai", 2021); // 2. 后构造
   // ... 离开 main() 的右大括号时：先析构 wangcai，再析构 xiaohui
   ```
   因为局部变量压在函数调用栈上，离开作用域时就像拆叠起来的盘子一样，从最上面的开始拆。

2. **继承体系下：构造先父后子，析构先子后父**。
   构造一只 `Cat` 时，必须先把地基 `Pet` 建好，再构造 `Cat` 自己的部分；销毁时顺序刚好反过来——先拆 `Cat` 自己的部分，再拆 `Pet`：

   ```text
   创建 Cat xiaohui:    Pet()  ───────▶  Cat()
                                           │
                                    (正常使用对象)
                                           │
   销毁 Cat xiaohui:    ~Pet() ◀───────  ~Cat()
   ```

   原因很直白：`~Cat()` 里可能还会用到从 `Pet` 继承来的接口或数据（比如调用 `name()` 打印日志），如果先把 `Pet` 拆没了，`~Cat()` 访问它就会直接出事。

3. **堆上对象与 RAII：为什么用 `std::unique_ptr` 而不是裸 `new` / `delete`？**
   如果手动写 `Pet *p = new Cat("xiaohui", 2023);`，这只猫活在堆上，函数结束时编译器**不会**帮它调析构函数，必须你亲手写 `delete p;`。一旦漏写、或者函数半路 `return` / 抛异常，就会发生**内存泄漏**。

   而 [main.cpp](main.cpp) 用的是：

   ```cpp
   std::vector<std::unique_ptr<Pet>> pets;
   pets.push_back(std::make_unique<Cat>("xiaohui", 2023));
   ```
   
   `std::unique_ptr` 本身是个托管指针的小对象。当 `main()` 结束、局部变量 `pets` 离开作用域时，`vector` 会销毁里面的每一个 `unique_ptr`，而每个 `unique_ptr` 的析构函数都会自动对自己管着的堆对象执行 `delete`，进而触发 `Cat`、`Dog`、`Rabbit` 的析构函数。

   这种**"把资源（堆内存、文件、锁）绑定到对象的生命周期上：构造时获取，析构时自动释放"**的思想，叫 **RAII（Resource Acquisition Is Initialization，资源获取即初始化）**，是现代 C++ 管理资源最核心的习惯。

### 5.3 为什么多态基类必须有虚析构函数？

现在回来看 [pet.hpp](pet.hpp) 里那句 `virtual ~Pet() = default;`。

设想一个子类自己新增了需要释放资源的成员——比如后面练习 2 里的 `LabCourse` 继承了 `Course`，并且自己多了一个私有成员 `std::string lab_room_`（或者某个子类打开了一个文件、申请了一块动态缓冲区）。然后我们像 [main.cpp](main.cpp) 一样，通过基类智能指针 `std::unique_ptr<Course>` 来管理它。

当 `unique_ptr<Course>` 离开作用域、执行 `delete base_ptr` 时，会发生两种截然不同的结果：

- **如果基类析构函数没有 `virtual`**（即只写了 `~Course()`）：
  编译器只认得指针的静态类型是 `Course*`，于是直接去调 `Course::~Course()`，**完全跳过 `LabCourse::~LabCourse()`**！结果就是 `lab_room_` 内部申请的堆内存（或打开的文件句柄）根本没被释放（在 C++ 标准中，通过没有虚析构函数的基类指针 `delete` 派生类对象属于**未定义行为 UB**）。
- **如果基类析构函数加了 `virtual`**（即 `virtual ~Course() = default;`）：
  销毁时会按多态规则先动态找到真实类型的析构函数 `LabCourse::~LabCourse()` 把 `lab_room_` 清理干净，再自动向上执行 `Course::~Course()`，一层不落。

---

## 六、深入一点：C++ 对象的内存模型

在上一篇 [tutorial1.md](../01_basics/tutorial1.md) 的"3.6 内存里到底长什么样？"里，我们看过最简单的情形：局部对象住在栈区，成员函数住在代码区，靠隐藏的 `this` 指针区分谁在调函数。

到了这一篇，我们引入了 `std::make_unique`、继承、对象切片、虚函数和虚析构函数——把它们放回内存视角里一看。

### 6.1 内存分区：`main.cpp` 里的对象都住在哪？

运行 [main.cpp](main.cpp) 时，程序用到的数据和代码主要分布在三块内存区域里：

- **栈区（Stack）**：存放函数内的局部变量，由编译器自动分配和回收，离开作用域立刻析构。比如 `main.cpp` 里的 `xiaohui`、`wangcai`，以及 `pets` 这个 `vector` 对象本身（它的控制头）。
- **堆区（Heap）**：由程序在运行期动态申请，生命周期不绑定在某一次函数调用的栈帧里。比如 `std::make_unique<Cat>(...)` 创建出的 `Cat` / `Dog` / `Rabbit` 对象本体就住在堆区（`pets` 内部存放 3 个 `unique_ptr` 的数组也在堆区），靠 `unique_ptr` 的析构函数在离开作用域时自动回收。
- **代码区 / 只读数据区**：存放所有成员函数的机器码（`Pet::print`、`Cat::speak` 等）以及各类的**虚函数表（vtable）**，全程序共用一份，不随对象个数复制。

把 [main.cpp](main.cpp) 运行到 `greet_all(pets)` 那一刻的内存画出来，大致长这样：

```text
栈区 (Stack)                            堆区 (Heap)
┌──────────────────────────────────┐    ┌────────────────────────────────────────┐
│ xiaohui (Cat)                    │    │ pets array (3 x unique_ptr<Pet>)       │
│  [ vptr | name_ | birth_year_ ]  │    │  ┌──────┐   ┌──────┐   ┌──────┐        │
│                                  │ ┌─▶│  │ ptr0 │   │ ptr1 │   │ ptr2 │        │
│ wangcai (Dog)                    │ │  │  └──┬───┘   └──┬───┘   └──┬───┘        │
│  [ vptr | name_ | birth_year_ ]  │ │  │     │          │          │            │
│                                  │ │  │     ▼          ▼          ▼            │
│ pets (vector header) ────────────┼─┘  │  [ Cat ]    [ Dog ]   [ Rabbit ]       │
└──────────────────────────────────┘    └────────────────────────────────────────┘

代码区 / 只读数据区 (全程序共用一份)
  函数代码 : Pet::print()  Cat::kind()  Cat::speak()  Dog::speak()  Rabbit::speak() ...
  虚函数表 : Cat vtable / Dog vtable / Rabbit vtable
```

### 6.2 继承的内存布局，以及"对象切片"的真相

当子类继承父类时，子类对象在内存里通常是把**父类子对象放在前半段，子类自己新增的成员变量紧接在后面**。

拿后面练习 2 的 `Course`（父类）和 `LabCourse`（子类，多了一个 `lab_room_` 成员）来对比，一眼就能看明白：

```text
基类 Course 的对象布局：
┌────────┬─────────┬──────────┬────────┐
│  vptr  │  name_  │ teacher_ │ hours_ │
└────────┴─────────┴──────────┴────────┘

子类 LabCourse 的对象布局：
┌────────┬─────────┬──────────┬────────┬───────────┐
│  vptr  │  name_  │ teacher_ │ hours_ │ lab_room_ │
└────────┴─────────┴──────────┴────────┴───────────┘
▲                                      ▲
└──────── 完整的 Course 子对象 ────────┘  子类新增成员
```

看懂这张图，前面第三节的两个现象一下子就透明了：

1. **为什么 `Pet` 指针可以直接指向子类对象？**
   因为子类对象的前半段在内存里天然就是一个完整的父类子对象。把 `LabCourse*` 转成 `Course*`（向上转型）时，指针稳稳指向父类成员的起点，访问 `name_`、`hours_` 完全顺理成章。
2. **为什么按值拷贝会触发"对象切片（Object Slicing）"？**
   假设基类不是抽象类、允许直接创建 `std::vector<Base>`，那 `vector` 里每个格子只分配了 `Base` 那么大的一块连续内存。如果你硬要把更大的 `Derived` 按值拷进去，后面多出来的子类成员根本装不下，只能被硬生生"切掉"，同时新对象的 `vptr` 也会变成基类的 `vptr`，多态身份彻底丢失。
   而 `std::vector<std::unique_ptr<Pet>>` 里每个格子存的都是大小一致的指针（64 位平台上占 8 字节），真正大小各异的子类对象完完整整住在堆上，一根毫毛都不会少。

### 6.3 多态的底层机制：`vptr` 与 `vtable`

在 [main.cpp](main.cpp) 的 `greet_all` 里，循环变量 `pet` 的编译期类型明明都是 `const std::unique_ptr<Pet> &`，程序在运行时到底是怎么知道该调 `Cat::speak()` 还是 `Dog::speak()` 的？

主流 C++ 编译器（GCC、Clang、MSVC）在底层用的都是同一套经典机制：**虚函数表（vtable） + 虚表指针（vptr）**。

- **虚函数表（vtable，virtual table）**：只要一个类声明了 `virtual` 函数（包括虚析构函数），编译器就会在只读数据区为这个**类**生成一张函数指针表，记录它各个虚函数的实际入口地址。**每个类只有一张表**，所有同类型对象共享。
- **虚表指针（vptr，virtual pointer）**：编译器会在每个多态**对象**的内存开头（典型布局下）悄悄塞进一个隐藏指针 `vptr`。对象在构造时，构造函数会自动把 `vptr` 指向**自己真实类型**对应的那张 `vtable`。

画出 `Cat("xiaohui")` 和 `Dog("wangcai")` 的运行时指向关系：

```text
堆上的对象实例                    只读区的虚函数表 (vtable)           代码区的实际函数
┌─────────────────────────┐      ┌────────────────────────┐
│ Cat                     │      │ Cat vtable             │
│  ┌──────┐               │      │  [0] ~Pet()  ──────────┼──▶ Cat::~Cat()
│  │ vptr ├───────────────┼─────▶│  [1] kind()  ──────────┼──▶ Cat::kind()
│  ├──────┴─────────────┐ │      │  [2] speak() ──────────┼──▶ Cat::speak()
│  │ name_ = "xiaohui"  │ │      └────────────────────────┘
│  │ birth_year_ = 2023 │ │
│  └────────────────────┘ │
└─────────────────────────┘

┌─────────────────────────┐      ┌────────────────────────┐
│ Dog                     │      │ Dog vtable             │
│  ┌──────┐               │      │  [0] ~Pet()  ──────────┼──▶ Dog::~Dog()
│  │ vptr ├───────────────┼─────▶│  [1] kind()  ──────────┼──▶ Dog::kind()
│  ├──────┴─────────────┐ │      │  [2] speak() ──────────┼──▶ Dog::speak()
│  │ name_ = "wangcai"  │ │      └────────────────────────┘
│  │ birth_year_ = 2021 │ │
│  └────────────────────┘ │
└─────────────────────────┘
```

顺着这张图走一遍三种调用：

1. **调用虚函数 `pet->speak()`（动态绑定）**：
   程序运行时先通过 `pet` 找到对象开头的 `vptr` → 跳到它对应的 `vtable` → 取出 `speak()` 槽位里存的函数地址 → 跳过去执行。指向 `xiaohui` 时读到的是 `Cat vtable`，于是执行 `Cat::speak()`；指向 `wangcai` 时读到的是 `Dog vtable`，于是执行 `Dog::speak()`。
   甚至 `Pet::print()` 本身并不是虚函数，但它内部调用 `kind()`（等价于 `this->kind()`）时同样会通过 `this->vptr` 查表，因此也能自动调用子类的 `kind()`。
2. **销毁 `std::unique_ptr<Pet>`（虚析构的底层原理）**：
   正因为 `~Pet()` 加了 `virtual`，它也在 `vtable` 里占了槽位！释放 `unique_ptr<Pet>` 时同样顺着 `vptr -> vtable[0]` 先找到 `Cat::~Cat()` 执行，再自动向上调用 `Pet::~Pet()`。如果没加 `virtual`，析构函数压根不会进 `vtable`，编译器只能死板地直接调 `Pet::~Pet()`。
3. **调用普通非虚函数（如 `pet->name()`、`pet->age()`、`pet->rename()`）**：
   这些函数没加 `virtual`，不在 `vtable` 里，编译器在编译期就能直接确定唯一的跳转地址（静态绑定），没有任何查表开销。

> 多态不是完全免费的——一旦类有了虚函数，**每个对象**会多占一个指针大小（64 位下通常为 8 字节）的 `vptr`，每次虚函数调用也多了一次查表间接跳转。所以 C++ 默认让成员函数是**非虚**的，只有你明确需要多态时才写 `virtual`。

---

## 七、回头看：四个特性与代码组织

现在把 [pet.hpp](pet.hpp)、[pet.cpp](pet.cpp) 和 [main.cpp](main.cpp) 从头到尾串起来看，不仅四个概念各司其职，文件分工也非常清晰：

- **文件组织**：

  - [pet.hpp](pet.hpp) 是对外说明书：用 `#pragma once` 防重复包含，声明 `Pet` 及各个子类的接口、继承关系、`virtual` / `override` / `= 0`；

  - [pet.cpp](pet.cpp) 藏起具体实现：用 `类名::函数名` 实现成员函数，改细节不影响头文件接口；
  
  - [main.cpp](main.cpp) 只面向接口编程：`#include "pet.hpp"`，用栈对象演示子类特长，用 `std::vector<std::unique_ptr<Pet>>` 演示多态统一管理与 RAII 自动回收。

- **四个特性如何配合**：

  - **抽象**：帮我们从猫、狗、兔子身上提炼出 `Pet` 这个统一概念，并用纯虚函数规定"宠物必须有种类、会叫"。

  - **封装**：把 `name_`、`birth_year_` 锁在 `Pet` 内部，守住校验规则，也让内部存储改来改去不影响外部。

  - **继承**：让 `Cat`、`Dog`、`Rabbit` 复用 `Pet` 的通用逻辑，只专注写自己的差异（抓老鼠、捡球、各自怎么叫）。

  - **多态**：让 `greet_all` 只面对 `Pet` 写一遍代码，就能在运行时借由 `vptr` / `vtable` 自动分派给猫、狗、兔子，以后加新宠物不用动老代码；配合**虚析构函数**与 `std::unique_ptr`，连对象销毁也能安全自动完成。

---

## 八、动手练一下

### 练习 1：给宠物程序加一只新宠物（并验证析构顺序）

打开 [pet.hpp](pet.hpp)、[pet.cpp](pet.cpp) 和 [main.cpp](main.cpp)，在**不动 `Pet` 和 `greet_all` 任何一行代码**的前提下：

1. 在 [pet.hpp](pet.hpp) 中新增一个 `Duck`（或者你喜欢的任意宠物）公有继承 `Pet`，声明构造函数、`kind()`、`speak()`，再加一个它独有的成员函数（比如 `swim()`）；
2. 在 [pet.cpp](pet.cpp) 中实现 `Duck` 的各个成员函数（注意：类外实现不要重复写 `override`）；
3. 在 [main.cpp](main.cpp) 的 `pets` 里用 `std::make_unique<Duck>(...)` 加进去，执行 `g++ -std=c++17 -Wall -Wextra -o oop2 main.cpp pet.cpp && ./oop2` 编译运行，确认 `greet_all` 自动支持了这只新宠物；
4. **（选做实验）** 给 `Pet` 和 `Cat`（或 `Duck`）的构造函数、析构函数各加一句 `std::cout` 日志，跑一遍观察栈对象和 `pets` 里堆对象的**构造与析构顺序**；再试着临时把 `Pet` 析构函数前的 `virtual` 去掉，看看 `pets` 销毁时子类的析构日志还会不会打印出来（实验完记得改回去！）。

### 练习 2：把上一篇的 `Subject` 升级成多态版本

上一篇练习里我们写过一个 `Subject`（学科）类。现在假设学校里的课程分成两种：
- **理论课（`LectureCourse`）**：按正常课时算学分（比如 `hours / 16.0`）；
- **实验课（`LabCourse`）**：实验课双倍折算，每 32 课时算 1 学分（`hours / 32.0`），并且多一个私有成员 `lab_room_`（实验室房间号）。

请你设计：
1. 一个抽象基类 `Course`，封装共有的 `name_`、`teacher_`、`hours_`（保持 `set_hours()` 拒绝负数的校验），并声明纯虚函数 `virtual double credits() const = 0;` 和 `virtual void print() const = 0;`（别忘了虚析构函数）；
2. 两个子类 `LectureCourse` 和 `LabCourse` 继承 `Course`，各自实现 `credits()` 和 `print()`；
3. 写一个自由函数 `void print_syllabus(const std::vector<std::unique_ptr<Course>> &courses)`，打印所有课程的信息以及**总学分**。

参考实现见 [exercise/answer_course.cpp](exercise/answer_course.cpp)（编译命令：`g++ -std=c++17 -Wall -Wextra -o answer_course exercise/answer_course.cpp && ./answer_course`）。
