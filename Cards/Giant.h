#pragma once

#include "Monster.h"
#include <sstream>

using std::string;

class Giant : public Monster {
public:
    Giant();

    Giant(const Giant &) = delete;

    Giant &operator=(const Giant &) = delete;

    ~Giant() override = default;

    string getName() const override;

    int getCombatPower() const override;

    int getLoot() const override;

    int getDamage() const override;

    string getDescription() const override;

private:
    static bool registered;
};
