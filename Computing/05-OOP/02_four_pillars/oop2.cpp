// oop2.cpp —— 面向对象四大特性综合示例（封装、继承、多态、抽象）
//
// 编译：g++ -std=c++17 -Wall -Wextra -o oop2 oop2.cpp
// 运行：./oop2

#include <iostream>
#include <memory>
#include <string>
#include <vector>

constexpr int kCurrentYear = 2026;

// ============================================================
// 抽象基类 Pet：
//   - 封装共有状态（name_ / birth_year_）与改名校验规则
//   - 通过纯虚函数（= 0）规定子类必须实现 kind() 和 speak()
//   - 含纯虚函数，不能直接实例化 Pet 对象
// ============================================================
class Pet
{
private:
    std::string name_;
    int birth_year_;

public:
    Pet(const std::string &name, int birth_year)
        : name_(name), birth_year_(birth_year)
    {
    }

    // 多态基类必须声明虚析构函数，避免通过基类指针销毁子类时漏掉子类析构
    virtual ~Pet() = default;

    // 封装内部变化：底层改存 birth_year_，对外 age() 接口保持不变
    const std::string &name() const { return name_; }
    int age() const { return kCurrentYear - birth_year_; }

    void rename(const std::string &new_name)
    {
        if (new_name.empty())
        {
            std::cout << "!! empty name rejected\n";
            return;
        }
        name_ = new_name;
    }

    // 纯虚函数：具体种类和叫声由子类决定
    virtual std::string kind() const = 0;
    virtual void speak() const = 0;

    // 通用打印逻辑放在基类，内部多态调用子类的 kind()
    void print() const
    {
        std::cout << name_ << " is a " << kind()
                  << ", age " << age() << '\n';
    }
};

// ============================================================
// 具体子类：公有继承 Pet，复用共有部分并扩展各自特色
// ============================================================

class Cat : public Pet
{
public:
    Cat(const std::string &name, int birth_year)
        : Pet(name, birth_year)
    {
    }

    std::string kind() const override { return "cat"; }

    void speak() const override
    {
        std::cout << name() << ": Meow~\n";
    }

    void catch_mouse() const
    {
        std::cout << name() << " caught a mouse!\n";
    }
};

class Dog : public Pet
{
public:
    Dog(const std::string &name, int birth_year)
        : Pet(name, birth_year)
    {
    }

    std::string kind() const override { return "dog"; }

    void speak() const override
    {
        std::cout << name() << ": Woof!\n";
    }

    void fetch() const
    {
        std::cout << name() << " fetched the ball!\n";
    }
};

class Rabbit : public Pet
{
public:
    Rabbit(const std::string &name, int birth_year)
        : Pet(name, birth_year)
    {
    }

    std::string kind() const override { return "rabbit"; }

    void speak() const override
    {
        std::cout << name() << ": Squeak!\n";
    }
};

// ============================================================
// 面向抽象基类编写的通用函数：后续新增动物子类时，这里无需改动
// ============================================================

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
