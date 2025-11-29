#pragma once
#include <vector>
#include <string>
#include "Employee.h"

class EmployeeCollection
{
public:
    // Визначення типів (для сумісності з STL)
    using container_type = std::vector<Employee>;
    using iterator = container_type::iterator;
    using const_iterator = container_type::const_iterator;

private:
    container_type data;

public:
    EmployeeCollection() = default;

    // Методи керування
    void Add(const Employee& e);
    std::size_t Size() const;
    bool Empty() const;

    // Ітератори (реалізація п.7)
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;

    // Пошук за варіантом №5
    std::vector<const Employee*> FindByProfession(const std::string& prof) const;
};