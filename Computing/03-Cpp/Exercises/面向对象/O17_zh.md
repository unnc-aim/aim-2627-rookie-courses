# O17 引用传参与复制传参

第 2 课 · 2.3 · 怎样使用和传递对象：const、this、复制与引用

## 题目

Counter 从 0 开始，touch_copy 按值加一，touch_ref 按引用加一，调用二者后输出原计数。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
1
```

## 逐步推导

第一次只改临时形参，第二次改原对象，因此总计只增加一次。

## 关键规则与边界

参数类型表达是否允许修改调用方对象。

## 完整单文件参考程序

```cpp
#include <iostream>

struct Counter {
    int value = 0;
};
void touch_copy(Counter c) { ++c.value; }
void touch_ref(Counter &c) { ++c.value; }

int main() {
    Counter c;
    touch_copy(c);
    touch_ref(c);
    std::cout << c.value << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
