---
marp: true
theme: aim-classroom
paginate: true
size: 16:9
---

<!-- _class: cover -->

## C++ 函数与面向对象

第二课 / 参数怎样传递，对象怎样协作

<!--
用两分钟回顾引用遍历修改数组。本课始终追问：这行代码改的是哪一份数据？后半沿用乐队模型。
建议用时：1 分钟
-->

---

<!-- _class: question -->

## 交换之后会发生什么？

```cpp
int x = 10, y = 20;
swap1(x, y);
std::cout << x << ' ' << y << '\n';
```

先留下你的预测，稍后回来验证

<!--
先不展示 swap1 定义，不要求猜实现细节。收集“函数名不够判断是否改变调用者”的观点，随后通过参数类型解决。
建议用时：2 分钟
-->

---

<!-- _class: section -->

## 函数

调用表达式怎样得到一个结果

<!--
用这一页交代接下来的问题。让学员把注意力从上一段代码转过来。
建议用时：1 分钟
-->

---

<!-- _class: code -->

## test_add 的接口

```cpp
int test_add(int a, int b) {
    int sum = a + b;
    return sum;
}

int result = test_add(1, 2);
```

参数 a、b 得到 1、2，result 得到 3

<!--
依次指出返回类型、函数名、形参、实参、返回值。sum 是局部对象，离开函数后结束生命周期，但整数值已交给调用点。
完整演示：Examples/L2_C01_D01.cpp
建议用时：3 分钟
-->

---

<!-- _class: trace -->

## 一次调用的局部状态

```text
call                a    b    sum
test_add(1, 2)      1    2      3
return 3           local objects end
caller             result = 3
```

返回的是结果值，局部变量不会变成全局变量

<!--
让学生追踪第二次调用test_add(4,5)。两次调用有各自的局部状态，不沿用上一次sum。这里仅讨论简单值返回。
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 输出与返回值

```cpp
int test_add(int a, int b) {
    std::cout << "adding\n";
    return a + b;
}

int result = test_add(2, 3);
```

屏幕输出 adding，变量 result 得到 5

<!--
问不写 cout<<result 时屏幕有没有 5，答案没有。再让学生解释只有 cout 没有 return 为什么不能替代非 void 函数的返回。
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 返回值可以继续参与表达式

```cpp
int total = test_add(2, 3) * 10;
std::cout << total << '\n';
```

先得到 5，再乘 10，最后输出 50

<!--
使用不带提示输出的test_add版本。让学生改成嵌套test_add(test_add(1,2),3)，解释内层结果成为外层实参。对有副作用参数不展开求值顺序推论。
建议用时：2 分钟
-->

---

<!-- _class: code -->

## 声明、定义与 void

```cpp
int test_add(int a, int b);

void hello() {
    std::cout << "Hello\n";
}
```

声明提供接口，定义提供函数体  
void 表示没有返回值

<!--
展示完整文件的调用位置，说明先声明再调用也可以。void 函数不能用来初始化 int。单文件平台仍只保留一个 main。
完整演示：Examples/L2_C01_D02.cpp
建议用时：2 分钟
-->

---

<!-- _class: code -->

## 同名局部变量互不干扰

```cpp
void change(int value) {
    value = 99;
}

int value = 10;
change(value);
```

函数内外名字相同，也仍是不同对象

<!--
调用者变量位于main内，本页省略外壳。输出调用者value仍是10。要求学生指出形参由实参初始化，而不是绑定别名。
建议用时：3 分钟
-->

---

<!-- _class: section -->

## 引用与指针

名字、地址和地址里的对象

<!--
用这一页交代接下来的问题。让学员把注意力从上一段代码转过来。
建议用时：1 分钟
-->

---

<!-- _class: question -->

## 引用是同一对象的别名

```cpp
std::string band1("poppin party");
std::string& live1 = band1;
live1 = "afterglow";
```

band1 现在是什么？

<!--
得到 afterglow。band1 与 live1 是同一个对象的两个名字。比较 &band1==&live1，可输出 true。引用初始化后不能重新绑定。
完整演示：Examples/L2_C02_D01.cpp
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 引用赋值不会重新绑定

```cpp
int a = 10, b = 20;
int& r = a;
r = b;
b = 30;
```

最后 a=20、b=30、r=20

<!--
r=b把b的值赋给a，不是让r改为引用b。对照下一节指针p=&b可以改变所存地址。
建议用时：2 分钟
-->

---

<!-- _class: code -->

## 指针保存地址

```cpp
std::string* anime1 = &band1;

std::cout << *anime1 << '\n';
*anime1 = "roselia";
```

&band1 取地址，*anime1 访问目标对象

<!--
区分声明中的 * 与表达式中的 *。anime1 自身也是一个对象，里面存地址。最后 band1 与 live1 都看到 roselia。
完整演示：Examples/L2_C02_D02.cpp
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 声明、取地址与解引用

```cpp
int value = 10;
int* p = &value;

// int*    : type of p
// &value  : address of value
// *p      : object at that address
```

同一个符号，先看它出现在哪种语法里

<!--
让学生口述p和*p的类型、值与关系。不要将编译器打印的具体地址作为固定结果。画在白板上即可。
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 改指针与改目标

```cpp
std::string a("A"), b{"B"};
std::string* p = &a;
p = &b;
*p = "X";
```

a 是 A，b 是 X  
p 的地址值变了，随后写入新的目标

<!--
让学生逐行说 p 指向谁。白板上用名字和地址关系辅助，不背“指针就是变量”口号。强调 p=&b 不会把 b 复制到 a。
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 空指针与有效期

```cpp
std::string* p = nullptr;
if (p != nullptr) {
    std::cout << *p << '\n';
}
```

先确认目标存在，再解引用

<!--
不会输出。空检查只是必要条件之一，悬空指针即使非空也不可用。不要返回局部变量地址。const string* 可只读访问目标，但这里不展开所有 const 组合。
完整演示：Examples/L2_C02_D03.cpp
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 只读借用与生命周期

```cpp
const std::string& view = band1;
const std::string* ptr = &band1;

// view = "X"; // not allowed
// *ptr = "X"; // not allowed
```

const 限制这条访问路径的修改能力  
借用者使用时，原对象必须仍然有效

<!--
原对象band1若不是const，仍可通过其他合法路径修改，view会看到变化。const借用不是快照，也不自动延长任意被借用对象的生命周期。
建议用时：3 分钟
-->

---

<!-- _class: practice -->

## 练习：追踪同一份数据

```cpp
int a = 10, b = 20;
int& r = a;
int* p = &b;
r = 11;
*p = r;
p = &a;
```

最后 a、b、r、*p 分别是多少？

<!--
全部为 11。要求逐行推导而非只报答案。再问 p=&a 时 b 有没有变，答案没有。
建议用时：5 分钟
-->

---

<!-- _class: trace -->

## 追踪题的逐行结果

```text
operation     a    b    r    *p
r = 11       11   20   11    20
*p = r       11   11   11    11
p = &a       11   11   11    11
```

最后一行改变了指针的目标，没有给 a 或 b 赋值

<!--
先请学生说明为何最后一行数值相同但关系变化。再问随后*p=99影响谁，答案a与r可见，b仍11。
建议用时：2 分钟
-->

---

<!-- _class: section -->

## 交换实验

参数的类型决定函数能访问哪份数据

<!--
用这一页交代接下来的问题。让学员把注意力从上一段代码转过来。
建议用时：1 分钟
-->

---

<!-- _class: code -->

## swap1 交换的是副本

```cpp
void swap1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

swap1(x, y);
```

调用者 x=10、y=20  
函数内部 a=20、b=10

<!--
回到开场预测。板书两行存储：调用者 x/y 和函数 a/b。逐行更新，返回后 a/b 生命周期结束，x/y 仍为 10/20。
完整演示：Examples/L2_C03_D01.cpp
建议用时：4 分钟
-->

---

<!-- _class: trace -->

## swap1 的状态轨迹

```text
step        x    y    a    b    temp
call       10   20   10   20      -
temp=a     10   20   10   20     10
a=b        10   20   20   20     10
b=temp     10   20   20   10     10
```

x、y 从头到尾没有被写入

<!--
把每次赋值的左侧圈出来。没有x、y，所以调用者没有变化。参数销毁时不会自动把局部值复制回去。
建议用时：3 分钟
-->

---

<!-- _class: code -->

## swap2 通过地址写回

```cpp
void swap2(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

swap2(&x, &y);
```

参数复制的是地址，*a 和 *b 指向原对象

<!--
调用从 x=10,y=20 重新开始。输出变 20/10。指针参数仍是值传递，复制的是地址。此接口要求两个指针均有效，不能随意传 nullptr。
完整演示：Examples/L2_C03_D02.cpp
建议用时：4 分钟
-->

---

<!-- _class: trace -->

## swap2 的状态轨迹

```text
step          target of a   target of b
call              x=10          y=20
temp=*a           x=10          y=20
*a=*b             x=20          y=20
*b=temp           x=20          y=10
```

指针本身是副本，写入目标仍是调用者的对象

<!--
同时在白板保留a=&x、b=&y，强调修改指针参数本身和解引用赋值不同。用调试器或临时输出验证每一步。
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 引用参数的交换

```cpp
void swap_ref(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

swap_ref(x, y);
```

a、b 直接成为 x、y 的别名

<!--
与 swap1 只差两个 &。此处是对照写法，原课主线仍是 swap1/swap2。解释三种接口的调用表达式区别。
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 三种参数接口的选择

```cpp
void f(int value);        // independent copy
void f(int& value);       // may modify caller
void f(const int& value); // read-only borrow
void f(int* value);       // pointer value
```

接口应说明是否修改、是否允许没有对象

<!--
指针可以表达可选目标但是否允许nullptr由接口约定，不能看到指针就假定可空。简单int只读通常直接值传递就足够，const&常用于较大对象。
建议用时：3 分钟
-->

---

<!-- _class: practice -->

## 练习：修复不能写回的函数

```cpp
void add_bonus(int score) {
    score += 5;
}
```

要求调用 add_bonus(score) 后，原分数增加 5  
你只需要改哪里？

<!--
答案为 int& score。让学生从 60 验证到 65，再解释为何原版没有改动。可另写返回新值版本，讨论两种接口都合理但调用方式不同。
建议用时：5 分钟
-->

---

<!-- _class: code -->

## 修改原对象与返回新值

```cpp
void add_bonus(int& score) {
    score += 5;
}

int with_bonus(int score) {
    return score + 5;
}
```

add_bonus(score) 直接修改  
score = with_bonus(score) 显式接收新值

<!--
让学生写出两个调用，并解释若只写with_bonus(score)为什么原值不变。讨论调用者能否从接口读出意图。
建议用时：2 分钟
-->

---

<!-- _class: section -->

## 课间休息

10 分钟  
回来后扩展 Band，再一起追踪完整程序

<!--
提醒保存完成的最小Band练习。回来时先回顾构造和访问权限，再进入继承。
建议用时：10 分钟
-->

---

<!-- _class: section -->

## Band：数据与行为

同一支乐队有自己的成员和操作

<!--
用这一页交代接下来的问题。让学员把注意力从上一段代码转过来。
建议用时：1 分钟
-->

---

<!-- _class: code -->

## 从记录到 Band

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

外部通过公开方法改变内部状态

<!--
先回顾第一课 record 可公开改字段。Band 将操作放在类型里。为聚焦只显示 keyboard，完整版本仍有 guitar/vocal/drum/bass。不要说这个 setter 已经实施业务校验。
完整演示：Examples/L2_C04_D02.cpp
建议用时：3 分钟
-->

---

<!-- _class: trace -->

## 五个字段属于同一支乐队

```text
guitar    mutsumi
vocal     hatsune
drum      nyamu
bass      umiri
keyboard  saki
```

字段名属于类型，每个对象保存自己的一组值

<!--
把完整五成员模型放回上下文，说明上一页只展示keyboard只是聚焦。问使用五组平行变量时如何确保属于同一支乐队，从而引出封装的必要。
建议用时：2 分钟
-->

---

<!-- _class: question -->

## 对象各自保存状态

```cpp
Band a;
Band b;
a.set_keyboard_anon();
```

a 的变化会自动影响 b 吗？

<!--
本页沿用上一页的最小类，有隐式默认构造，字符串默认为空。答案不会。说明随后添加有参构造后，此处的默认构造写法将不再适用。
建议用时：3 分钟
-->

---

<!-- _class: trace -->

## 两个对象的独立状态

```text
before       a.keyboard=""   b.keyboard=""
a.set_keyboard_anon()
after        a.keyboard="anon"
             b.keyboard=""
```

相同成员名，不代表同一份存储

<!--
沿用有隐式默认构造的最小Band。不要用带五参数构造的完整版去执行Band a;。解释对象名限定方法调用目标。
建议用时：2 分钟
-->

---

<!-- _class: code -->

## private 与 public

```cpp
a.keyboard = "anon";  // error
a.set_keyboard_anon(); // OK
```

成员方法可以访问自己的 private 成员

<!--
第一行是故意的编译错误，不与第二行一起作为成功示例运行。解释 private 限制类外直接访问，类的成员函数有访问权限。
完整演示：Examples/L2_C04_D02.cpp
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 封装提供统一的修改入口

```cpp
void set_keyboard(const std::string& name) {
    if (name.empty()) return;
    keyboard = name;
}
```

调用者提出修改，类决定是否接受

<!--
这是为解释约束新增的方法，不声称原set_keyboard_anon已做校验。空名字在此被拒绝；让学生讨论静默拒绝是否足够，接口也可返回bool。
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 构造函数给对象初始状态

```cpp
Band(std::string key) {
    keyboard = key;
}

Band a("saki");
```

名称与类相同，不写返回类型

<!--
把构造函数放回 Band 的 public 区域。原课完整 Band 接收五个成员参数，本页缩小为一个。先展示函数体赋值，下一页再对比初始化列表。
完整演示：Examples/L2_C05_D01.cpp
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 有参构造与默认构造

```cpp
Band a("saki"); // OK in the reduced class
// Band b;      // no matching constructor
```

声明了这个有参构造后，编译器不会再隐式生成默认构造

<!--
明确这里是只接受一个key参数的最小Band。需要默认创建时应设计默认构造或默认实参，并确认默认状态合法。不要说构造函数都必须public，当前教学接口选择public。
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 成员初始化列表

```cpp
Band(std::string key)
    : keyboard(key) {}
```

keyboard 直接用 key 初始化  
成员按声明顺序初始化

<!--
对比上一页先默认构造再赋值。实际顺序不是冒号列表排列顺序。const 成员、引用成员需要在初始化阶段建立状态。std::move 原稿用法留讲义解释，不讲成“必然更快”。
完整演示：Examples/L2_C05_D02.cpp
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 声明顺序决定初始化顺序

```cpp
class Example {
    int first;
    int second;
public:
    Example() : second(2), first(1) {}
};
```

实际仍先 first，再 second  
初始化列表按声明顺序写更清楚

<!--
该例每个值都是常量，不读取未初始化成员。把列表顺序改正并展示编译器reorder警告。不要用危险依赖例子让学生运行未定义行为。
建议用时：2 分钟
-->

---

<!-- _class: code -->

## 读方法与写方法

```cpp
void print_info() const {
    std::cout << keyboard << '\n';
}

void set_keyboard_anon() {
    keyboard = "anon";
}
```

成员函数末尾的 const 承诺不修改普通成员

<!--
针对本课无 mutable 成员的类解释。const Band 可调用 print_info，不能调用 setter。原稿 get_guitar 是打印，不误讲成返回字符串。
完整演示：Examples/L2_C06_D01.cpp
建议用时：3 分钟
-->

---

<!-- _class: code -->

## const 对象可以调用什么？

```cpp
const Band band("saki");
band.print_info();       // OK
// band.set_keyboard_anon(); // error
```

只读承诺也成为调用接口的一部分

<!--
仍用单字段Band。取消注释第二次调用让学生读诊断。print_info末尾const修饰当前对象访问，和参数const是不同位置的约束。
建议用时：2 分钟
-->

---

<!-- _class: practice -->

## 练习：独立完成一个 Band

保留一个 private 字符串 keyboard  
用构造函数接收初始值  
提供只读打印和修改方法  
创建两个对象，验证只改动其中一个

<!--
建议初值 saki 与 eve。修改 a 后应为 anon/eve。必须完整类定义、分号、main、头文件。学生完成后再切回完整五成员 Band，明确最小示例只是聚焦。
建议用时：10 分钟
-->

---

<!-- _class: statement -->

## Band 练习的验收

a 初值 saki，b 初值 eve  
只修改 a 后，输出应为 anon / eve  
const 对象可以打印  
类外直接写 keyboard 应编译失败

<!--
把有效程序与故意的编译失败用例分开运行。由学生解释每个用例检验了哪条规则。确认不是只会照抄类定义。
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 完整 Band 的五个成员

```cpp
Band ave_mujica(
    "mutsumi", "hatsune", "nyamu",
    "umiri", "saki"
);
ave_mujica.print_info();
ave_mujica.live();
```

guitar、vocal、drum、bass、keyboard

<!--
明确从此回到完整定义，运行示例文件。按原 class_band 顺序先创建 ave_mujica，再 print_info/live。两者分别输出成员表和 LIVE。
完整演示：Examples/L2_C09_D01.cpp
建议用时：3 分钟
-->

---

<!-- _class: code -->

## vector 存放多支乐队

```cpp
std::vector<Band> live_bands;
live_bands.emplace_back(
    "hina", "aya", "maya", "chisato", "eve");
live_bands.emplace_back(
    "sayo", "yukina", "ako", "lisa", "rinko");
```

vector 管理数量，Band 管理每个对象

<!--
需要 vector 头文件。emplace_back 使用构造参数在末尾建立对象。不要把 vector 的内部重新分配细节加到主讲，提醒扩容可能使已有引用/指针失效。
完整演示：Examples/L2_C06_D02.cpp
建议用时：3 分钟
-->

---

<!-- _class: code -->

## vector 的大小与位置

```cpp
std::cout << live_bands.size() << '\n';
live_bands[0].print_info();
live_bands.at(1).print_info();
```

两次追加后 size 为 2，有效下标为 0 和 1

<!--
[]不检查边界，at越界会抛异常。emplace_back不只是“给数组赋值”，它改变容器大小并构造新对象。
建议用时：2 分钟
-->

---

<!-- _class: code -->

## 遍历时要改哪一份？

```cpp
for (Band band : live_bands) {
    band.set_keyboard_anon();
}

for (Band& band : live_bands) {
    band.set_keyboard_anon();
}
```

上面改副本，下面改容器里的对象

<!--
回收第一课数组遍历的同一规则。只读打印用 const Band&。不要在两个循环之间不复位就误认为第一轮也修改了容器。
完整演示：Examples/L2_C06_D02.cpp
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 只读遍历完整乐队

```cpp
for (const Band& band : live_bands) {
    band.print_info();
}
```

借用容器中的对象，并通过 const 接口读取

<!--
对比Band复制、Band&修改、const Band&读取三种选择。让学生指出为何print_info需要const，而setter在这里不能调用。
建议用时：2 分钟
-->

---

<!-- _class: question -->

## 类与容器检查

值传递、引用、指针分别传来了什么？  
构造函数在哪一步建立初始状态？  
读方法为什么可以带 const？

<!--
请学生举一个本课例子解释，不要求背定义。 用学生自己的代码解释，而不是只报结论。
建议用时：5 分钟
-->

---

<!-- _class: section -->

## 继承

在 Band 的基础上增加 vocal_actor

<!--
用这一页交代接下来的问题。让学员把注意力从上一段代码转过来。
建议用时：1 分钟
-->

---

<!-- _class: code -->

## MofoBand 的继承关系

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

已有 Band 行为，再增加配音演员信息

<!--
本页只展示继承与方法，构造函数下一页补上。基类 private 字段仍不能在派生类中直接访问，派生类调用公开方法。public 继承表达可作为一种 Band 使用的关系。
完整演示：Examples/L2_C07_D01.cpp
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 基类先初始化

```cpp
MofoBand(std::string gt, std::string vo,
         std::string dr, std::string ba,
         std::string key, std::string actor)
    : Band(gt, vo, dr, ba, key),
      vocal_actor(actor) {}
```

先 Band，再 vocal_actor，最后进入函数体

<!--
这是类内构造函数片段。打开完整示例对照五个乐队成员参数。把 Band(...) 写在函数体里会创建临时对象，不能补救缺失的基类初始化。
完整演示：Examples/L2_C07_D02.cpp
建议用时：4 分钟
-->

---

<!-- _class: statement -->

## protected 的访问范围

MofoBand 的成员函数：可以  
MofoBand_New 的成员函数：可以按继承规则访问  
main 中直接写对象.vocal_actor：不可以

<!--
纠正原稿“protected 只给子类”的错误，声明它的类本身也可访问。访问还受对象表达式及继承方式规则约束，本页只讨论既定 public 继承链。
完整演示：Examples/L2_C08_D01.cpp
建议用时：3 分钟
-->

---

<!-- _class: code -->

## this 指向当前对象

```cpp
void change_actor(
    const std::string& new_actor) {
    this->vocal_actor = new_actor;
}
```

左侧是当前对象的成员，右侧是参数

<!--
在 MofoBand_New 中演示。const& 只读借用参数，赋给 vocal_actor 时仍发生字符串赋值。此处 this-> 可省略，不说成成员访问都必须写 this。
完整演示：Examples/L2_C08_D02.cpp
建议用时：3 分钟
-->

---

<!-- _class: practice -->

## 练习：演员信息的修改

创建一个 actor 初值为 amane 的对象  
调用 change_actor("ayane")  
输出修改后的信息  
说明为什么 main 不能直接改 protected 字段

<!--
让学生基于完整示例修改 main，避免在演示窗口重敲所有构造参数。验证输出只有目标对象演员字段发生改变。
完整演示：Examples/L2_C08_D02.cpp
建议用时：8 分钟
-->

---

<!-- _class: statement -->

## class_band 的运行轨迹

ave_mujica：创建、print_info、live  
live_bands：加入两支乐队、遍历  
ave_mujica：get_guitar、修改 keyboard  
morfonica 与 lovelive：创建、修改 actor

<!--
打开原课综合 Lesson02.cpp 的 class_band。跟随执行顺序逐段运行，追问每个方法作用于谁。原 ave_mujica 不在 live_bands 中，修改容器元素不等于修改它。
完整演示：Examples/L2_C09_D01.cpp
建议用时：5 分钟
-->

---

<!-- _class: question -->

## 主课回看

谁拥有这份数据？  
函数访问的是副本还是原对象？  
外部代码通过哪个接口修改它？

<!--
用 swap、Band setter、vector 引用遍历各举一个例子。布置 Assessment-02 必做题。之后几页属于可选拓展，可在这里结束主课。
建议用时：3 分钟
-->

---

<!-- _class: section -->

## 可选拓展

虚函数、切片与资源所有权

<!--
用这一页交代接下来的问题。让学员把注意力从上一段代码转过来。
建议用时：1 分钟
-->

---

<!-- _class: code -->

## 通过基类调用派生行为

```cpp
struct Base {
    virtual void live() const { /* ... */ }
    virtual ~Base() = default;
};
struct Derived : Base {
    void live() const override { /* ... */ }
};
```

Base& 指向 Derived 时，live 调用派生实现

<!--
原 Band 没有 virtual，不可声称它已经多态。此处新建最小类型解释动态分派，展示 Base& b=d; b.live()。override 检查匹配，基类虚析构支持经基类指针删除。
完整演示：Examples/L2_C09_D02.cpp
建议用时：4 分钟
-->

---

<!-- _class: code -->

## 值复制可能发生切片

```cpp
Derived d;
Base copied = d;
Base& borrowed = d;
```

copied 只保留 Base 部分  
borrowed 仍引用完整的 d

<!--
沿用上一页类型。分别调用 live，copied 为 Base 实现，borrowed 为 Derived 实现。连接容器元素类型的选择，但不把新设计替换掉既有 vector<Band>。
完整演示：Examples/L2_C09_D02.cpp
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 独占资源的所有权

```cpp
std::unique_ptr<Band> owner = std::make_unique<Band>(
    "mutsumi", "hatsune", "nyamu",
    "umiri", "saki");
std::unique_ptr<Band> next = std::move(owner);
```

所有权交给 next，owner 变空  
离开作用域时自动释放

<!--
需要 memory 与 utility。这是可选工程拓展，原 Band 值语义不需要手写 new/delete。unique_ptr 不可复制。std::move 本身是转换，实际转移由 unique_ptr 移动构造完成；一般被移动对象不保证为空，本例 unique_ptr 保证。
完整演示：Examples/L2_C09_D03.cpp
建议用时：4 分钟
-->

---

<!-- _class: statement -->

## 课后材料与挑战

必做：用本课接口完成 Assessment-02  
加练：从例题索引选择薄弱知识点  
挑战：读完拓展后再完成相关题目

<!--
提醒公开自检不是正式总分，按老师要求主动提交。参考答案和完整推导在讲义与例题中。按班级情况决定拓展是当堂讲还是课后读。
建议用时：2 分钟
-->
