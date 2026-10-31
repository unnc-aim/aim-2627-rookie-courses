# O23 注入可替换配置

第 2 课 · 2.4 · 先学组合：一个对象拥有另一些对象

## 题目

Policy 含 max_speed，Controller 通过构造复制配置，对请求限幅。两个配置 2 和 5 对请求 4 各输出结果。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
2 4
```

## 逐步推导

相同请求分别经过两个对象自己的配置，不能共享一套被后构造覆盖的全局上限。

## 关键规则与边界

把变化的数据作为配置传入，减少对全局变量的依赖。题目保证 max_speed 非负。

## 完整单文件参考程序

```cpp
#include <algorithm>
#include <iostream>

struct Policy {
    int max_speed = 1;
};
class Controller {
    Policy policy_;

  public:
    explicit Controller(Policy p) : policy_(p) {}
    int command(int v) const {
        return std::clamp(v, -policy_.max_speed, policy_.max_speed);
    }
};

int main() {
    Controller a(Policy{2}), b(Policy{5});
    std::cout << a.command(4) << ' ' << b.command(4) << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
