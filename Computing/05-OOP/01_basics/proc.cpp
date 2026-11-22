// proc.cpp —— 面向过程版本（对照示例）
//
// 编译：g++ -std=c++17 -Wall -Wextra -o proc proc.cpp
// 运行：./proc

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

// 阶段一：只有一只宠物

void print_name(const std::string &name)
{
    std::cout << "Its name is: " << name << '\n';
}

void print_kind(const std::string &kind)
{
    std::cout << "It is a " << kind << '\n';
}

// 阶段二：管理多只宠物

void print_all(const std::vector<std::string> &kinds,
               const std::vector<std::string> &names,
               const std::vector<int> &ages)
{
    for (std::size_t i = 0; i < names.size(); ++i)
    {
        std::cout << names[i] << " is a " << kinds[i]
                  << ", age " << ages[i] << '\n';
    }
}

// 改名字：必须把整张"名字表"和下标一起传进来
void rename(std::vector<std::string> &names,
            std::size_t index,
            const std::string &new_name)
{
    names[index] = new_name;
}

// 按名字查找：找不到时约定返回 names.size()
std::size_t find_by_name(const std::vector<std::string> &names,
                         const std::string &target)
{
    for (std::size_t i = 0; i < names.size(); ++i)
    {
        if (names[i] == target)
        {
            return i;
        }
    }
    return names.size();
}

int main()
{
    // ---- 阶段一 ----
    std::string kind = "cat";
    std::string name = "xiaohui";

    print_kind(kind);
    print_name(name);

    std::cout << "----------------\n";

    // ---- 阶段二 ----
    // 三个 vector 必须时刻保持下标对齐
    std::vector<std::string> kinds{"cat", "dog", "rabbit"};
    std::vector<std::string> names{"xiaohui", "wangcai", "tuanzi"};
    std::vector<int> ages{3, 5, 1};

    print_all(kinds, names, ages);

    rename(names, 0, "huihui");
    std::cout << "---- after rename ----\n";
    print_all(kinds, names, ages);

    const std::size_t idx = find_by_name(names, "wangcai");
    if (idx != names.size())
    {
        std::cout << "found: " << names[idx] << " is a " << kinds[idx] << '\n';
    }

    return 0;
}
