#include "game.hpp"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

Game::Game(const std::string& playerName, const std::string& playerType)
 : player(playerName, playerType) {
    // Initialize some NPCs
    npcs.push_back(NPC("Guard", "Stay safe out there, traveler!"));
    npcs.push_back(NPC("Wizard", "Magic is a powerful tool, use it wisely."));
    srand(static_cast<unsigned int>(time(0)));
}

void Game::start() {
    std::string command;
    while (player.isAlive()) {
        std::cout << "\nWhat would you like to do? (stats, combat, npc, quit): ";
        std::cin >> command;

        if (command == "stats") {
            player.displayStats();
        } else if (command == "combat") {
            engageCombat();
        } else if (command == "npc") {
            int npcIndex;
            std::cout << "Enter NPC index to interact with (0-" << npcs.size() - 1 << "): ";
            std::cin >> npcIndex;

            try {
                if (npcIndex < 0 || npcIndex >= npcs.size()) {
                    throw std::out_of_range("Invalid NPC index!");
                }
                interactWithNPC(npcIndex);
            } catch (const std::out_of_range& e) {
                std::cout << e.what() << "\n";
            }
        } else if (command == "quit") {
            std::cout << "Thanks for playing!\n";
            break;
        } else {
            std::cout << "Unknown command.\n";
        }
    }
}

void Game::interactWithNPC(int npcIndex) {
    std::cout << "NPC says: " << npcs[npcIndex].interact() << "\n";
}

void Game::engageCombat() {
    int monsterDamage = rand() % 20 + 5;
    std::cout << "You encounter a monster! It deals " << monsterDamage << " damage.\n";
    player.takeDamage(monsterDamage);
    player.gainExperience(5);
}
