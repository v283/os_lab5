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

    // Додавання елемента
    void Add(const Employee& e)
    {
        data.push_back(e);
    }

    std::size_t Size() const
    {
        return data.size();
    }

    bool Empty() const
    {
        return data.empty();
    }

    // Ітератори (вимога "реалізація ітератора")
    iterator begin() { return data.begin(); }
    iterator end() { return data.end(); }
    const_iterator begin() const { return data.begin(); }
    const_iterator end()   const { return data.end(); }
    const_iterator cbegin() const { return data.cbegin(); }
    const_iterator cend()   const { return data.cend(); }

    // === Пошук за варіантом №5: імена службовців заданої професії ===
    std::vector<const Employee*> FindByProfession(const std::string& prof) const
    {
        std::vector<const Employee*> res;

        for (const auto& e : data)
        {
            if (e.Profession() == prof)
                res.push_back(&e);
        }

        return res;
    }
};
