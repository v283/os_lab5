#include "Organization.h"
using namespace std;

Organization* Organization::s_head = nullptr;
int           Organization::s_count = 0;

void Organization::PrintBase(ostream& os) const {
    os << "Назва: " << _name << ", працівників: " << _employees << ", дохід/рік: " << _revenue << " грн";
}

Organization::Organization()
    : Organization("Без назви", 0, 0.0, false) {
}

Organization::Organization(const string& name, size_t employees, double revenue, bool autoAdd)
    : _name(), _employees(0), _revenue(0.0), _next(nullptr), _inList(false)
{
    SetName(name);
    SetEmployees(employees);
    SetRevenue(revenue);

    if (autoAdd) AddToList();

    cout << "[Організація] Створено: " << _name << "\n";
}

Organization::Organization(const Organization& other)
    : Organization(other._name, other._employees, other._revenue, false) // копія — без авто-додавання
{
}

Organization::~Organization() {
    if (_inList) RemoveFromList(this);
    cout << "[Організація] Знищено: " << _name << "\n";
}

const string& Organization::Name() const { return _name; }
size_t        Organization::Employees() const { return _employees; }
double        Organization::Revenue() const  { return _revenue; }

void Organization::SetName(const string& n) { _name = n; }
void Organization::SetEmployees(size_t e) { _employees = e; }
void Organization::SetRevenue(double r) { _revenue = r; }

void Organization::AddToList() {
    if (_inList) return;
    _next = s_head;
    s_head = this;
    _inList = true;
    ++s_count;
}

void Organization::RemoveFromList(Organization* who) {
    Organization** pp = &s_head;
    while (*pp && *pp != who) {
        pp = &((*pp)->_next);
    }
    if (*pp == who) {
        *pp = who->_next;
        who->_next = nullptr;
        who->_inList = false;
        --s_count;
    }
}

void Organization::PrintList(ostream& os) {
    os << "=== Перелік організацій у списку (" << s_count << ") ===\n";
    Organization* cur = s_head;
    int idx = 1;
    while (cur) {
        os << idx++ << ") ";
        cur->Show(os);
        os << "\n";
        cur = cur->_next;
    }
}

int Organization::Count() { return s_count; }
