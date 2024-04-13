#include "Sorcerer.h"

using std::string;
using std::unique_ptr;

unique_ptr <Job> Sorcerer::clone() const {
    return unique_ptr<Job>(new Sorcerer(*this));
}

string Sorcerer::getName() const {
    return "Sorcerer";
}

int Sorcerer::combatPower(int force, int level) const {
    return force + level;
}

bool Sorcerer::registered = Job::registerJob("Sorcerer",
                                             []() -> unique_ptr <Job> { return unique_ptr<Sorcerer>(new Sorcerer()); });