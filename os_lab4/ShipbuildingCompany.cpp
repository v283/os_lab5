#include "ShipbuildingCompany.h"
#include <iostream>
using namespace std;

ShipbuildingCompany::ShipbuildingCompany()
    : ShipbuildingCompany("Суднобудівна компанія (без назви)", 0, 0.0, 0, false) {
}

ShipbuildingCompany::ShipbuildingCompany(const string& name, size_t employees, double revenue,
    size_t shipsPerYear, bool autoAdd)
    : Organization(name, employees, revenue, autoAdd), _shipsPerYear(0)
{
    SetShipsPerYear(shipsPerYear);
    cout << "[Суднобудівна] Створено: " << Name() << "\n";
}

ShipbuildingCompany::ShipbuildingCompany(const ShipbuildingCompany& other)
    : ShipbuildingCompany(other.Name(), other.Employees(), other.Revenue(),
        other._shipsPerYear, false) {
}

ShipbuildingCompany::~ShipbuildingCompany() {
    cout << "[Суднобудівна] Знищено: " << Name() << "\n";
}

size_t ShipbuildingCompany::ShipsPerYear() const { return _shipsPerYear; }
void   ShipbuildingCompany::SetShipsPerYear(size_t n) { _shipsPerYear = n; }

void ShipbuildingCompany::Show(ostream& os) const {
    os << "Суднобудівна компанія — ";
    PrintBase(os);
    os << ", кораблів/рік: " << _shipsPerYear;
}
