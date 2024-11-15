#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "item.hpp"

class player {
public:
    player(const std::string& name, const std::string& type);

    void displayStats() const;
    void equipItem(item* item);
    void takeDamage(int damage);
    void gainExperience(int xp);
    bool isAlive() const;

private:
    std::string name;
    std::string type;
    int health;
    int magic;
    int strength;
    int level;
    int experience;
    item* equippedItem;
};

#endif
