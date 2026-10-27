# S63 按值返回避免悬空

Lesson 2 · Chapter 02 · 引用、地址与指针

## 题目

make_values 在函数内部创建 vector{1,2,3} 并按值返回，调用方输出 size 和首元素。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
3 1
```

## 逐步推导

函数按值返回完整容器，调用方持有自己的结果，不引用已经销毁的局部容器。

## 关键规则与边界

不要返回局部变量的引用或指针。按值返回可由编译器消除复制或移动。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <vector>

std::vector<int> make_values() { return {1, 2, 3}; }

int main() {
    std::vector<int> values = make_values();
    std::cout << values.size() << ' ' << values.front() << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
