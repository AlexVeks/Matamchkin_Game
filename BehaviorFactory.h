#pragma once

#include <memory>
#include <string>
#include "Behavior.h"
#include "Responsible.h"
#include "RiskTaking.h"

using std::string;
using std::unique_ptr;

class BehaviorFactory {
public:
    BehaviorFactory() = delete;

    ~BehaviorFactory() = delete;

    BehaviorFactory(const BehaviorFactory &) = delete;

    BehaviorFactory &operator=(const BehaviorFactory &) = delete;


    static unique_ptr <Behavior> createBehavior(const string &type);
};