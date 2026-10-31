# S51 速度限幅函数

第 1 课 · 1.8 · 函数——让计算有明确的输入和输出

## 题目

实现 clamp_speed(v,limit)，输入 v 与非负 limit，输出夹到 [-limit,limit] 的值。

## 样例输入

```text
8 3
```

## 样例输出

```text
3
```

## 逐步推导

先用 min 限制上界，再用 max 限制下界；范围里的请求保持不变。

## 关键规则与边界

把纯计算抽成函数，边界条件不依赖输入输出代码。

## 完整单文件参考程序

```cpp
#include <algorithm>
#include <iostream>

int clamp_speed(int v, int limit) { return std::max(-limit, std::min(v, limit)); }

int main() {
    int v = 0, limit = 0;
    std::cin >> v >> limit;
    std::cout << clamp_speed(v, limit) << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
