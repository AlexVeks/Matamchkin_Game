#pragma once

#include <memory>
#include <string>
#include <unordered_map>

using std::string;
using std::unique_ptr;
using std::unordered_map;

class Job {
public:
    Job() = default;

    Job(const Job &) = default;

    Job &operator=(const Job &) = delete;


    virtual ~Job() = default;

    virtual unique_ptr <Job> clone() const = 0;

    virtual string getName() const = 0;

    virtual int combatPower(int force, int level) const = 0;

    // Factory-related methods and members
    static unique_ptr <Job> createJob(const string &type);

    // Type for the factory function to create Job instances
    using FactoryFunction = unique_ptr<Job> (*)();

    static unordered_map <string, FactoryFunction> &getRegistry() {
        static unordered_map <string, FactoryFunction> registry;
        return registry;
    }

    static bool registerJob(const string &type, FactoryFunction factoryFunction) {
        getRegistry()[type] = factoryFunction;
        return true;
    }
};