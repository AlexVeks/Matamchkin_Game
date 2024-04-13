#pragma once

#include "Behavior.h"

using std::string;
using std::unique_ptr;

class RiskTaking : public Behavior {
public:
    RiskTaking() = default;

    RiskTaking(const RiskTaking &) = default;

    RiskTaking &operator=(const RiskTaking &) = delete;

    ~RiskTaking() = default;

    unique_ptr <Behavior> clone() const override;

    string getName() const override;

private:
    static bool registered;
};