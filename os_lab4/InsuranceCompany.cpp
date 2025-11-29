#include "InsuranceCompany.h"
#include <iostream>
using namespace std;

InsuranceCompany::InsuranceCompany()
    : InsuranceCompany("Страхова компанія (без назви)", 0, 0.0, 0, false) {
}

InsuranceCompany::InsuranceCompany(const string& name, size_t employees, double revenue,
    size_t policies, bool autoAdd)
    : Organization(name, employees, revenue, autoAdd), _policies(0)
{
    SetPolicies(policies);
    cout << "[СК] Створено: " << Name() << "\n";
}

InsuranceCompany::InsuranceCompany(const InsuranceCompany& other)
    : InsuranceCompany(other.Name(), other.Employees(), other.Revenue(),
        other._policies, false) {
}

InsuranceCompany::~InsuranceCompany() {
    cout << "[СК] Знищено: " << Name() << "\n";
}

size_t InsuranceCompany::Policies() const { return _policies; }
void   InsuranceCompany::SetPolicies(size_t p) { _policies = p; }

void InsuranceCompany::Show(ostream& os) const {
    os << "Страхова компанія — ";
    PrintBase(os);
    os << ", активних полісів: " << _policies;
}
