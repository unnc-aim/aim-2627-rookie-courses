# S75 受限命令解释器

第 1 课 · 1.7 · 字符串流：把一行文本真正解析成有效数据

## 题目

输入多行 ADD 整数或 RESET，格式合法才生效，其他忽略。最后输出累加器值，数值绝对值与行数≤1000。

## 样例输入

```text
ADD 5
BAD 9
RESET
ADD 3
```

## 样例输出

```text
3
```

## 逐步推导

先解析操作与参数并检查尾部，完整合法后才更新累加器。

## 关键规则与边界

整行验证完成后再修改状态，避免脏行部分生效。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;
    long long value = 0;
    while (std::getline(std::cin, line)) {
        std::istringstream in(line);
        std::string op, extra;
        int x = 0;
        if (!(in >> op))
            continue;
        if (op == "ADD" && (in >> x) && !(in >> extra))
            value += x;
        else if (op == "RESET" && !(in >> extra))
            value = 0;
    }
    std::cout << value << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
