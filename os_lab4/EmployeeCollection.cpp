#include "EmployeeCollection.h"

void EmployeeCollection::Add(const Employee& e)
{
    data.push_back(e);
}

std::size_t EmployeeCollection::Size() const
{
    return data.size();
}

bool EmployeeCollection::Empty() const
{
    return data.empty();
}

// --- Реалізація ітераторів ---

EmployeeCollection::iterator EmployeeCollection::begin()
{
    return data.begin();
}

EmployeeCollection::iterator EmployeeCollection::end()
{
    return data.end();
}

EmployeeCollection::const_iterator EmployeeCollection::begin() const
{
    return data.begin();
}

EmployeeCollection::const_iterator EmployeeCollection::end() const
{
    return data.end();
}

EmployeeCollection::const_iterator EmployeeCollection::cbegin() const
{
    return data.cbegin();
}

EmployeeCollection::const_iterator EmployeeCollection::cend() const
{
    return data.cend();
}

// --- Реалізація пошуку (Варіант 5) ---

std::vector<const Employee*> EmployeeCollection::FindByProfession(const std::string& prof) const
{
    std::vector<const Employee*> res;

    for (const auto& e : data)
    {
        if (e.Profession() == prof)
            res.push_back(&e);
    }

    return res;
}