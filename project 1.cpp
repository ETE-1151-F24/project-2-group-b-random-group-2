/* Author : Hermann Kenko Tanfoudie 
 * ID#   : 017639193
*PROJECT 1 _ ETE-1151-02 C++
*Description: This program is a code for a game set up. It asks the user(player) to enter the player name, and then the magic-type...
*Date: 09/30/2024*/

#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <cstring>  // For strcmp

const int MAX_ITEMS = 10;  // Max items the player can carry

struct Item {
    const char* name;
    const char* description;
    int trait;    // Bonus to magic or strength
    int rarity;   // Rarity from 1 (common) to 5 (legendary)
};

// Function to display the player's inventory
void showInventory(Item* inventory[], int inventorySize) {
    std::cout << "\nInventory:\n";
    bool empty = true;
    for (int i = 0; i < inventorySize; ++i) {
        if (inventory[i] != nullptr) {
            std::cout << "- " << inventory[i]->name << " : " << inventory[i]->description
                      << " (Trait: " << inventory[i]->trait 
                      << ", Rarity: " << inventory[i]->rarity << "/5)\n";
            empty = false;
        }
    }
    if (empty) {
        std::cout << "Your inventory is empty.\n";
    }
}

// Function to equip an item by name
void equipItem(const char* itemName, Item* inventory[], int inventorySize, Item*& equippedItem) {
    for (int i = 0; i < inventorySize; ++i) {
        if (inventory[i] != nullptr && strcmp(inventory[i]->name, itemName) == 0) {
            equippedItem = inventory[i];
            std::cout << "You have equipped: " << equippedItem->name << "\n";
            return;
        }
    }
    std::cout << "Item not found.\n";
}

// Combat function, with damage modified by the equipped item
void combat(int& health, Item* equippedItem) {
    std::cout << "\nYou encounter a monster!\n";
    int monsterDamage = rand() % 20 + 5;  // Random damage between 5 and 25
    std::cout << "The monster deals " << monsterDamage << " damage!\n";
    
    if (equippedItem) {
        std::cout << "You use " << equippedItem->name << " to defend yourself.\n";
        monsterDamage -= equippedItem->trait;  // Reduce damage by item's trait
        if (monsterDamage < 0) monsterDamage = 0;  // Prevent negative damage
    }
    
    health -= monsterDamage;  // Reduce player's health
    std::cout << "Your health is now " << health << ".\n";

    if (health <= 0) {
        std::cout << "You died. Game over!\n";
        exit(0);  // End game if player dies
    }
}

// Function to check quest completion
void checkQuest(Item* inventory[], int inventorySize) {
    bool questCompleted = false;
    for (int i = 0; i < inventorySize; ++i) {
        if (inventory[i] != nullptr && strcmp(inventory[i]->name, "Legendary Sword") == 0) {
            questCompleted = true;
            break;
        }
    }

    if (questCompleted) {
        std::cout << "Congratulations! You have found the Legendary Sword and completed your quest!\n";
        exit(0);  // End game on quest completion
    }
}

// Main function to manage the game
int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed random number generator

    char playerName[50];  // Player name
    int magic = 0, strength = 0, health = 100;  // Player stats
    Item* equippedItem = nullptr;  // The item the player has equipped

    // List of 10 items
    Item wand = {"Wand", "A powerful magic wand", 5, 2};
    Item sword = {"Legendary Sword", "Legendary sword of the ancients", 10, 5};
    Item bow = {"Bow", "A sturdy wooden bow", 4, 3};
    Item shield = {"Shield", "A shield for defense", 2, 1};
    Item potion = {"Healing Potion", "A potion to restore health", 0, 2};
    Item axe = {"Axe", "A heavy battle axe", 8, 4};
    Item dagger = {"Dagger", "A sharp and swift dagger", 3, 2};
    Item staff = {"Staff", "A mystical staff for channeling magic", 6, 3};
    Item armor = {"Armor", "A protective armor suit", 2, 3};
    Item ring = {"Magic Ring", "A ring that enhances magical powers", 5, 5};

    // Inventory array (10 items)
    Item* inventory[MAX_ITEMS] = {&wand, &sword, &bow, &shield, &potion, &axe, &dagger, &staff, &armor, &ring};

    // Welcome and player setup
    std::cout << "Enter your player's name: ";
    std::cin >> playerName;

    char playerType[20];
    std::cout << "Choose your type (Wizard, Knight, Archer): ";
    std::cin >> playerType;

    // Assign player stats based on type, with a bit of randomness
    if (strcmp(playerType, "Wizard") == 0) {
        magic = 10 + rand() % 6;  // Random magic between 10 and 15
        strength = 3 + rand() % 5;   // Random strength between 3 and 7
    } else if (strcmp(playerType, "Knight") == 0) {
        magic = 0 + rand() % 2;   // Random magic between 0 and 1
        strength = 12 + rand() % 9;  // Random strength between 12 and 20
    } else if (strcmp(playerType, "Archer") == 0) {
        magic = 5 + rand() % 4;   // Random magic between 5 and 8
        strength = 8 + rand() % 6;   // Random strength between 8 and 13
    }

    std::cout << "\nWelcome " << playerName << " the " << playerType << "!\n";
    std::cout << "Stats: Magic = " << magic << ", Strength = " << strength << ", Health = " << health << "\n";

    // Game loop
    while (true) {
        std::string command;
        std::cout << "\nWhat would you like to do? (inventory, equip, quest, combat, quit): ";
        std::cin >> command;

        if (command == "inventory") {
            showInventory(inventory, MAX_ITEMS);
        } else if (command == "equip") {
            char itemName[50];
            std::cout << "Enter the name of the item to equip: ";
            std::cin >> itemName;
            equipItem(itemName, inventory, MAX_ITEMS, equippedItem);
        } else if (command == "quest") {
            checkQuest(inventory, MAX_ITEMS);
        } else if (command == "combat") {
            combat(health, equippedItem);
        } else if (command == "quit") {
            std::cout << "Thanks for playing! See you soon, " << playerName << "!\n";
            break;
        } else {
            std::cout << "Unknown command.\n";
        }

        // Random chance for a combat encounter (1 in 5 chance)
        if (rand() % 5 == 0) {
            combat(health, equippedItem);
        }
    }

    return 0;
}
