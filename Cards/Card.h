#pragma once

#include <string>
#include "Player.h"

using std::string;

class Card {
public:
    Card() = default;

    Card(const Card &) = delete;

    Card &operator=(const Card &) = delete;

    virtual ~Card() = default;


    virtual string execute(Player &player) = 0;

    virtual string getDescription() const = 0;
};