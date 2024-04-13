#include "Giant.h"

#include <sstream>

using std::ostringstream;
using std::unique_ptr;
using std::string;

bool Giant::registered = Monster::registerMonster("Giant", []() -> unique_ptr <Monster> {
    return unique_ptr<Giant>(new Giant());
});

Giant::Giant() : Monster(12, 5, 25) {}

string Giant::getName() const {
    return "Giant";
}

int Giant::getCombatPower() const {
    return Monster::combatPower;
}

int Giant::getLoot() const {
    return Monster::loot;
}

int Giant::getDamage() const {
    return Monster::damage;
}

string Giant::getDescription() const {
    ostringstream ss;
    ss << getName() << " (power " << getCombatPower() << ", loot " << getLoot() << ", damage " << getDamage() << ")";
    return ss.str();
}
