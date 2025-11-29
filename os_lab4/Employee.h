#pragma once
#include <string>
#include <iostream>

class Employee
{
private:
    std::string name;
    std::string profession;

public:

    Employee();


    Employee(const std::string& name, const std::string& profession);


    const std::string& Name() const;
    const std::string& Profession() const;

    // Метод виводу
    void Show(std::ostream& out = std::cout) const;
};