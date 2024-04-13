#include "Responsible.h"

using std::string;
using std::unique_ptr;

unique_ptr <Behavior> Responsible::clone() const {
    return unique_ptr<Behavior>(new Responsible(*this));
}

string Responsible::getName() const {
    return "Responsible";
}

bool Responsible::registered = Behavior::registerBehavior("Responsible", []() -> unique_ptr <Behavior> {
    return unique_ptr<Responsible>(new Responsible());
});