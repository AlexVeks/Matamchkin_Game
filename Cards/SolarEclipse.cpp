#include "SolarEclipse.h"
#include <utilities.h>

using std::string;
using std::unique_ptr;

SolarEclipse::SolarEclipse() {}

string SolarEclipse::execute(Player &player) {
    return applyEffect(player);
}

string SolarEclipse::applyEffect(Player &player) {
    if (player.getJob().getName() == "Sorcerer") {
        player.buff(1);
        return getSolarEclipseMessage(player, 1);
    } else if (player.getForce() > 0) {
        player.buff(-1);
        return getSolarEclipseMessage(player, -1);
    } else {
        return getSolarEclipseMessage(player, 0);
    }
}

string SolarEclipse::getDescription() const {
    return name;
}

bool SolarEclipse::registered = Event::registerEvent("SolarEclipse", []() -> unique_ptr <Event> {
    return unique_ptr<SolarEclipse>(new SolarEclipse());
});
