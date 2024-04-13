#pragma once

#include "Event.h"
#include "Player.h"
#include <memory>
#include <string>

using std::string;

class PotionsMerchant : public Event {
public:
    PotionsMerchant();
    PotionsMerchant(const PotionsMerchant&) = delete;
    PotionsMerchant& operator=(const PotionsMerchant&) = delete;
    virtual ~PotionsMerchant() override = default;

    string execute(Player &player) override;

    string getDescription() const override;

protected:
    string applyEffect(Player &player) override;

private:
    string name = "PotionsMerchant";
    static bool registered;
};