#pragma once

#include "Player.h"
#include <memory>
#include <vector>
#include <string>

using std::string;
using std::shared_ptr;
using std::vector;

class PlayerFactory {
public:
    PlayerFactory() = default;

    ~PlayerFactory() = default;

    PlayerFactory(const PlayerFactory &) = delete;

    PlayerFactory &operator=(const PlayerFactory &) = delete;
    
    static shared_ptr <Player>
    createPlayer(const string &name, const string &jobType, const string &behaviorType);

    static vector <shared_ptr<Player>> createPlayers(const string &filePath);

private:
    static bool isValidName(const string &name);
};
