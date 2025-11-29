#include "Factory.h"
#include <iostream>
using namespace std;

Factory::Factory()
    : Factory("Завод (без назви)", 0, 0.0, "Невідомо", 0, false) {
}

Factory::Factory(const string& name, size_t employees, double revenue,
    const string& industry, size_t workshops, bool autoAdd)
    : Organization(name, employees, revenue, autoAdd), _industry(), _workshops(0)
{
    SetIndustry(industry);
    SetWorkshops(workshops);
    cout << "[Завод] Створено: " << Name() << "\n";
}

Factory::Factory(const Factory& other)
    : Factory(other.Name(), other.Employees(), other.Revenue(),
        other._industry, other._workshops, false) {
}

Factory::~Factory() {
    cout << "[Завод] Знищено: " << Name() << "\n";
}

const string& Factory::Industry() const { return _industry; }
size_t        Factory::Workshops() const { return _workshops; }

void Factory::SetIndustry(const string& i) { _industry = i; }
void Factory::SetWorkshops(size_t w) { _workshops = w; }

void Factory::Show(ostream& os) const {
    os << "Завод — ";
    PrintBase(os);
    os << ", галузь: " << _industry << ", цехів: " << _workshops;
}
