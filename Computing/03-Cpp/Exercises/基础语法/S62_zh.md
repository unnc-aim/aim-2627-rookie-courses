# S62 const 引用遍历

第 1 课 · 1.9 · 先认识内存和地址，再理解引用

## 题目

用 const `vector<int>`& 实现 sum，不复制 vector，输入 n 个≤1000 的整数，输出和。n≤1000。

## 样例输入

```text
3 1 2 3
```

## 样例输出

```text
6
```

## 逐步推导

参数用只读引用，局部 long long 累加所有元素并按值返回结果。

## 关键规则与边界

const 引用表达只读借用，函数执行期间调用方对象必须存活。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <vector>

long long sum(const std::vector<int> &a) {
    long long result = 0;
    for (int x : a)
        result += x;
    return result;
}

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x : a)
        std::cin >> x;
    std::cout << sum(a) << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
