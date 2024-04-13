#include "BehaviorFactory.h"
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <memory>

using std::runtime_error;
using std::string;
using std::unique_ptr;
using std::unordered_map;

unique_ptr <Behavior> BehaviorFactory::createBehavior(const string &type) {
    const unordered_map <string, Behavior::FactoryFunction> &registry = Behavior::getRegistry();

    // Check if the type is found in the registry
    if (registry.find(type) != registry.end()) {
        // Directly call the factory function to create the Behavior instance
        return registry.at(type)();
    }
    // If the type is not found in the registry, throw an exception
    throw runtime_error("Invalid Cards File");
}