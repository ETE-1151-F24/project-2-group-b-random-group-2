#ifndef GAME_H
#define GAME_H

#include "player.hpp"
#include "NPC.hpp"
#include <vector>

class Game {
public:
    Game(const std::string& playerName, const std::string& playerType);
    void start();

private:
    player player;
    std::vector<NPC> npcs;

    void interactWithNPC(int npcIndex);
    void engageCombat();
};

#endif
