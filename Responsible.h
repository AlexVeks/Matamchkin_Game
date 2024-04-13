#pragma once

#include "Behavior.h"

using std::string;
using std::unique_ptr;

class Responsible : public Behavior {
public:
    Responsible() = default;

    Responsible(const Responsible &) = default;

    Responsible &operator=(const Responsible &) = delete;

    ~Responsible() = default;

    unique_ptr <Behavior> clone() const override;

    string getName() const override;

private:
    static bool registered;
};