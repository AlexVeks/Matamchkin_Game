#pragma once

#include <vector>
#include <memory>
#include "Player.h"

using std::vector;
using std::shared_ptr;

class Leaderboard {
public:
    Leaderboard() = default;

    ~Leaderboard() = default;

    Leaderboard(const Leaderboard &) = delete;

    Leaderboard &operator=(const Leaderboard &) = delete;

    void printLeaderboard(const vector <shared_ptr<Player>> &players) const;

    static bool comparePlayers(const shared_ptr <Player> &a, const shared_ptr <Player> &b);
};