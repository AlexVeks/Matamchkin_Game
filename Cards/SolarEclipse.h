#pragma once

#include "Event.h"
#include "Player.h"
#include <string>

using std::string;

class SolarEclipse : public Event {
public:
    SolarEclipse();

    SolarEclipse(const SolarEclipse &) = delete;

    SolarEclipse &operator=(const SolarEclipse &) = delete;

    virtual ~SolarEclipse() override = default;

    string execute(Player &player) override;

    string getDescription() const override;

protected:
    string applyEffect(Player &player) override;

private:
    string name = "SolarEclipse";
    static bool registered;
};