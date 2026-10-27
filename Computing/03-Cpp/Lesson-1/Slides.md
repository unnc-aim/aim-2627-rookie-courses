---
marp: true
theme: aim-classroom
paginate: true
size: 16:9
---

<!-- _class: cover -->

## C++ 基础语法

第一课 / 让程序读入、判断、处理数据

<!--
先问谁已经在本机运行过 Hello World。说明今天会反复经历预测、运行、解释、修改。完整代码在 Examples，投影只显示当前讨论部分。
建议用时：1 分钟
-->

---

<!-- _class: statement -->

## 今天要写出的程序

```text
输入：3 个分数
计算：总分与平均分
判断：是否达到 60 分
输出：结果
```

你已经会用 Python 怎么写？

<!--
请一位同学口述 Python 解法，不要求语法。把输入、存储、循环、分支写在白板上，后面逐步收回来。
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 第一份完整程序

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, C++!\n";
    return 0;
}
```

入口是 main，语句用分号结束

<!--
先运行一次，再指头文件、main、花括号、分号。return 0 是退出状态，不会被打印。后续幻灯片省略未变化的外壳，运行时仍打开完整文件。
完整演示：Examples/L1_C01_D01.cpp
建议用时：2 分钟
-->

---

<!-- _class: code -->

## Python 与 C++ 的表达方式

```cpp
// Python: score = 85
int score = 85;

// Python: if score >= 60:
if (score >= 60) {
    std::cout << "pass\n";
}
```

类型写在变量前，花括号标记语句块

<!--
逐项比较变量声明、条件括号、花括号和分号。让学生指出缩进仍然重要，但缩进本身不定义 C++ 块。不要把 main 的外壳理解为每行都要背的魔法。
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 语句块与变量的作用域

```cpp
int score = 85;
{
    int bonus = 5;
    score += bonus;
}
std::cout << score << '\n';
// bonus is no longer in scope here
```

内层可以使用外层变量，外层不能使用已离开的局部名字

<!--
逐行追踪 score 从85到90。再将 bonus 的输出放在块外制造诊断。区分名字能否使用的作用域与对象何时存在的生命周期，当前简单局部变量两者同步结束。
建议用时：3 分钟
-->

---

<!-- _class: question -->

## 编译与运行

```cpp
std::cout << "Hello\n"
```

少了一个分号。这次会输出 Hello 吗？

<!--
停留至少十秒收集答案，再在完整示例中删掉分号运行。编译失败，当前源码不会执行。指向第一条诊断，修复后再运行。不要展示整屏错误列表。
完整演示：Examples/L1_C01_D01.cpp
建议用时：3 分钟
-->

---

<!-- _class: statement -->

## 第一条诊断的位置

先看文件名和行号  
回到该行，并检查前一行  
修复第一个原因，再重新编译

<!--
现场演示缺分号导致诊断指向下一行的情况。说明报错位置是编译器发现问题的位置，不一定就是最初错误位置。让学生主动读一条诊断。
建议用时：2 分钟
-->

---

<!-- _class: code -->

## std:: 是名字的归属

```cpp
std::cout << "AIM\n";

using std::cout;
cout << "AIM\n";
```

两种写法指向同一个标准库对象

<!--
解释 namespace 的目的是区分同名对象。现场只使用 std::，using 作为识读。旧稿命名冲突可在演示文件中看，不在此引入头文件拆分。
完整演示：Examples/L1_C02_D01.cpp
建议用时：2 分钟
-->

---

<!-- _class: code -->

## 输出的拼接顺序

```cpp
int score = 85;
std::cout << "score=" << score << '\n';
```

屏幕上会出现什么？

<!--
先让学生说出 score=85。指出字符串引号不输出，变量输出其值。换行通常用 \n，endl 还会刷新流，这里只口头补充。
完整演示：Examples/L1_C02_D02.cpp
建议用时：2 分钟
-->

---

<!-- _class: section -->

## 输入与类型

同一份数据，先确定它是什么

<!--
用这一页交代接下来的问题。让学员把注意力从上一段代码转过来。
建议用时：1 分钟
-->

---

<!-- _class: code -->

## 变量的类型

```cpp
int count = 3;
double average = 82.5;
char grade = 'A';
std::string name("anon");
bool passed = true;
```

整数 / 小数 / 一个字符 / 字符串 / 条件

<!--
逐行问这份数据适合表达什么。string 需要 string 头文件。强调 char 单引号、字符串双引号。bool 通常输出 0 或 1，boolalpha 可显示 true/false。
完整演示：Examples/L1_C03_D02.cpp
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 初始化与后续赋值

```cpp
int count = 3;  // initialization
count = 5;      // assignment

double measured = 3.5;
int truncated = static_cast<int>(measured);
```

初始化建立对象，赋值改变已有对象  
显式转换也可能丢失小数部分

<!--
truncated 为3。比较初始化与赋值，再解释显式转换表示意图，不保证没有信息损失。用-3.5检验转换向零截断。
建议用时：2 分钟
-->

---

<!-- _class: code -->

## 类型决定可表示的值

```cpp
int whole = 85;
double fraction = 85.5;

std::cout << sizeof(whole) << '\n';
std::cout << sizeof(fraction) << '\n';
```

整数有范围，浮点数有精度限制  
类型大小依赖实现，不能凭一次运行定规则

<!--
常见机器 int4字节、double8字节，但不作为语言保证。提醒有符号整数溢出不能依赖回绕。先理解选类型，再查 numeric_limits，不投影位宽表。
建议用时：2 分钟
-->

---

<!-- _class: code -->

## 输入按顺序进入变量

```cpp
int a = 0, b = 0;
std::cin >> a >> b;
std::cout << a - b << '\n';
```

输入 8 4，输出多少？换成两行呢？

<!--
预填 8 4，输出 4。改为两行仍为 4。空格和换行都可分隔这两个整数。再试 8,4，指出逗号不会自动成为分隔符，第二次提取会失败。
完整演示：Examples/L1_C03_D01.cpp
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 提取运算与一整行输入

```cpp
std::string first, second;
std::cin >> first >> second;
// Input: poppin party
// first = "poppin", second = "party"
```

>> 按空白分词，getline 读取一整行

<!--
先运行两个词的例子，再改成 std::getline(std::cin,line)。说明混用数值提取和 getline 时前一次换行可能残留，需要正确处理，例如 std::ws，但它也会跳过行首空白。
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 输入失败的分支

```cpp
int score = 0;
if (!(std::cin >> score)) {
    std::cout << "invalid input\n";
    return 1;
}
```

输入 abc，会走到哪里？

<!--
把这段放在 main 中演示。先让学生用自然语言解释：如果没读到整数就退出。if 与逻辑非的细节稍后展开。失败时不要继续把 score 当有效成绩。
建议用时：2 分钟
-->

---

<!-- _class: practice -->

## 练习：读取并输出

读入姓名与分数  
输出 anon:85  
输入样例：anon 85

<!--
学员从 Hello World 外壳改起。需要 iostream 与 string。巡视时优先检查提取顺序和引号。两分钟后请一位同学解释每个变量的类型，再现场运行。不要先展示答案。
建议用时：5 分钟
-->

---

<!-- _class: code -->

## 读取并输出：一起核对

```cpp
std::string name;
int score = 0;
std::cin >> name >> score;
std::cout << name << ':' << score << '\n';
```

检查变量类型、输入顺序和输出符号

<!--
学生完成后才翻此页。让一位同学解释冒号为什么带单引号。输入交换顺序会怎样？名字有空格时接口是否仍满足要求？
建议用时：2 分钟
-->

---

<!-- _class: section -->

## 运算与判断

先预测结果，再解释类型

<!--
用这一页交代接下来的问题。让学员把注意力从上一段代码转过来。
建议用时：1 分钟
-->

---

<!-- _class: question -->

## 3 / 2 的结果

```cpp
std::cout << 3 / 2 << '\n';
std::cout << 3 / 2.0 << '\n';
std::cout << 3 % 2 << '\n';
```

三行各输出什么？

<!--
按顺序收集 1、1.5、1。整数相除向零截断，% 是整数余数。本页只用正数，口头补充负数也按向零截断。
完整演示：Examples/L1_C04_D01.cpp
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 转换发生的时机

```cpp
int a = 3, b = 2;

double x = a / b;
double y = static_cast<double>(a) / b;
```

x 是 1，y 是 1.5  
接收结果的类型不会重算除法

<!--
在白板上先写 a/b 的 int 结果 1，再写转换成 double。改为转换 a 后，除法先获得浮点操作数。补问 static_cast<double>(a/b) 能否补救，答案不能。
完整演示：Examples/L1_C04_D01.cpp
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 三个除法表达式的计算过程

```cpp
3 / 2                         // 1
static_cast<double>(3) / 2     // 1.5
static_cast<double>(3 / 2)     // 1.0
```

先确定操作数类型，再执行除法，最后转换结果

<!--
白板分别圈出括号内表达式。最后一行数值为double的1，默认输出可能显示1而不是1.0，区分数值与显示格式。
建议用时：2 分钟
-->

---

<!-- _class: code -->

## 赋值与比较

```cpp
int x = 10;
x = 3;

std::cout << (x == 3) << '\n';
std::cout << (x != 3) << '\n';
```

= 改值，== 问是否相等

<!--
请学生说出 x 最后为 3，输出为 1 和 0。特别提示 if(x=3) 常能编译但改变了 x，编译通过不等于语义正确。
完整演示：Examples/L1_C04_D02.cpp
建议用时：2 分钟
-->

---

<!-- _class: code -->

## 复合条件与短路

```cpp
if (total != 0 && score / total > 0.6) {
    std::cout << "pass\n";
}
```

total 为 0 时，右边会计算吗？

<!--
此处假定 score 与 total 为 double。&& 左假则不计算右侧；|| 左真则不计算右侧，! 取反。让学员说出把两个条件反过来为什么不安全。
完整演示：Examples/L1_C04_D03.cpp
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 与、或、非的含义

```cpp
true  && false   // false
true  || false   // true
!true            // false
!(score < 0 || score > 100)
```

最后一行表示分数在 [0, 100] 内

<!--
让学生代入-1、0、100、101。再对照 score>=0 && score<=100。逻辑关系与短路求值是两个层次，都需要解释。
建议用时：2 分钟
-->

---

<!-- _class: code -->

## 变量的更新

```cpp
int count = 3;
++count;
count += 2;
count *= 3;
```

每行之后 count 分别是多少？

<!--
逐行停住，得到 4、6、18。这里 ++ 不放进复杂表达式。cmath 中 sqrt、abs 等作为口头识读，不在投影罗列函数手册。
完整演示：Examples/L1_C04_D04.cpp
建议用时：2 分钟
-->

---

<!-- _class: code -->

## 数学函数与返回类型

```cpp
#include <cmath>

std::sqrt(9.0);   // 3.0
std::abs(-3);     // 3
std::floor(2.8);  // 2.0
std::ceil(2.1);   // 3.0
```

调用产生一个值，想显示它仍要输出

<!--
把每个表达式放进 cout 中运行。解释 floor 和 ceil 是向下/向上取整的浮点结果，不等于 int 转换。-2.8 的 floor 是-3，向零转换为-2。
建议用时：2 分钟
-->

---

<!-- _class: code -->

## if 的互斥分支

```cpp
if (score >= 90) {
    std::cout << "A\n";
} else if (score >= 60) {
    std::cout << "pass\n";
} else {
    std::cout << "retry\n";
}
```

score 是 95，会打印几行？

<!--
只打印 A。对比两个独立 if 会同时满足两个条件。演示 95、60、59，解释为什么先测较高阈值。
完整演示：Examples/L1_C05_D01.cpp
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 分支顺序与边界样例

```cpp
// Test cases for score:
// 59  -> retry
// 60  -> pass
// 89  -> pass
// 90  -> A
// 100 -> A
```

边界两侧各测一次，比只测 80 更能发现错误

<!--
让学生把条件顺序交换成先>=60，预测95被分到pass。逐个样例手算再运行。题面若要求输入合法范围，还需单独检查0..100。
建议用时：2 分钟
-->

---

<!-- _class: practice -->

## 练习：平均分与及格判断

读入 3 个整数分数  
输出平均分，保留 1 位小数  
平均分 ≥ 60 时再输出 pass

<!--
提示需要 iomanip，使用 fixed 与 setprecision(1)。让同学先算 59 60 60 的期望 59.7，不能 pass。再试 60 60 60。平均分比较应使用未格式化数值。
建议用时：7 分钟
-->

---

<!-- _class: code -->

## 平均分：分离计算与显示

```cpp
double average = (a + b + c) / 3.0;
std::cout << std::fixed
          << std::setprecision(1)
          << average << '\n';
if (average >= 60) {
    std::cout << "pass\n";
}
```

显示到 1 位小数，不改变 average 存储的数值

<!--
需要iostream和iomanip。输入59 60 60时约59.6667，显示59.7且不通过。不要用已四舍五入的显示文本来判断是否通过。fixed与精度设置会继续影响流的后续浮点输出。
建议用时：3 分钟
-->

---

<!-- _class: section -->

## 课间休息

10 分钟  
回来后处理字符串，再整合成完整程序

<!--
休息前确认学生保存代码。根据前半段问题记录，回来时用一两个样例回收最常见误解。
建议用时：10 分钟
-->

---

<!-- _class: section -->

## 循环与一组数据

把重复的代码交给循环

<!--
用这一页交代接下来的问题。让学员把注意力从上一段代码转过来。
建议用时：1 分钟
-->

---

<!-- _class: code -->

## for 的执行顺序

```cpp
int sum = 0;
for (int i = 1; i <= 3; ++i) {
    sum += i;
}
```

初始化一次，判断后执行，最后更新

<!--
白板追踪 i/sum：1/1、2/3、3/6，下一次 i=4 条件失败。不要把 ++i 讲成循环体之前执行。
完整演示：Examples/L1_C05_D02.cpp
建议用时：3 分钟
-->

---

<!-- _class: trace -->

## 一次循环的状态表

```text
i       condition       sum after body
1       true            1
2       true            3
3       true            6
4       false           6
```

最后一次判断也会发生，但不会执行循环体

<!--
每一行追问：这次判断前i怎样得到，sum为何累加或不变。用白板或调试器逐步运行，避免学员只记住最后6。
建议用时：3 分钟
-->

---

<!-- _class: question -->

## 循环的边界

```cpp
for (int i = 0; i < 3; ++i) {
    std::cout << i << ' ' ;
}
```

输出 0 1 2  
条件改成 <= 3，会多出什么？

<!--
答案会多出 3，循环从三次变四次。提前连接到数组下标边界，半开区间 [0,3) 包含三个值。
建议用时：2 分钟
-->

---

<!-- _class: code -->

## continue 与 break

```cpp
for (int i = 0; i < 5; ++i) {
    if (i == 1) continue;
    if (i == 4) break;
    std::cout << i << ' ' ;
}
```

输出 0 2 3  
continue 跳过本轮，break 结束循环

<!--
追踪0..4。continue后仍执行for的更新表达式；break直接退出。学生将两个条件交换再预测是否变化，讨论为什么复杂循环要谨慎阅读。
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 数组的下标

```cpp
int scores[5] = {94, 87, 50};

std::cout << scores[0] << '\n';
std::cout << scores[4] << '\n';
```

5 个位置：0、1、2、3、4  
剩余元素初始化为 0

<!--
画在白板上即可，不把整份内存讲义投影。输出 94 和 0。scores[5] 越界是未定义行为，不保证报错，不现场以一次运行结果推断规则。
完整演示：Examples/L1_C06_D01.cpp
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 初始化方式影响元素的值

```cpp
int a[3] = {0};       // 0, 0, 0
int b[3] = {5};      // 5, 0, 0
int c[3];         // uninitialized local ints
```

未初始化的局部元素不能直接当作有效值读取

<!--
明确讨论main中的自动局部数组，不泛化到全局/静态数组。不要运行并依赖c出现的随机输出。说明显式零初始化建立可预测的起点。
建议用时：2 分钟
-->

---

<!-- _class: code -->

## std::array 的整体赋值

```cpp
std::array<int, 3> a = {94, 87, 50};
std::array<int, 3> b = {};
b = a;
b[0] = 100;
```

a[0] 仍是 94  
原生数组不能直接写 b = a

<!--
需要 array 头文件。对比 int a[3] 与 std::array 的赋值能力，拷贝后是独立对象。不要引入动态内存。
完整演示：Examples/L1_C06_D02.cpp
建议用时：2 分钟
-->

---

<!-- _class: trace -->

## 拷贝后是两组独立元素

```text
a:  94  87  50
b:  94  87  50   // after b = a

b[0] = 100

a:  94  87  50
b: 100  87  50
```

值复制建立新的对象；后续修改不会自动同步

<!--
逐个指明a和b拥有不同元素。把这个结论与接下来范围for的副本连接，不把底层存储布局当作本页目标。
建议用时：2 分钟
-->

---

<!-- _class: question -->

## 范围循环中的副本

```cpp
std::array<int, 3> scores = {60, 70, 80};

for (int score : scores) {
    score += 5;
}
```

循环后 scores[0] 是 60 还是 65？

<!--
先投票，再运行，仍是 60。每次 score 是元素的副本。下一页只改变一个符号来形成清晰对比。
完整演示：Examples/L1_C06_D03.cpp
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 用引用修改元素

```cpp
for (int& score : scores) {
    score += 5;
}
```

scores 变成 65、75、85  
& 在这里表示元素的别名

<!--
这里只建立别名直觉，引用与指针的系统解释留第二课。再展示只读遍历 const int&，说明它借用而不修改。
完整演示：Examples/L1_C06_D03.cpp
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 三种遍历写法

```cpp
for (int value : scores)      // copy
for (int& value : scores)     // modify element
for (const int& value : scores) // read only
```

先决定是否修改原元素，再选择循环变量类型

<!--
这里是语法对照，各行仍需要循环体。让学生各给一个场景：算总分、加奖励、只读较大对象。基本int复制成本很低，不把引用说成永远更好。
建议用时：2 分钟
-->

---

<!-- _class: practice -->

## 练习：统计及格人数

给定 {94, 87, 50, 60, 0}  
统计 ≥ 60 的元素个数  
再求平均分，预期为 58.2

<!--
应得到 3 人、总分 291。要求学生解释计数与累加的初始值、比较边界、浮点除法。提前完成者改成从输入读五项，或尝试空数据接口的防护作为讨论。
建议用时：7 分钟
-->

---

<!-- _class: code -->

## 统计问题的两个累加器

```cpp
int sum = 0, passed = 0;
for (int score : scores) {
    sum += score;
    if (score >= 60) ++passed;
}
double average =
    static_cast<double>(sum) / scores.size();
```

这组固定数据：sum=291，passed=3，average=58.2

<!--
本例scores固定有5项。讨论若设计允许空容器，就必须先处理size为0。先让学生解释为何两个累加器都从0开始，再展示参考写法。
建议用时：3 分钟
-->

---

<!-- _class: question -->

## 循环与数组检查

为什么 double x = 3 / 2 得不到 1.5？  
为什么 score += 5 可能没有改动数组？

<!--
让两位同学各解释一题，确认类型与副本概念。 用学生自己的代码解释，而不是只报结论。
建议用时：5 分钟
-->

---

<!-- _class: section -->

## 字符串

在一串名字里定位和修改内容

<!--
用这一页交代接下来的问题。让学员把注意力从上一段代码转过来。
建议用时：1 分钟
-->

---

<!-- _class: code -->

## 字符串也有下标

```cpp
std::string name("soyo");
std::cout << name.size() << '\n';
name[0] = 'S';
```

size 是 4，修改后是 Soyo

<!--
有效字符位置为 0..size()-1。本课程只使用 ASCII 名字，不把字节位置误讲成任意中文字符位置。at 可检查边界并抛异常，作为口头补充。
完整演示：Examples/L1_C07_D01.cpp
建议用时：2 分钟
-->

---

<!-- _class: question -->

## find 返回位置

```cpp
std::string members("soyo,anon,taki");
std::string::size_type pos = members.find("anon");
```

anon 从哪个下标开始？

<!--
数出 soyo 为 0..3，逗号是 4，anon 从 5 开始。不要让学生靠目测记一个数，要解释为什么有逗号位置。
完整演示：Examples/L1_C07_D02.cpp
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 没找到时是 npos

```cpp
std::string::size_type pos = members.find("rana");
if (pos != std::string::npos) {
    std::cout << pos << '\n';
}
```

位置 0 是成功，不能用 if(pos) 判断

<!--
再问 find("soyo") 为 0，用 if(pos) 会被当 false。未找到则为 npos，比较后才使用位置。
完整演示：Examples/L1_C07_D02.cpp
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 查找的三个边界

```cpp
members = "soyo,anon,taki";
find("soyo")  // 0: found at the start
find("taki")  // 10: found later
find("rana")  // npos: not found
```

起点、非起点、未找到，都要覆盖

<!--
此页是结果对照，不是可直接运行的函数调用。回到完整表达式members.find验证。问if(pos)对哪几类样例产生错误。
建议用时：2 分钟
-->

---

<!-- _class: code -->

## replace 改变后续位置

```cpp
std::string::size_type pos = members.find("anon");
if (pos != std::string::npos) {
    members.replace(pos, 4, "rana");
}
```

结果是 soyo,rana,taki  
换成更长名字后，要重新查找后续位置

<!--
4 是删除字符数，不是结束下标。先等长替换，再现场换成 tomori，观察后续下标移动。不在主屏放一整套字符串 API。
完整演示：Examples/L1_C07_D03.cpp
建议用时：2 分钟
-->

---

<!-- _class: code -->

## 追加与删除

```cpp
members += ",tomori";
members.insert(0, "rana,");
members.erase(0, 5);
```

删除名字时，分隔符由谁处理？

<!--
从 soyo,anon,taki 开始逐行运行。erase(0,5) 删除 rana,。clear 清空全部。指出位置按当前字符串算，不沿用修改前的下标。
完整演示：Examples/L1_C07_D04.cpp
建议用时：3 分钟
-->

---

<!-- _class: trace -->

## 字符串修改后的状态

```text
start:    soyo,anon,taki
append:   soyo,anon,taki,tomori
insert:   rana,soyo,anon,taki,tomori
erase:    soyo,anon,taki,tomori
```

每一步都在上一份结果上继续修改

<!--
对应上一页三行调用。学生标出被删的5个字符rana,。再问只删4个会留下什么：开头多一个逗号。
建议用时：2 分钟
-->

---

<!-- _class: practice -->

## 练习：查找并替换成员

起始：soyo,anon,taki  
找到 anon 时替换为 tomori  
找不到时保持原样

<!--
要求两次运行：有 anon、无 anon。再问目标出现在位置 0 时是否仍工作。期望 soyo,tomori,taki。强调不直接硬编码位置 5。
建议用时：6 分钟
-->

---

<!-- _class: section -->

## 整合与下一课

数据开始属于同一个对象

<!--
用这一页交代接下来的问题。让学员把注意力从上一段代码转过来。
建议用时：1 分钟
-->

---

<!-- _class: code -->

## 一条记录

```cpp
struct BandRecord {
    std::string guitar;
    std::string vocal;
};

BandRecord band = {"mutsumi", "hatsune"};
std::cout << band.guitar << '\n';
```

类型描述结构，对象保存一份具体数据

<!--
连接第二课 Band。不要把 struct 和 class 讲成两套不相关机制，默认访问权限不同。完整讲义的记录还含 bass，本页只显示两个字段以聚焦。
完整演示：Examples/L1_C08_D01.cpp
建议用时：3 分钟
-->

---

<!-- _class: code -->

## 类型与两份记录

```cpp
BandRecord a = {"mutsumi", "hatsune"};
BandRecord b = {"anon", "tomori"};
a.guitar = "soyo";
```

同一类型的两个对象，各自保存自己的字段

<!--
沿用本课投影的两个字段最小记录。b.guitar仍是anon。把类型比作结构约定即可，不引入继承。下一课会把操作也放进类。
建议用时：2 分钟
-->

---

<!-- _class: practice -->

## 综合：成绩报告

读取 3 个分数并存入 std::array  
循环求和，输出 1 位小数的平均分  
输出及格人数

<!--
输入 94 87 50，期望平均 77.0、及格 2。让学生自行组合刚学的输入、循环、类型转换、条件、格式。验收时要求解释一个边界，不只看输出。
建议用时：10 分钟
-->

---

<!-- _class: statement -->

## 综合程序的检查顺序

94 87 50：平均分 77.0，及格 2 人  
60 60 60：平均分 60.0，及格 3 人  
0 0 0：平均分 0.0，及格 0 人  
出错时依次检查输入、累计值、除法和比较

<!--
让学生互换测试样例并说出错误定位理由。将变量值临时输出用于定位，修复后删除调试输出。最后回到开场的Python口述解法，对照已经完成的各部分。
建议用时：4 分钟
-->

---

<!-- _class: question -->

## 第一课回看

读到一个新程序，你会先看哪里？  
算错结果，你会先检查什么？  
下一课：函数怎样改变调用者的数据？

<!--
引导回答 main、输入、类型、条件、循环边界。课后完成 Assessment-01 必做，挑战单独说明。完整资料见讲义与例题索引，不在放映中翻答案。
建议用时：3 分钟
-->
