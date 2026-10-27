# O25 诊断消息集合

Lesson 2 · Chapter 09 · 原课程整合与工程拓展

## 题目

Diagnostics 保存非空消息，add 忽略空串，report 每行输出一条，依次添加 OK、空串、LOW。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
OK
LOW
```

## 逐步推导

入口先过滤空消息，其余按插入顺序保存，报告不改变集合。

## 关键规则与边界

聚合多个标准库成员即可实现明确职责，不必为每个类型设计继承层次。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <string>
#include <vector>

class Diagnostics {
    std::vector<std::string> messages_;

  public:
    void add(const std::string &s) {
        if (!s.empty())
            messages_.push_back(s);
    }
    void report() const {
        for (const std::string & s : messages_)
            std::cout << s << '\n';
    }
};

int main() {
    Diagnostics d;
    d.add("OK");
    d.add("");
    d.add("LOW");
    d.report();
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
