// pet.cpp —— Pet / Cat / Dog / Rabbit 成员函数的具体实现
//
// 注意：virtual、override、= 0 只写在 pet.h 的类声明里，
// 类外实现时用 "类名::函数名" 指明归属，不再重复写 virtual / override。

#include "pet.hpp"

#include <iostream>

constexpr int kCurrentYear = 2026;

// ============================================================
// Pet 实现
// ============================================================

Pet::Pet(const std::string &name, int birth_year)
    : name_(name), birth_year_(birth_year)
{
}

const std::string &Pet::name() const
{
    return name_;
}

int Pet::age() const
{
    return kCurrentYear - birth_year_;
}

void Pet::rename(const std::string &new_name)
{
    if (new_name.empty())
    {
        std::cout << "!! empty name rejected\n";
        return;
    }
    name_ = new_name;
}

void Pet::print() const
{
    std::cout << name_ << " is a " << kind()
              << ", age " << age() << '\n';
}

// ============================================================
// Cat 实现
// ============================================================

Cat::Cat(const std::string &name, int birth_year)
    : Pet(name, birth_year)
{
}

std::string Cat::kind() const
{
    return "cat";
}

void Cat::speak() const
{
    std::cout << name() << ": Meow~\n";
}

void Cat::catch_mouse() const
{
    std::cout << name() << " caught a mouse!\n";
}

// ============================================================
// Dog 实现
// ============================================================

Dog::Dog(const std::string &name, int birth_year)
    : Pet(name, birth_year)
{
}

std::string Dog::kind() const
{
    return "dog";
}

void Dog::speak() const
{
    std::cout << name() << ": Woof!\n";
}

void Dog::fetch() const
{
    std::cout << name() << " fetched the ball!\n";
}

// ============================================================
// Rabbit 实现
// ============================================================

Rabbit::Rabbit(const std::string &name, int birth_year)
    : Pet(name, birth_year)
{
}

std::string Rabbit::kind() const
{
    return "rabbit";
}

void Rabbit::speak() const
{
    std::cout << name() << ": Squeak!\n";
}
