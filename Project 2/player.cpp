#include "player.hpp"
#include <iostream>

player::player(const std::string& name, const std::string& type)
    : name(name), type(type), health(100), level(1), experience(0), equippedItem(nullptr) {
    if (type == "Wizard") {
        magic = 15;
        strength = 5;
    } else if (type == "Knight") {
        magic = 5;
        strength = 15;
    } else {
        magic = 10;
        strength = 10;
    }
}

void player::displayStats() const {
    std::cout << "Player Stats:\n";
    std::cout << "Name: " << name << "\nType: " << type << "\nHealth: " << health << "\n";
    std::cout << "Magic: " << magic << "\nStrength: " << strength << "\nLevel: " << level << "\n";
    std::cout << "Experience: " << experience << "\n";
}

void player::equipItem(item* item) {
    equippedItem = item;
    std::cout << "Equipped: " << equippedItem->getName() << "\n";
}

void player::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
        std::cout << "Your health dropped to zero. You died. Game over!\n";
        exit(0);
    }
}

void player::gainExperience(int xp) {
    experience += xp;
    if (experience >= level * 10) {
        experience = 0;
        level++;
        std::cout << "Level up! You are now level " << level << "!\n";
    }
}

bool player::isAlive() const {
    return health > 0;
}
