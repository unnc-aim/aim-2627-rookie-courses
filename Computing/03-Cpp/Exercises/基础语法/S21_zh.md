# S21 switch 指令

第 1 课 · 1.3 · 把 Python 的条件判断迁移过来

## 题目

输入字符 F、L、R 分别输出 FORWARD、LEFT、RIGHT，其他输出 UNKNOWN。

## 样例输入

```text
L
```

## 样例输出

```text
LEFT
```

## 逐步推导

每个合法字符对应一个 case，输出后 break；未知字符统一进入 default。

## 关键规则与边界

break 结束 switch，遗漏时可能落入下一个分支。

## 完整单文件参考程序

```cpp
#include <iostream>

int main() {
    char op = '\0';
    std::cin >> op;
    switch (op) {
    case 'F':
        std::cout << "FORWARD\n";
        break;
    case 'L':
        std::cout << "LEFT\n";
        break;
    case 'R':
        std::cout << "RIGHT\n";
        break;
    default:
        std::cout << "UNKNOWN\n";
    }
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
