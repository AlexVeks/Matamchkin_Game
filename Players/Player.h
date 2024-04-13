#pragma once

#include <string>
#include <memory>
#include "Job.h"
#include "Behavior.h"
#include "Job.h"

using std::string;
using std::unique_ptr;
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
class Player {
    string m_name;
    int m_level;
    int m_HP;
    int m_coins;
    int m_force;
    int m_maxHP;
    const static int DEFAULT_MAX_HP = 100;
    const static int DEFAULT_FORCE = 5;
    const static int DEFAULT_LEVEL = 1;
    const static int DEFAULT_COINS = 10;
    unique_ptr <Job> m_job;
    unique_ptr <Behavior> m_behavior;

public:
    friend std::ostream &operator<<(ostream &os, const Player &player);

    /*
     * Constructor to create a new player with a name, job, behavior, maximum HP, and force.
     *
     * @param name - The name of the player.
     * @param job - A unique pointer to the Job object the player will own.
     * @param behavior - A unique pointer to the Behavior object the player will own.
     * @param maxHP - The maximum HP of the player.
     * @param force - The force of the player.
     * @return A new instance of Player.
    */
    Player(const string &name,
           unique_ptr <Job> job,
           unique_ptr <Behavior> behavior,
           int maxHP = DEFAULT_MAX_HP,
           int force = DEFAULT_FORCE);

    /*
     * Copy constructor to create a new player from an existing one.
     *
     * @param other - The player to copy.
     * @return A new instance of Player.
    */
    Player(const Player &other) = delete;

    /*
     * Destructor to clean up resources allocated for a player.
    */
    ~Player() = default;

    /*
     * Assignment operator overload to assign the properties of another player.
     *
     * @param other - The player to copy.
     * @return A reference to the current player.
    */
    Player &operator=(const Player &other) = delete;

    /*
     * Increases the level of the player.
    */
    void levelUp();

    /*
     * Returns the current level of the player.
     *
     * @return The current level of the player.
    */
    int getLevel() const;

    /*
     * Increases the force of the player by the specified amount.
     *
     * @param amount - The amount to increase the force by.
    */
    void buff(int amount);

    /*
     * Heals the player by the specified amount.
     *
     * @param amount - The amount to heal the player by.
    */
    void heal(int amount);

    /*
     * Inflicts damage on the player by the specified amount.
     *
     * @param amount - The amount to damage the player by.
    */
    void damage(int amount);

    /*
     * Checks if the player is knocked out (HP <= 0).
     *
     * @return True if the player is knocked out, false otherwise.
    */
    bool isKnockedOut() const;

    /*
     * Adds coins to the player's inventory.
     *
     * @param amount - The amount of positive coins to add.
    */
    void addCoins(int amount);

    /*
     * Attempts to pay a specified amount using the player's coins.
     *
     * @param amount - The not negative amount of coins to pay.
     * @return True if the player has enough coins to pay, false otherwise.
    */
    bool pay(int amount);

    /**
     * Gets the description of the player
     *
     * @return - description of the player
    */
    string getDescription() const;

    /**
     * Gets the name of the player
     *
     * @return - name of the player
    */
    string getName() const;

    /**
     * Gets the of force the player has
     *
     * @return - force points of the player
    */
    int getForce() const;

    /**
     * Gets the combat power of the player
     *
     * @return - combat power of the player
    */
    int getCombatPower() const;

    /**
     * Gets the amount of health points the player currently has
     *
     * @return - health points of the player
    */
    int getHealthPoints() const;

    /**
     * Gets the amount of coins the player has
     *
     * @return - coins of the player
    */
    int getCoins() const;

    /**
     * Gets job of the player
    */
    const Job &getJob() const;

    /*
     * Gets behavior of the player
    */
    const Behavior &getBehavior() const;

    /*
    * Sets the player's behavior
    */
    void setBehavior(unique_ptr <Behavior> behavior);

    /*
    * Sets the player's job
    */
    void setJob(unique_ptr <Job> job);
};