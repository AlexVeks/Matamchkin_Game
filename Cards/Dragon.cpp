#include "Dragon.h"

using std::ostringstream;
using std::unique_ptr;
using std::string;

bool Dragon::registered = Monster::registerMonster("Dragon", []() -> unique_ptr <Monster> {
    return unique_ptr<Dragon>(new Dragon());
});

Dragon::Dragon() : Monster(17, 100, 9001) {}

string Dragon::getName() const {
    return "Dragon";
}

int Dragon::getCombatPower() const {
    // Assuming these are accessible from Monster; adjust if needed
    return Monster::combatPower;
}

int Dragon::getLoot() const {
    return Monster::loot;
}

int Dragon::getDamage() const {
    return Monster::damage;
}

string Dragon::getDescription() const {
    ostringstream ss;
    ss << getName() << " (power " << getCombatPower() << ", loot " << getLoot() << ", damage " << getDamage() << ")";
    return ss.str();
}
