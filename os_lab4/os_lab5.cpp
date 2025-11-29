#include <iostream>
#include <windows.h>

#include "Organization.h"
#include "InsuranceCompany.h"
#include "ShipbuildingCompany.h"
#include "Factory.h"

#include "Employee.h"
#include "EmployeeCollection.h"

#include <array>
#include <list>
#include <set>
#include <map>
#include <stack>

int main()
{
    using std::cout;
    using std::endl;

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "\x1B[2J\x1B[H";
    cout << "Лабораторна робота 5 — Варіант 5\n\n";

    //  1. Успадкування ( з ЛР4) 

    InsuranceCompany sk1("СК «Avocado»", 120, 5'500'000.0, 25'000, true);
    Factory z1("Завод «Прогрес»", 340, 12'300'000.0, "Машинобудування", 8, true);

    ShipbuildingCompany sb1;
    sb1.SetName("Суднобудівний комплекс «Океан»");
    sb1.SetEmployees(900);
    sb1.SetRevenue(98'000'000.0);
    sb1.SetShipsPerYear(12);
    sb1.AddToList();

    cout << "=== Поліморфія (успадкування з ЛР4) ===\n";
    Organization::PrintList(cout);
    cout << "\nУсього у списку: " << Organization::Count() << " об'єкт(и).\n\n";


    //  2. vector<Employee> 

    EmployeeCollection employees;

    employees.Add(Employee("Іван", "Інженер"));
    employees.Add(Employee("Анна", "Бухгалтер"));
    employees.Add(Employee("Марія", "Інженер"));
    employees.Add(Employee("Олег", "Охоронець"));
    employees.Add(Employee("Світлана", "Менеджер"));

    cout << "=== Всі працівники (ітератор vector<Employee>) ===\n";
    for (EmployeeCollection::iterator it = employees.begin();
        it != employees.end(); ++it)
    {
        it->Show(cout);
        cout << endl;
    }

    //  3. Пошук 

    std::string target = "Інженер";
    auto found = employees.FindByProfession(target);

    cout << "\n=== Пошук: професія \"" << target << "\" ===\n";

    if (found.empty())
    {
        cout << "Нічого не знайдено.\n";
    }
    else
    {
        cout << "Знайдено службовців:\n";
        for (const Employee* e : found)
        {
            cout << " - " << e->Name() << endl;
        }
    }


    //  4. array 

    std::array<int, 5> departments = { 101, 102, 103, 104, 105 };

    cout << "\n=== array<int,5> (номери відділів) ===\n";
    for (int d : departments)
        cout << d << " ";
    cout << "\n";


    //  5. list 

    std::list<std::string> queue;
    queue.push_back("Іван");
    queue.push_back("Марія");
    queue.push_front("Анна");

    cout << "\n=== list<string> (черга працівників) ===\n";
    for (const auto& name : queue)
        cout << name << " ";
    cout << "\n";


    //  6. set 

    std::set<std::string> uniqueProfessions;
    for (const auto& e : employees)
        uniqueProfessions.insert(e.Profession());

    cout << "\n=== set<string> (унікальні професії) ===\n";
    for (const auto& p : uniqueProfessions)
        cout << p << " ";
    cout << "\n";


    //  7. map 

    std::map<std::string, int> professionCount;

    for (const auto& e : employees)
        professionCount[e.Profession()]++;

    cout << "\n=== map<string,int> (кількість працівників за професіями) ===\n";
    for (const auto& kv : professionCount)
        cout << kv.first << ": " << kv.second << endl;


    //  8. stack 

    std::stack<Employee> history;

    history.push(Employee("Гість 1", "Технік"));
    history.push(Employee("Гість 2", "Лаборант"));
    history.push(Employee("Гість 3", "Інженер"));

    cout << "\n=== stack<Employee> (історія додавання) ===\n";
    while (!history.empty())
    {
        history.top().Show(cout);
        cout << endl;
        history.pop();
    }

    return 0;
}
