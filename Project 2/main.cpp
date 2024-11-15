#include "game.hpp"
#include <iostream>

int main() {
    std::string playerName;
    std::string playerType;

    std::cout << "Enter your player's name: ";
    std::cin >> playerName;

    std::cout << "Choose your type (Wizard, Knight, Archer): ";
    std::cin >> playerType;

    Game game(playerName, playerType);
    game.start();

    return 0;
}
