# S44 逗号字段拆分

第 1 课 · 1.7 · 字符串流：把一行文本真正解析成有效数据

## 题目

输入一行，按逗号拆分，每个字段用 [] 包住并逐行输出，保留首尾与相邻空字段。

## 样例输入

```text
a,,b,
```

## 样例输出

```text
[a]
[]
[b]
[]
```

## 逐步推导

用 begin 追踪字段起点，find 找下一个逗号；最后即使为空也输出一次。

## 关键规则与边界

npos-begin 仍足够大，substr 会截到字符串末尾；空行应产生一个空字段。

## 完整单文件参考程序

```cpp
#include <cstddef>
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::size_t begin = 0;
    while (true) {
        std::string::size_type end = s.find(',', begin);
        std::cout << '[' << s.substr(begin, end - begin) << "]\n";
        if (end == std::string::npos)
            break;
        begin = end + 1;
    }
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
