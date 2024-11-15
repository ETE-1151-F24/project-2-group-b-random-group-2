#include "NPC.hpp"
#include <iostream>
NPC::NPC(const std::string& name, const std::string& dialogue) : name(name), dialogue(dialogue) {}

std::string NPC::interact() const {
    return dialogue;
}
