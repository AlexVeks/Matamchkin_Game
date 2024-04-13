#pragma once

#include <memory>
#include <string>
#include <unordered_map>

using std::string;
using std::unique_ptr;
using std::unordered_map;

class Behavior {
public:
    Behavior() = default;

    Behavior(const Behavior &) = default;

    Behavior &operator=(const Behavior &) = delete;


    virtual ~Behavior() = default;

    virtual unique_ptr <Behavior> clone() const = 0;

    virtual string getName() const = 0;

    using FactoryFunction = unique_ptr<Behavior> (*)();

    static unique_ptr <Behavior> createBehavior(const string &type);

    static unordered_map <string, FactoryFunction> &getRegistry() {
        static unordered_map <string, FactoryFunction> registry;
        return registry;
    }

    static bool registerBehavior(const string &type, FactoryFunction factoryFunction) {
        getRegistry()[type] = factoryFunction;
        return true;
    }
};