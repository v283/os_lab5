#pragma once
#include "Organization.h"

class Factory : public Organization {
protected:
    std::string _industry;
    std::size_t _workshops{};
public:
    Factory();
    Factory(const std::string& name, std::size_t employees, double revenue,
        const std::string& industry, std::size_t workshops, bool autoAdd = false);
    Factory(const Factory& other);
    ~Factory() override;

    const std::string& Industry() const;
    std::size_t        Workshops() const;

    void SetIndustry(const std::string& i);
    void SetWorkshops(std::size_t w);

    void Show(std::ostream& os = std::cout) const override;
};
