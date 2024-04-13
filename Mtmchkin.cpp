#include "Mtmchkin.h"
#include "DeckFactory.h"
#include "PlayerFactory.h"
#include "Leaderboard.h"
#include "utilities.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

using std::string;
using std::shared_ptr;
using std::unique_ptr;
using std::vector;
using std::ifstream;
using std::ostringstream;
using std::sort;
using std::move;

/**
 * Constructor of Mtmchkin class
 *
 * @param deckPath - path to the deck file
 * @param playersPath - path to the players file
 *
 * @return - Mtmchkin object with the given deck and players
 *
*/
Mtmchkin::Mtmchkin(const string &deckPath, const string &playersPath)
        : deck(DeckFactory().createDeck(deckPath)),
          players(PlayerFactory().createPlayers(playersPath)),
          m_turnIndex(1) {
}

/**
 * Playes a single turn for a player
 *
 * @param player - the player to play the turn for
 *
 * @return - void
*/
void Mtmchkin::playTurn(shared_ptr <Player> &player) {
    if (!deck.empty()) {
        Card *card = deck.front().get(); // Get the front card of the deck
        printTurnDetails(m_turnIndex++, *player, *card); // Increment the turn index here

        string outcome = card->execute(*player);

        printTurnOutcome(outcome);
        deck.push_back(move(deck.front())); // Move the front card to the back
        deck.erase(deck.begin()); // Erase the now-empty front element
    }
}

/**
 * Plays a single round of the game
 *
 * @return - void
*/
void Mtmchkin::playRound() {
    printRoundStart();

    for (shared_ptr <Player> &player: players) {
        if (!player->isKnockedOut()) {
            playTurn(player);
        }
    }

    printRoundEnd();
    printLeaderBoardMessage();

    Leaderboard leaderboard;
    leaderboard.printLeaderboard(players);

    printBarrier();

    if (!isGameOver()) {
        playRound();
    }
}

/**
 * Checks if the game is over
 *
 * @return - true if the game is over, false otherwise
*/
bool Mtmchkin::isGameOver() const {
    bool hasMaxLevelPlayer = false;
    bool allKnockedOut = true;

    // Check for any player with level >= 10
    for (size_t i = 0; i < players.size(); i++) {
        if (players[i]->getLevel() >= 10) {
            hasMaxLevelPlayer = true;
            break; // No need to continue if a player with level >= 10 is found
        }
    }

    // Check if all players are knocked out
    for (size_t i = 0; i < players.size(); i++) {
        if (!players[i]->isKnockedOut()) {
            allKnockedOut = false;
            break; // No need to continue if a player who is not knocked out is found
        }
    }

    return hasMaxLevelPlayer || allKnockedOut;
}

/**
 * Plays the entire game
 *
 * @return - void
*/
void Mtmchkin::play() {
    printStartMessage();

    int playerIndex = 1;
    // Use traditional for loop with index to access players
    for (size_t i = 0; i < players.size(); i++) {
        printStartPlayerEntry(playerIndex++, *players[i]);
    }

    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();

    vector <shared_ptr<Player>> sortedPlayers(players);
    sort(sortedPlayers.begin(), sortedPlayers.end(), Leaderboard::comparePlayers);

    shared_ptr <Player> winner = nullptr;
    for (size_t i = 0; i < sortedPlayers.size(); i++) {
        if (sortedPlayers[i]->getLevel() >= 10) {
            winner = sortedPlayers[i];
            break; // Found the winner, no need to continue
        }
    }

    if (winner != nullptr) {
        printWinner(*winner);
    } else {
        // No winners, either everyone is knocked out or another condition
        printNoWinners();
    }
}