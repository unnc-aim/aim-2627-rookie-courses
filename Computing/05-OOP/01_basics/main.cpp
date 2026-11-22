// oop1.cpp —— 面向对象入门版（解决与 proc.cpp 相同的问题）
//
// 编译：g++ -std=c++17 -Wall -Wextra -o oop1 oop1.cpp
// 运行：./oop1

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include "Pet.hpp"

void print_all(const std::vector<Pet> &pets)
{
    for (const Pet &pet : pets)
    {
        pet.print();
    }
}

std::size_t find_by_name(const std::vector<Pet> &pets, const std::string &target)
{
    for (std::size_t i = 0; i < pets.size(); ++i)
    {
        if (pets[i].name() == target)
        {
            return i;
        }
    }
    return pets.size();
}

int main()
{
    // 单只宠物
    Pet cat("cat", "xiaohui", 3);
    cat.print();

    std::cout << "----------------\n";

    // 多只宠物：每个元素都是一个完整的 Pet 对象
    std::vector<Pet> pets{
        Pet("cat", "xiaohui", 3),
        Pet("dog", "wangcai", 5),
        Pet("rabbit", "tuanzi", 1),
    };

    print_all(pets);

    pets[0].rename("huihui");
    pets[0].rename(""); // 空名字会被拒绝
    std::cout << "---- after rename ----\n";
    print_all(pets);

    const std::size_t idx = find_by_name(pets, "wangcai");
    if (idx != pets.size())
    {
        std::cout << "found: ";
        pets[idx].print();
    }

    // 下面这行无法编译，因为 name_ 是 private：
    //   cat.name_ = "hacked";

    return 0;
}
