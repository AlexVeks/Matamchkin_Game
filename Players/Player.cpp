#include <string>
#include "utilities.h"
#include <sstream>
#include "Player.h"
#include "Job.h"

using std::string;
using std::unique_ptr;
using std::ostream;
using std::move;
using std::stringstream;
using std::ostream;

/*
 * C'tor to create a new player with a name, maximum HP, and force.
 *
 * @param m_name - The name of the player.
 * @param m_level - The level of the player.
 * @param m_HP - The current HP of the player.
 * @param m_coins - The coins the player has.
 * @param m_force - The force of the player.
 * @param m_maxHP - The maximum HP of the player.
 * @param DEFAULT_MAX_HP - The default maximum HP of the player.
 * @param DEFAULT_FORCE - The default force of the player.
 * @param DEFAULT_LEVEL - The default level of the player.
 * @param DEFAULT_COINS - The default coins of the player.
 * @param m_job - The job of the player.
 * @param m_behavior - The behavior of the player.
 * @return A new instance of Player.
*/
Player::Player(const string &name,
               unique_ptr <Job> job,
               unique_ptr <Behavior> behavior,
               int maxHP,
               int force) {
    this->m_name = name;

    // Ensure maxHP is positive; otherwise, use DEFAULT_MAX_HP
    this->m_maxHP = maxHP > 0 ? maxHP : DEFAULT_MAX_HP;
    this->m_HP = this->m_maxHP;

    // Ensure force is non-negative; otherwise, use DEFAULT_FORCE
    this->m_force = force >= 0 ? force : DEFAULT_FORCE;

    this->m_level = DEFAULT_LEVEL;
    this->m_coins = DEFAULT_COINS;

    // Transfer ownership of job and behavior to this player object
    this->m_job = move(job);
    this->m_behavior = move(behavior);
}


/*
 * Increases the level of the player.
*/
void Player::levelUp() {
    if (m_level < 10) {
        m_level++;
    }
}

/*
 * Increases the force of the player by the specified amount.
 *
 * @param amount - The amount to increase or decrease the force.
*/
void Player::buff(int amount) {
    m_force += amount;
}

/*
 * Heals the player by the specified amount.
 *
 * @param amount - The amount to heal the player by.
*/
void Player::heal(int amount) {
    if (amount > 0) {
        if (m_HP + amount > m_maxHP) {
            m_HP = m_maxHP;
        } else {
            m_HP += amount;
        }
    }
}

/*
 * Inflicts damage on the player by the specified amount.
 *
 * @param amount - The amount to damage the player by.
*/
void Player::damage(int amount) {
    if (amount > 0) {
        if (m_HP - amount < 0) {
            m_HP = 0;
        } else {
            m_HP -= amount;
        }
    }
}

/*
 * Checks if the player is knocked out (HP <= 0).
 *
 * @return True if the player is knocked out, false otherwise.
*/
bool Player::isKnockedOut() const {
    return m_HP <= 0;
}

/*
 * Adds coins to the player's inventory.
 *
 * @param amount - The amount of positive coins to add.
*/
void Player::addCoins(int amount) {
    if (amount > 0) {
        m_coins += amount;
    }
}

/*
 * Attempts to pay a specified amount using the player's coins.
 *
 * @param amount - The not negative amount of coins to pay.
 * @return True if the player has enough coins to pay, false otherwise.
*/
bool Player::pay(int amount) {
    if (amount >= 0 && (m_coins - amount >= 0)) {
        m_coins -= amount;
        return true;
    }
    return false;
}

/*
 * Gets the name of the player
 *
 * @return - name of the player

*/
string Player::getName() const {
    return m_name;
}

/*
 * Returns the current level of the player.
*/
int Player::getLevel() const {
    return m_level;
}

/*
    * Gets the current force of the player
    *
    * @return - force of the player
*/
int Player::getForce() const {
    return m_force;
}

/*
    * Gets the current combat power of the player
    *
    * @return - combat power of the player
*/
int Player::getCombatPower() const {
    return m_job->combatPower(m_force, m_level);
}


/*
    * Gets the current HP of the player
    *
    * @return - HP of the player
*/
int Player::getHealthPoints() const {
    return m_HP;
}

/*
 * Gets the amount of coins the player has
 *
 * @return - coins of the player
*/
int Player::getCoins() const {
    return m_coins;
}

/*
* Gets the job of the player
*/
const Job &Player::getJob() const {
    return *m_job;
}

/*
* Gets behavior of the player
*/
const Behavior &Player::getBehavior() const {
    return *m_behavior;
}

/*
 * Gets the description of the player
 *
 * @return - description of the player
*/
string Player::getDescription() const {
    stringstream ss;
    ss << m_name << ", " << m_job->getName() << " with " << m_behavior->getName()
       << " behavior (level " << m_level << ", force " << m_force << ")";
    return ss.str();
}

/*
 * Overloads the << operator to output the player's description.
 *
 * @param os - The output stream to write to.
 * @param player - The player to output.
 * @return The output stream.
*/
ostream &operator<<(ostream &os, const Player &player) {
    os << player.getDescription();
    return os;
}

/*
 * Sets the player's behavior
*/
void Player::setBehavior(unique_ptr <Behavior> behavior) {
    m_behavior = move(behavior);
}

/*
* Sets the player's job
*/
void Player::setJob(unique_ptr <Job> job) {
    m_job = move(job);
}