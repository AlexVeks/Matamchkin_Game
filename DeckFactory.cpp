#include "DeckFactory.h"
#include "Event.h"
#include "Monster.h"
#include "Gang.h"
#include "Encounter.h"
#include <fstream>
#include <sstream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <memory>
#include <vector>

using std::string;
using std::unique_ptr;
using std::vector;
using std::ifstream;
using std::runtime_error;
using std::unordered_map;
using std::move;

vector <unique_ptr<Card>> DeckFactory::createDeck(const string &filePath) {
    vector <unique_ptr<Card>> deck;
    ifstream file(filePath);
    if (!file.is_open()) {
        throw runtime_error("Invalid Cards File");
    }

    string word;
    vector <string> words;
    // Read words directly from the file
    while (file >> word) {
        words.push_back(word);
    }
    file.close(); // Close the file as we have read all its contents

    bool hasEncounter = false; // Flag to check if the deck contains at least one encounter card

    // Process the words to create the deck
    for (size_t i = 0; i < words.size();) {
        if (Event::getRegistry().find(words[i]) != Event::getRegistry().end()) {
            deck.push_back(createEvent(words[i]));
            ++i;
        } else if (words[i] != "Gang" && Monster::getRegistry().find(words[i]) != Monster::getRegistry().end()) {
            deck.push_back(unique_ptr<Card>(new Encounter(createMonster(words[i]))));
            hasEncounter = true; // Encounter card added
            ++i;
        } else if (words[i] == "Gang") {
            // Ensure createGang correctly updates currentIndex to skip the gang members
            unique_ptr <Card> gangEncounter(new Encounter(createGang(words, i)));
            deck.push_back(move(gangEncounter));
            hasEncounter = true; // Encounter card added
        } else {
            throw runtime_error("Invalid Cards File");
        }
    }

    if (deck.size() < 2 || !hasEncounter) {
        // A deck must have at least 2 cards and at least one encounter card otherwise will be inifnite loop in Mtmchkin.cpp
        throw runtime_error("Invalid Cards File");
    }

    return deck;
}

unique_ptr <Card> DeckFactory::createEvent(const string &eventType) {
    const unordered_map <string, Event::FactoryFunction> &registry = Event::getRegistry();
    // Check if the event type is found in the registry
    if (registry.find(eventType) != registry.end()) {
        // Invoke the factory function to create the event
        return registry.at(eventType)();
    }
    // If the event type is not found in the registry
    throw runtime_error("Invalid Cards File");
}

unique_ptr <Monster> DeckFactory::createMonster(const string &monsterType) {
    const unordered_map <string, Monster::FactoryFunction> &registry = Monster::getRegistry();
    // Check if the monster type is found in the registry
    if (registry.find(monsterType) != registry.end()) {
        // Invoke the factory function to create the monster
        return registry.at(monsterType)();
    }
    // If the monster type is not found in the registry
    throw runtime_error("Invalid Cards File");
}

unique_ptr <Monster> DeckFactory::createGang(const vector <string> &details, size_t &currentIndex) {
    ++currentIndex; // Assuming 'Gang' keyword is already consumed

    if (currentIndex >= details.size()) {
        // If the gang size is missing
        throw runtime_error("Invalid Cards File");
    }

    int gangSize = stoi(details[currentIndex++]);
    if (gangSize < 2) {
        // Gangs must have at least 2 monsters
        throw runtime_error("Invalid Cards File");
    }

    unique_ptr <Gang> gang(new Gang());
    for (int i = 0; i < gangSize; ++i) {
        if (currentIndex >= details.size()) {
            // If the gang size is larger than the number of monsters in the deck
            throw runtime_error("Invalid Cards File");
        }

        const string &type = details[currentIndex];
        if (type == "Gang") {
            // Recursively create a gang
            gang->addMonster(createGang(details, currentIndex));
        } else {
            gang->addMonster(createMonster(type));
            currentIndex++; // Advance currentIndex after processing a non-gang monster
        }
    }

    // Return the gang as a Monster
    return unique_ptr<Monster>(move(gang));
}