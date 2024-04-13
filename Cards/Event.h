#pragma once

#include "Player.h"
#include "Card.h"
#include <memory>
#include <string>
#include <unordered_map>

using std::string;
using std::unique_ptr;
using std::unordered_map;

class Event : public Card {
public:
    Event() = default;

    Event(const Event &) = delete;

    Event &operator=(const Event &) = delete;

    virtual ~Event() = default;

    virtual string applyEffect(Player &player) = 0;

    static unique_ptr <Job> createEvent(const string &type);

    // Type for the factory function to create Job instances
    using FactoryFunction = unique_ptr<Event> (*)();

    static unordered_map <string, FactoryFunction> &getRegistry() {
        static unordered_map <string, FactoryFunction> registry;
        return registry;
    }

    static bool registerEvent(const string &type, FactoryFunction factoryFunction) {
        getRegistry()[type] = factoryFunction;
        return true;
    }
};