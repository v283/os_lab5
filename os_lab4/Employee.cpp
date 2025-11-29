#include "Employee.h"

// ÄÅËÅÃÓÂÀÍÍß ÊÎÍÑÒĞÓÊÒÎĞ²Â
Employee::Employee()
    : Employee("Íåâ³äîìî", "Íåâ³äîìî")
{
}

Employee::Employee(const std::string& name, const std::string& profession)
    : name(name), profession(profession)
{
}

const std::string& Employee::Name() const
{
    return name;
}

const std::string& Employee::Profession() const
{
    return profession;
}

void Employee::Show(std::ostream& out) const
{
    out << "²ì'ÿ: " << name << ", ïğîôåñ³ÿ: " << profession;
}