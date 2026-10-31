# S02 多个字段输出

第 1 课 · 1.1 · Python 和 C++ 的程序分别怎样跑起来？

## 题目

把机器人编号 7 与名称 Sentry 输出成 id=7 name=Sentry。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
id=7 name=Sentry
```

## 逐步推导

id 保存整数、name 保存字符串；按字面前缀、值、分隔空格的顺序插入同一个流。

## 关键规则与边界

字符字面量用单引号，字符串字面量用双引号。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <string>

int main() {
    int id = 7;
    std::string name("Sentry");
    std::cout << "id=" << id << " name=" << name << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
