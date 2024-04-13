#include "Gang.h"
#include <sstream>

using std::string;
using std::unique_ptr;
using std::move;
using std::ostringstream;

bool Gang::registered = Monster::registerMonster("Gang",
                                                 []() -> unique_ptr <Monster> { return unique_ptr<Gang>(new Gang()); });

Gang::Gang() : Monster(0, 0, 0) {}

void Gang::addMonster(unique_ptr <Monster> monster) {
    if (monster) {
        combatPower += monster->getCombatPower();
        loot += monster->getLoot();
        damage += monster->getDamage();

        // Add the monster to the collection
        monsters.push_back(move(monster));
    }
}

string Gang::getName() const {
    return "Gang";
}

int Gang::getCombatPower() const {
    return combatPower;
}

int Gang::getLoot() const {
    return loot;
}

int Gang::getDamage() const {
    return damage;
}

string Gang::getDescription() const {
    ostringstream ss;
    ss << "Gang of " << monsters.size() << " members (power " << getCombatPower() << ", loot " << getLoot()
       << ", damage " << getDamage() << ")";
    return ss.str();
}