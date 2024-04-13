#include "RiskTaking.h"

using std::string;
using std::unique_ptr;

unique_ptr <Behavior> RiskTaking::clone() const {
    return unique_ptr<Behavior>(new RiskTaking(*this));
}

string RiskTaking::getName() const {
    return "RiskTaking";
}

bool RiskTaking::registered = Behavior::registerBehavior("RiskTaking", []() -> unique_ptr <Behavior> {
    return unique_ptr<RiskTaking>(new RiskTaking());
});