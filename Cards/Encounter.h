#pragma once

#include "Card.h"
#include "Monster.h"
#include "Player.h"
#include <memory>
#include "utilities.h"

using std::unique_ptr;
using std::string;
using std::move;

class Encounter : public Card {
public:
    explicit Encounter(unique_ptr <Monster> monster) : monster(move(monster)) {}

    Encounter(const Encounter &) = delete;

    Encounter &operator=(const Encounter &) = delete;

    ~Encounter() override = default;

    string execute(Player &player) override;

    string getDescription() const override;

private:
    unique_ptr <Monster> monster;
};