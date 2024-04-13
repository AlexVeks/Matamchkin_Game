#include "PotionsMerchant.h"
#include <utilities.h>

using std::string;
using std::unique_ptr;

PotionsMerchant::PotionsMerchant() {}

string PotionsMerchant::execute(Player &player) {
    string effectMessage = applyEffect(player);
    return effectMessage;
}

string PotionsMerchant::getDescription() const {
    return name;
}

string PotionsMerchant::applyEffect(Player &player) {
    int potionsBought = 0;
    const int potionCost = 5;
    const int potionHPIncrease = 10;
    const int maxHealthPoints = 100;

    if (player.getHealthPoints() == maxHealthPoints) {
        return getPotionsPurchaseMessage(player, potionsBought);
    }

    if (player.getBehavior().getName() == "Responsible") {
        while (player.getCoins() >= potionCost && player.getHealthPoints() < maxHealthPoints) {
            player.pay(potionCost);
            player.heal(potionHPIncrease);
            potionsBought++;
        }
    } else if (player.getBehavior().getName() == "RiskTaking") {
        if (player.getHealthPoints() < 50 && player.getCoins() >= potionCost) {
            player.pay(potionCost);
            player.heal(potionHPIncrease);
            potionsBought++;
        }
    }

    // Return the message detailing the effects applied
    return getPotionsPurchaseMessage(player, potionsBought);
}

bool PotionsMerchant::registered = Event::registerEvent("PotionsMerchant", []() -> unique_ptr <Event> {
    return unique_ptr<PotionsMerchant>(new PotionsMerchant());
});