#pragma once
#include "Organization.h"

class InsuranceCompany : public Organization {
protected:
    std::size_t _policies{};
public:
    InsuranceCompany();
    InsuranceCompany(const std::string& name, std::size_t employees, double revenue,
        std::size_t policies, bool autoAdd = false);
    InsuranceCompany(const InsuranceCompany& other);
    ~InsuranceCompany() override;

    std::size_t Policies() const;
    void SetPolicies(std::size_t p);

    void Show(std::ostream& os = std::cout) const override;
};
