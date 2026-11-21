// pet.h —— 抽象基类 Pet 与具体子类 Cat / Dog / Rabbit 的声明
//
// 头文件相当于"接口说明书"：只放类的结构、成员变量和函数声明，
// 具体函数体写在 pet.cpp 里。

#pragma once

#include <string>

class Pet
{
private:
    std::string name_;
    int birth_year_;

public:
    Pet(const std::string &name, int birth_year);

    // 多态基类必须声明虚析构函数
    virtual ~Pet() = default;

    const std::string &name() const;
    int age() const;
    void rename(const std::string &new_name);

    // 纯虚函数：具体种类和叫声由子类实现
    virtual std::string kind() const = 0;
    virtual void speak() const = 0;

    void print() const;
};

class Cat : public Pet
{
public:
    Cat(const std::string &name, int birth_year);

    std::string kind() const override;
    void speak() const override;
    void catch_mouse() const;
};

class Dog : public Pet
{
public:
    Dog(const std::string &name, int birth_year);

    std::string kind() const override;
    void speak() const override;
    void fetch() const;
};

class Rabbit : public Pet
{
public:
    Rabbit(const std::string &name, int birth_year);

    std::string kind() const override;
    void speak() const override;
};
