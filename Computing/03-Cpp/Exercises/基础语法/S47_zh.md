# S47 严格整数解析

第 1 课 · 1.7 · 字符串流：把一行文本真正解析成有效数据

## 题目

读取一行，仅允许前后空白和一个 int，尾部存在额外字符或溢出时输出 INVALID。

## 样例输入

```text
12abc
```

## 样例输出

```text
INVALID
```

## 逐步推导

先检查整数提取，再试图提取额外字符；存在额外内容就拒绝整行。

## 关键规则与边界

只检查第一个提取会误把 12abc 当作合法整数 12。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream stream(line);
    int value = 0;
    char extra = '\0';
    if ((stream >> value) && !(stream >> extra))
        std::cout << value << '\n';
    else
        std::cout << "INVALID\n";
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
