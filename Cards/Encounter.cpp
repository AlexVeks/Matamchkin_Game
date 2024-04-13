#include "Encounter.h"
#include "utilities.h"
#include <sstream>

using std::string;

string Encounter::execute(Player &player) {
    int playerCombatPower = player.getCombatPower();

    if (playerCombatPower > monster->getCombatPower()) {
        player.addCoins(monster->getLoot());
        player.levelUp();
        return getEncounterWonMessage(player, monster->getLoot());
    } else {
        player.damage(monster->getDamage());
        return getEncounterLostMessage(player, monster->getDamage());
    }
}

string Encounter::getDescription() const {
    return monster->getDescription();
}
