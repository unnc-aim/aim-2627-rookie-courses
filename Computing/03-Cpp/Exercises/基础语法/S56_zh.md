# S56 布尔结果与输出参数

第 1 课 · 1.9 · 先认识内存和地址，再理解引用

## 题目

实现 safe_divide(a,b,out)，b=0 返回 false 且不修改 out，否则写入整数商。输入范围≤1000。

## 样例输入

```text
5 0
```

## 样例输出

```text
false 99
```

## 逐步推导

先拒绝零除数，成功时才写 out，最后返回状态。

## 关键规则与边界

失败路径保持输出参数原值，这项契约需要独立验证。

## 完整单文件参考程序

```cpp
#include <iostream>

bool safe_divide(int a, int b, int &out) {
    if (b == 0)
        return false;
    out = a / b;
    return true;
}

int main() {
    int a = 0, b = 0, answer = 99;
    std::cin >> a >> b;
    bool ok = safe_divide(a, b, answer);
    std::cout << std::boolalpha << ok << ' ' << answer << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
