#pragma once

#include "Job.h"

using std::string;
using std::unique_ptr;

class Sorcerer : public Job {
public:
    Sorcerer() = default;

    Sorcerer(const Sorcerer &) = default;

    Sorcerer &operator=(const Sorcerer &) = delete;

    ~Sorcerer() = default;

    unique_ptr <Job> clone() const override;

    string getName() const override;

    int combatPower(int force, int level) const override;

private:
    static bool registered;
};
