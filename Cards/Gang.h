#pragma once

#include "Monster.h"
#include <vector>
#include <memory>

using std::string;
using std::unique_ptr;
using std::vector;

class Gang : public Monster {
public:
    Gang();

    Gang(const Gang &) = delete;

    Gang &operator=(const Gang &) = delete;

    ~Gang() override = default;

    void addMonster(unique_ptr <Monster> monster);

    string getName() const override;

    int getCombatPower() const override;

    int getLoot() const override;

    int getDamage() const override;

    string getDescription() const;

private:
    vector <unique_ptr<Monster>> monsters;
    static bool registered;
};