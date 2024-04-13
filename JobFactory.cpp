#include "JobFactory.h"
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <memory>
#include "Job.h"

using std::string;
using std::unique_ptr;
using std::unordered_map;
using std::runtime_error;

unique_ptr <Job> JobFactory::createJob(const string &type) {
    const unordered_map <string, Job::FactoryFunction> &registry = Job::getRegistry();

    if (registry.count(type) > 0) {
        return registry.at(type)();
    }
    throw runtime_error("Invalid Players File");
}
