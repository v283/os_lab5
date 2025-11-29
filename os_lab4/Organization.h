#pragma once
#pragma once
#include <string>
#include <iostream>
#include <cstddef>

class Organization {
protected:
    std::string _name;
    std::size_t _employees{};
    double _revenue{};
    Organization* _next{ nullptr };
    bool _inList{ false };

    // Допоміжний друк базових полів для нащадків
    void PrintBase(std::ostream& os) const;

public:
    // Делегування конструкторів + get/set усередині
    Organization();
    Organization(const std::string& name, std::size_t employees, double revenue, bool autoAdd = false);
  
    Organization(const Organization& other);

    virtual ~Organization();

    // get/set 
    const std::string& Name() const;
    std::size_t        Employees() const;
    double             Revenue() const;

    void SetName(const std::string& n);
    void SetEmployees(std::size_t e);
    void SetRevenue(double r);

    // Абстрактний інтерфейс
    virtual void Show(std::ostream& os = std::cout) const = 0;

    // Керування зв’язаним списком
    void AddToList();                      // явне додавання
    static void PrintList(std::ostream& os = std::cout); // перегляд списку
    static int  Count();                   // скільки у списку

private:
    static Organization* s_head; // початок списку (static)
    static int           s_count;

    static void RemoveFromList(Organization* who); // викликається у деструкторі
};
