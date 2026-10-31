# S37 复制与修改

第 1 课 · 1.5 · Python 的 list 到了 C++，该用什么？

## 题目

复制 vector {1,2,3} 到 b，修改 b[0]=9，分别输出 a[0] 和 b[0]。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
1 9
```

## 逐步推导

先复制，再只修改 b；输出时明确分别读取两个对象。

## 关键规则与边界

vector 具有值语义，复制后的元素存储独立。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = a;
    b[0] = 9;
    std::cout << a[0] << ' ' << b[0] << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
