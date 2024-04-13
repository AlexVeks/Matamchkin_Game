#pragma once

#include <memory>
#include <string>
#include "Job.h"
#include "Warrior.h"
#include "Sorcerer.h"

using std::string;
using std::unique_ptr;

class JobFactory {
public:
    JobFactory() = delete;

    ~JobFactory() = delete;

    JobFactory(const JobFactory &) = delete;

    JobFactory &operator=(const JobFactory &) = delete;

    static unique_ptr <Job> createJob(const string &type);
};
