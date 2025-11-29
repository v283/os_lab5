#pragma once
#include <string>
#include <iostream>

class Employee
{
private:
    std::string name;
    std::string profession;

public:
    Employee() = default;

    Employee(const std::string& name,
        const std::string& profession)
        : name(name), profession(profession)
    {
    }

    const std::string& Name() const { return name; }
    const std::string& Profession() const { return profession; }

    void Show(std::ostream& out = std::cout) const
    {
        out << "Ім'я: " << name
            << ", професія: " << profession;
    }
};
