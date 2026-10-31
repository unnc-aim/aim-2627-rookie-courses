# O39 不可复制的设备

第 2 课 · 2.5 · 对象何时结束，资源由谁清理？

## 题目

Device 删除复制构造与复制赋值，仍可默认构造和调用 id 输出 7。指出复制语句应编译失败。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
7
```

## 逐步推导

正常示例只构造一个对象，复制语句放到故障实验中验证接口限制。

## 关键规则与边界

=delete 让类型的所有权限制在编译时可见，避免意外复制唯一设备句柄。

## 完整单文件参考程序

```cpp
#include <iostream>

class Device {
  public:
    Device() = default;
    Device(const Device &) = delete;
    Device &operator=(const Device &) = delete;
    int id() const { return 7; }
};

int main() {
    Device d;
    std::cout << d.id() << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
