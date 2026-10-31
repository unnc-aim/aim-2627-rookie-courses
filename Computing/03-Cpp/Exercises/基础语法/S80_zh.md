# S80 任务汇总报表

第 1 课 · 1.11 · 把相关字段组织成记录，并处理一批记录

## 题目

输入 n 条 id、hp，hp 限幅到 [0,100]，按 id 升序输出 id:hp，最后输出 ALIVE=存活数。id 唯一，n≤1000。

## 样例输入

```text
2 7 120 2 -5
```

## 样例输出

```text
2:0
7:100
ALIVE=1
```

## 逐步推导

读取时统一限幅并统计存活，再排序输出，不用原始血量作另一套判断。

## 关键规则与边界

输入规范化与统计使用同一份限幅后的数据，避免显示值和状态不一致。

## 完整单文件参考程序

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

struct Unit {
    int id = 0;
    int hp = 0;
};

int main() {
    int n = 0, alive = 0;
    std::cin >> n;
    std::vector<Unit> units(n);
    for (Unit & u : units) {
        std::cin >> u.id >> u.hp;
        u.hp = std::clamp(u.hp, 0, 100);
        alive += u.hp > 0;
    }
    std::sort(units.begin(), units.end(),
              [](const Unit &a, const Unit &b) { return a.id < b.id; });
    for (const Unit & u : units)
        std::cout << u.id << ':' << u.hp << '\n';
    std::cout << "ALIVE=" << alive << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
