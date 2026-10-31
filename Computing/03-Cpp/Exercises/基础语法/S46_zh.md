# S46 单词计数

第 1 课 · 1.7 · 字符串流：把一行文本真正解析成有效数据

## 题目

输入一行，按空白分词，输出单词个数。

## 样例输入

```text
  AIM   Sentry  07
```

## 样例输出

```text
3
```

## 逐步推导

用字符串流重复提取 word，每次成功提取计数加一，不把连续空格当空单词。

## 关键规则与边界

istringstream 使用流提取规则，可以合并多个空白分隔符。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line, word;
    std::getline(std::cin, line);
    std::istringstream stream(line);
    int count = 0;
    while (stream >> word)
        ++count;
    std::cout << count << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
