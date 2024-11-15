#ifndef NPC_H
#define NPC_H

#include <string>

class NPC {
public:
    NPC(const std::string& name, const std::string& dialogue);

    std::string interact() const;

private:
    std::string name;
    std::string dialogue;
};

#endif
