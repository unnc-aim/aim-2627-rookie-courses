# O04 拒绝无效修改

第 2 课 · 2.1 · 从一份记录到一个会做事的对象

## 题目

Magazine 初值 5，reload(n) 仅接受 n>=0 且总数≤10，成功返回 true，失败保持原状态。测试 +4 与 +2。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
1 0 9
```

## 逐步推导

先加四到九，再请求加二；第二次拒绝，弹数不应部分变动。

## 关键规则与边界

先检查全部条件，再提交修改，保证失败不改变对象。

## 完整单文件参考程序

```cpp
#include <iostream>

class Magazine {
    int rounds_ = 5;

  public:
    bool reload(int n) {
        if (n < 0 || n > 10 - rounds_)
            return false;
        rounds_ += n;
        return true;
    }
    int rounds() const { return rounds_; }
};

int main() {
    Magazine m;
    std::cout << m.reload(4) << ' ' << m.reload(2) << ' ' << m.rounds() << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
