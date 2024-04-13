#pragma once

#include "Card.h"
#include "Monster.h"
#include <memory>
#include <vector>
#include <string>

using std::vector;
using std::unique_ptr;
using std::string;

class DeckFactory {
public:
    DeckFactory() = default;

    ~DeckFactory() = default;

    DeckFactory(const DeckFactory &) = delete;

    DeckFactory &operator=(const DeckFactory &) = delete;


    vector <unique_ptr<Card>> createDeck(const string &filePath);

private:
    unique_ptr <Card> createEvent(const string &eventType);

    unique_ptr <Monster> createMonster(const string &monsterType);

    unique_ptr <Monster> createGang(const vector <string> &details, size_t &currentIndex);
};
