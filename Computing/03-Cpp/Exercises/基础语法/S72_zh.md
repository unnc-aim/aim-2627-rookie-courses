# S72 排序和平局

Lesson 1 · Chapter 08 · 第一课整合与结构体预告

## 题目

输入 n 条 id、score，按 score 降序、id 升序输出 id，每行一个。n≤1000。

## 样例输入

```text
3 9 10 7 20 2 20
```

## 样例输出

```text
2
7
9
```

## 逐步推导

先比较 score，不相等直接决定顺序；相等时比较 id，完整表达二级排序。

## 关键规则与边界

比较器使用严格比较，不能写 >=。lambda 是就地定义的可调用对象。

## 完整单文件参考程序

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

struct Record {
    int id = 0;
    int score = 0;
};

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<Record> records(n);
    for (Record & r : records)
        std::cin >> r.id >> r.score;
    std::sort(records.begin(), records.end(), [](const Record &a, const Record &b) {
        if (a.score != b.score)
            return a.score > b.score;
        return a.id < b.id;
    });
    for (const Record & r : records)
        std::cout << r.id << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
