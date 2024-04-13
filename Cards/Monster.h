#pragma once

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

using std::string;
using std::unique_ptr;
using std::vector;
using std::unordered_map;

class Monster {
public:
    Monster() = default;

    Monster(const Monster &) = delete;

    Monster &operator=(const Monster &) = delete;

    virtual ~Monster() = default;

    virtual string getName() const = 0;

    virtual int getCombatPower() const = 0;

    virtual int getLoot() const = 0;

    virtual int getDamage() const = 0;

    virtual string getDescription() const = 0;

    static unique_ptr <Monster> createMonster(const string &type);

    using FactoryFunction = unique_ptr<Monster> (*)();

    static unordered_map <string, FactoryFunction> &getRegistry() {
        static unordered_map <string, FactoryFunction> registry;
        return registry;
    }

    static bool registerMonster(const string &type, FactoryFunction factoryFunction) {
        getRegistry()[type] = factoryFunction;
        return true;
    }

protected:
    Monster(int combatPower, int loot, int damage)
            : combatPower(combatPower), loot(loot), damage(damage) {
    }

    int combatPower;
    int loot;
    int damage;
};