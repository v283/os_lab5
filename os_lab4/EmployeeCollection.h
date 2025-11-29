#pragma once
#include <vector>
#include <string>
#include "Employee.h"

class EmployeeCollection
{
public:
    using container_type = std::vector<Employee>;
    using iterator = container_type::iterator;
    using const_iterator = container_type::const_iterator;

private:
    container_type data;

public:
    EmployeeCollection() = default;

    void Add(const Employee& e);
    std::size_t Size() const;
    bool Empty() const;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    // Пошук 
    std::vector<const Employee*> FindByProfession(const std::string& prof) const;
};