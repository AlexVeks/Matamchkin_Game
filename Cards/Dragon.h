#pragma once

#include "Monster.h"
#include <sstream>

using std::string;

class Dragon : public Monster {
public:
    Dragon();

    Dragon(const Dragon &) = delete;

    Dragon &operator=(const Dragon &) = delete;

    ~Dragon() = default;

    string getName() const override;

    int getCombatPower() const override;

    int getLoot() const override;

    int getDamage() const override;

    string getDescription() const override;

private:
    static bool registered;
};
