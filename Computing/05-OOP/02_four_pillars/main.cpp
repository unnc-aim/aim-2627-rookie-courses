// main.cpp —— 面向对象四大特性综合示例入口（调用 pet.h 中声明的类）
//
// 编译：g++ -std=c++17 -Wall -Wextra -o oop2 main.cpp pet.cpp
// 运行：./oop2

#include "pet.hpp"

#include <iostream>
#include <memory>
#include <vector>

// 面向抽象基类 Pet 编写的通用函数：后续新增动物子类时，这里无需改动
void greet_all(const std::vector<std::unique_ptr<Pet>> &pets)
{
    for (const auto &pet : pets)
    {
        pet->print();
        pet->speak();
    }
}

int main()
{
    // 1. 直接使用具体子类，可调用各自的特有行为
    Cat xiaohui("xiaohui", 2023);
    Dog wangcai("wangcai", 2021);
    xiaohui.catch_mouse();
    wangcai.fetch();

    std::cout << "----------------\n";

    // 2. 通过基类智能指针放进同一个容器统一管理（多态）
    std::vector<std::unique_ptr<Pet>> pets;
    pets.push_back(std::make_unique<Cat>("xiaohui", 2023));
    pets.push_back(std::make_unique<Dog>("wangcai", 2021));
    pets.push_back(std::make_unique<Rabbit>("tuanzi", 2025));

    greet_all(pets);

    std::cout << "---- after rename ----\n";
    pets[0]->rename("huihui");
    pets[0]->rename(""); // 封装校验依然生效
    pets[0]->print();

    // 下面这行无法编译，因为 Pet 是抽象类：
    //   Pet p("mystery", 2024);

    return 0;
}
