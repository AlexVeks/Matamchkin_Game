#include "Warrior.h"

using std::string;
using std::unique_ptr;


unique_ptr <Job> Warrior::clone() const {
    return std::unique_ptr<Job>(new Warrior(*this));
}

string Warrior::getName() const {
    return "Warrior";
}

int Warrior::combatPower(int force, int level) const {
    return force * 2 + level;
}

bool Warrior::registered = Job::registerJob("Warrior",
                                            []() -> unique_ptr <Job> { return unique_ptr<Warrior>(new Warrior()); });