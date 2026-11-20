# C++ 面向对象入门（二）

上一篇 [tutorial1.md](../01_basics/tutorial1.md) 里，我们把散落的数组收拢进了一个 `Pet` 类，管理了三只宠物：`xiaohui`（猫）、`wangcai`（狗）和 `tuanzi`（兔子）。

但到目前为止，`Pet` 还只是个"能存数据、能校验名字的盒子"。这一篇我们继续顺着这个宠物程序往下加需求，看看代码在什么地方开始不够用——在这个过程中，面向对象最常提的四个词：**封装、继承、多态、抽象**，会一个接一个自然冒出来。

> 本篇最终的完整代码放在 [oop2.cpp](oop2.cpp)，可以用下面这条命令编译运行：
>
> ```bash
> g++ -std=c++17 -Wall -Wextra -o oop2 oop2.cpp && ./oop2
> ```

---

## 一、封装

先回头看上一篇的 `Pet`，它里面存了 `int age_;`。

程序跑了一年之后，新问题来了：**存固定年龄是个坏主意**——跨过新年，所有宠物的 `age_` 全都过时了。更合理的做法是改存**出生年份 `birth_year_`**，需要年龄的时候拿当前年份减一下。

好在上一篇我们把 `age_` 放在了 `private` 里，外面所有地方读年龄调用的都是 `pet.age()`。所以现在改起来非常轻松：

```cpp
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

如果你试图把一个 `Cat` 按值放进 `std::vector<Pet>`，C++ 会发生**对象切片（object slicing）**——容器里每个格子只留了 `Pet` 那么大的空间，塞进去的 `Cat` 会被硬生生切掉子类那一部分，只剩一个光秃秃的 `Pet`。

所以想要用基类统一存放不同的子类，必须用**指针**（现代 C++ 推荐智能指针 `std::unique_ptr<Pet>`）或者**引用**（函数参数用 `const Pet &`）。

### 坑 2：不加 `virtual`，调的永远是父类的函数

就算用了指针或引用，如果 `Pet::speak()` 只是普通成员函数，编译器在编译期看到指针类型是 `Pet*`，就会死板地去调 `Pet::speak()`，根本不管它实际指向的是猫还是狗。

解决办法是给 `Pet` 里需要"因子类而异"的函数加上 **`virtual`**（虚函数），子类重写的时候在后面加上 **`override`**：

```cpp
class Pet
{
    // ...
public:
    virtual ~Pet() = default; // 多态基类务必加虚析构函数

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

现在再看 `greet_all` 和 `main`：

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
    std::vector<std::unique_ptr<Pet>> pets;
    pets.push_back(std::make_unique<Cat>("xiaohui", 2023));
    pets.push_back(std::make_unique<Dog>("wangcai", 2021));
    pets.push_back(std::make_unique<Rabbit>("tuanzi", 2025));

    greet_all(pets);
}
```

运行输出：

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
> - **只要一个类会被继承、并通过基类指针管理，析构函数必须写成 `virtual ~Pet() = default;`**。否则释放 `std::unique_ptr<Pet>` 时，只会调 `Pet` 的析构函数，子类的析构函数根本不会被执行。

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

更好的做法是把这两句改成**纯虚函数**（在末尾写 `= 0`）：

```cpp
virtual std::string kind() const = 0;
virtual void speak() const = 0;
```

加了 `= 0` 之后，`Pet` 就成了一个**抽象类（abstract class）**，带来两个实实在在的约束：

1. **禁止直接造出"泛泛的宠物"**：在 `main` 里写 `Pet p("mystery", 2024);` 会直接编译报错，想创建对象只能创建具体的 `Cat`、`Dog`、`Rabbit`。
2. **强制子类履约**：任何继承 `Pet` 的子类，必须自己把 `kind()` 和 `speak()` 实现出来，少写一个都编译不过。

这正是**抽象（Abstraction）**落地到代码里的样子：
- 在思考阶段，抽象意味着**提炼共性、忽略无关细节**（从各种动物里抽出"有名字、有年龄、会叫"这几个我们关心的特征）；
- 在代码层面，抽象类负责定下**"能做什么"的统一规范**（`kind()`、`speak()`），把**"具体怎么做"**彻底交给各个子类去实现。

顺带一提：如果一个抽象类里连成员变量都没有、全是 `= 0` 的纯虚函数，它就是 C++ 里最纯粹的**接口（interface）**——只定合同，不带任何数据和实现。

---

## 五、回头看：四个特性是怎么配合的？

把 [oop2.cpp](oop2.cpp) 从头到尾串起来，其实四个概念各司其职，缺一不可：

- **抽象**：帮我们从猫、狗、兔子身上提炼出 `Pet` 这个统一概念，并用纯虚函数规定"宠物必须有种类、会叫"。
- **封装**：把 `name_`、`birth_year_` 锁在 `Pet` 内部，守住校验规则，也让内部存储改来改去不影响外部。
- **继承**：让 `Cat`、`Dog`、`Rabbit` 复用 `Pet` 的通用逻辑，只专注写自己的差异（抓老鼠、捡球、各自怎么叫）。
- **多态**：让 `greet_all` 只面对 `Pet` 写一遍代码，就能在运行时自动分派给猫、狗、兔子，以后加新宠物不用动老代码。

---

## 六、动手练一下

### 练习 1：给 [oop2.cpp](oop2.cpp) 加一只新宠物

在不动 `Pet` 和 `greet_all` 任何一行代码的前提下：
1. 新增一个 `Duck`（或者你喜欢的任意宠物）继承 `Pet`；
2. 实现它的 `kind()`、`speak()`，再加一个它独有的成员函数（比如 `swim()`）；
3. 把它加进 `main` 的 `pets` 里，编译运行，确认 `greet_all` 自动支持了这只新宠物。

### 练习 2：把上一篇的 `Subject` 升级成多态版本

上一篇练习里我们写过一个 `Subject`（学科）类。现在假设学校里的课程分成两种：
- **理论课（`LectureCourse`）**：按正常课时算学分（比如 `hours / 16.0`）；
- **实验课（`LabCourse`）**：实验课双倍折算，每 32 课时算 1 学分（`hours / 32.0`），并且多一个私有成员 `lab_room_`（实验室房间号）。

请你设计：
1. 一个抽象基类 `Course`，封装共有的 `name_`、`teacher_`、`hours_`（保持 `set_hours()` 拒绝负数的校验），并声明纯虚函数 `virtual double credits() const = 0;` 和 `virtual void print() const = 0;`（别忘了虚析构函数）；
2. 两个子类 `LectureCourse` 和 `LabCourse` 继承 `Course`，各自实现 `credits()` 和 `print()`；
3. 写一个自由函数 `void print_syllabus(const std::vector<std::unique_ptr<Course>> &courses)`，打印所有课程的信息以及**总学分**。

参考实现见 [exercise/answer_course.cpp](exercise/answer_course.cpp)。
