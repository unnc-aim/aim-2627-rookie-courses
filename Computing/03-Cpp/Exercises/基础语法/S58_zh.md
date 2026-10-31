# S58 引用交换

第 1 课 · 1.9 · 先认识内存和地址，再理解引用

## 题目

用 int& 实现 swap_ref，读取两个整数并交换后输出。

## 样例输入

```text
10 20
```

## 样例输出

```text
20 10
```

## 逐步推导

临时量保存原 a，再把 b 写入 a，最后把临时量写入 b。

## 关键规则与边界

引用是已有对象的别名，通常需初始化，之后不能重新绑定。

## 完整单文件参考程序

```cpp
#include <iostream>

void swap_ref(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int a = 0, b = 0;
    std::cin >> a >> b;
    swap_ref(a, b);
    std::cout << a << ' ' << b << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
