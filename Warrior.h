#pragma once

#include "Job.h"
#include <memory>
#include <string>

using std::string;
using std::unique_ptr;

class Warrior : public Job {
public:
    Warrior() = default;

    Warrior(const Warrior &) = default;

    Warrior &operator=(const Warrior &) = delete;

    virtual ~Warrior() = default;

    unique_ptr <Job> clone() const override;

    string getName() const override;

    int combatPower(int force, int level) const override;

private:
    static bool registered;
};
