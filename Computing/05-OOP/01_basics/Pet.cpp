#include "Pet.hpp"
#include <iostream>

Pet::Pet(const std::string &kind, const std::string &name, int age)
    : kind_(kind), name_(name), age_(age) {}

const std::string &Pet::name() const
{
    return name_;
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
    std::cout << name_ << " is a " << kind_
            << ", age" << age_ << '\n';
}