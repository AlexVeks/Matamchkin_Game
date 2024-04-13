#include "Goblin.h"
#include <sstream>

using std::ostringstream;
using std::unique_ptr;
using std::string;

bool Goblin::registered = Monster::registerMonster("Goblin", []() -> unique_ptr <Monster> {
    return unique_ptr<Goblin>(new Goblin());
});

Goblin::Goblin() : Monster(5, 2, 10) {
}

string Goblin::getName() const {
    return "Goblin";
}

int Goblin::getCombatPower() const {
    return Monster::combatPower;
}

int Goblin::getLoot() const {
    return Monster::loot;
}

int Goblin::getDamage() const {
    return Monster::damage;
}

string Goblin::getDescription() const {
    ostringstream ss;
    ss << getName() << " (power " << getCombatPower() << ", loot " << getLoot() << ", damage " << getDamage() << ")";
    return ss.str();
}
