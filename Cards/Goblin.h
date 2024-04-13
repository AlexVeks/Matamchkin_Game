#pragma once

#include "Monster.h"

using std::string;

class Goblin : public Monster {
public:
    Goblin();

    Goblin(const Goblin &) = delete;

    Goblin &operator=(const Goblin &) = delete;

    ~Goblin() override = default;

    string getName() const override;

    int getCombatPower() const override;

    int getLoot() const override;

    int getDamage() const override;

    string getDescription() const override;

private:
    static bool registered;
};