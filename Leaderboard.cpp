#include "Leaderboard.h"
#include <algorithm>
#include "utilities.h"

using std::string;
using std::vector;
using std::shared_ptr;
using std::sort;

void Leaderboard::printLeaderboard(const vector <shared_ptr<Player>> &players) const {
    // Create a copy of the players vector for sorting
    vector <shared_ptr<Player>> sortedPlayers(players);

    // Sort the copied vector
    sort(sortedPlayers.begin(), sortedPlayers.end(), Leaderboard::comparePlayers);

    // Iterate over sortedPlayers and print their ranking
    int rank = 1;
    for (const shared_ptr <Player> &player: sortedPlayers) {
        printLeaderBoardEntry(rank++, *player);
    }
}

bool Leaderboard::comparePlayers(const shared_ptr <Player> &a, const shared_ptr <Player> &b) {
    if (a->getLevel() != b->getLevel()) {
        return a->getLevel() > b->getLevel();
    } else if (a->getCoins() != b->getCoins()) {
        return a->getCoins() > b->getCoins();
    } else {
        return a->getName() < b->getName();
    }
}
