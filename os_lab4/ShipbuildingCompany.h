#pragma once
#include "Organization.h"

class ShipbuildingCompany : public Organization {
protected:
    std::size_t _shipsPerYear{};
public:
    ShipbuildingCompany();
    ShipbuildingCompany(const std::string& name, std::size_t employees, double revenue,
        std::size_t shipsPerYear, bool autoAdd = false);
    ShipbuildingCompany(const ShipbuildingCompany& other);
    ~ShipbuildingCompany() override;

    std::size_t ShipsPerYear() const;
    void SetShipsPerYear(std::size_t n);

    void Show(std::ostream& os = std::cout) const override;
};
