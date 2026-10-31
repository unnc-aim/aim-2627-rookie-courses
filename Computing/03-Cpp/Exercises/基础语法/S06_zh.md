# S06 输入失败检测

第 1 课 · 1.3 · 把 Python 的条件判断迁移过来

## 题目

读取一个整数，失败输出 INVALID，成功输出其两倍。范围不超过 1000。

## 样例输入

```text
robot
```

## 样例输出

```text
INVALID
```

## 逐步推导

把提取表达式放进条件；失败路径立即给出 INVALID，成功路径才参与乘法。

## 关键规则与边界

读取失败后流进入失败状态，不能继续假定变量已取得合法值。

## 完整单文件参考程序

```cpp
#include <iostream>

int main() {
    int value = 0;
    if (!(std::cin >> value)) {
        std::cout << "INVALID\n";
    } else {
        std::cout << 2 * value << '\n';
    }
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
