# S35 vector 动态追加

第 1 课 · 1.5 · Python 的 list 到了 C++，该用什么？

## 题目

读入直到 EOF 的整数，保存到 vector，倒序每行输出。

## 样例输入

```text
1 2 3
```

## 样例输出

```text
3
2
1
```

## 逐步推导

读取成功就 push_back；倒序计数从 size 开始，访问 i-1 而非访问 size。

## 关键规则与边界

size_t 是无符号类型，用 i>0 避免 i>=0 的下溢死循环。

## 完整单文件参考程序

```cpp
#include <cstddef>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> a;
    int value = 0;
    while (std::cin >> value)
        a.push_back(value);
    for (std::size_t i = a.size(); i > 0; --i)
        std::cout << a[i - 1] << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
