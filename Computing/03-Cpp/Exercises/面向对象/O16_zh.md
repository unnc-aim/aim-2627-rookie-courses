# O16 对象值复制

第 2 课 · 2.3 · 怎样使用和传递对象：const、this、复制与引用

## 题目

Robot 内含 vector{1,2}，复制 a 到 b，修改 b 首项为 9，输出 a 与 b 首项。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
1 9
```

## 逐步推导

默认复制逐成员复制 vector，修改 b 不会反向修改 a。

## 关键规则与边界

标准容器成员使默认复制得到独立元素，适合使用 Rule of Zero。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <vector>

struct Robot {
    std::vector<int> values = {1, 2};
};

int main() {
    Robot a;
    Robot b = a;
    b.values[0] = 9;
    std::cout << a.values[0] << ' ' << b.values[0] << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
