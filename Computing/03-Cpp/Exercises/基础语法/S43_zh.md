# S43 安全替换首次命中

第 1 课 · 1.6 · 字符串、字符，以及“读一个词”和“读一整行”

## 题目

输入一行文本，把第一次 anon 替换成 saki，不存在则保持原文。

## 样例输入

```text
soyo,anon,taki
```

## 样例输出

```text
soyo,saki,taki
```

## 逐步推导

每次只查第一次命中，不进入重复替换循环；未命中时完全不修改原文本。

## 关键规则与边界

先判断 find 结果，去年演示中的直接 replace(find(...)) 在未命中时会抛异常。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <string>

int main() {
    std::string text;
    std::getline(std::cin, text);
    std::string::size_type pos = text.find("anon");
    if (pos != std::string::npos)
        text.replace(pos, 4, "saki");
    std::cout << text << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
