#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include <stdexcept>
#include <memory>
#include <string>
#include "Player.h"
#include "PlayerFactory.h"
#include "JobFactory.h"
#include "BehaviorFactory.h"

using std::string;
using std::shared_ptr;
using std::vector;
using std::ifstream;
using std::getline;
using std::istringstream;
using std::move;
using std::make_shared;
using std::unique_ptr;
using std::runtime_error;

vector <shared_ptr<Player>> PlayerFactory::createPlayers(const string &filePath) {
    ifstream playersFile(filePath);
    if (!playersFile.is_open()) {
        throw runtime_error("Invalid Players File");
    }

    vector <shared_ptr<Player>> players;
    string line;
    while (getline(playersFile, line)) {
        istringstream iss(line);
        vector <string> tokens;
        string token;

        // Manually split the line into tokens
        while (iss >> token) {
            tokens.push_back(token);
        }

        if (tokens.size() != 3) {
            throw runtime_error("Invalid Players File");
        }

        const string &name = tokens[0];
        if (!isValidName(name)) { // Assume isValidName is a function you've defined elsewhere
            throw runtime_error("Invalid Players File");
        }

        const string &jobType = tokens[1];
        const string &behaviorType = tokens[2];

        unique_ptr <Job> job = JobFactory::createJob(jobType);
        unique_ptr <Behavior> behavior = BehaviorFactory::createBehavior(behaviorType);

        shared_ptr <Player> player = make_shared<Player>(name, move(job), move(behavior));
        players.push_back(player);
    }

    if (players.size() < 2 || players.size() > 6) {
        throw runtime_error("Invalid Players File");
    }

    return players;
}

bool PlayerFactory::isValidName(const string &name) {
    // A valid name is a string of length 3-15 containing only letters
    if (name.empty() || name.length() > 15 || name.length() < 3) {
        return false;
    }

    for (char c: name) {
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
            return false;
        }
    }

    return true;
}