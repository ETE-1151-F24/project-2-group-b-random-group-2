#ifndef ITEM_H
#define ITEM_H

#include <string>

class item {
public:
    item(const std::string& name, const std::string& description, int trait, int rarity);

    std::string getName() const;
    int getTrait() const;
    std::string getDescription() const;

private:
    std::string name;
    std::string description;
    int trait;    // Effect on combat, e.g., bonus damage or defense
    int rarity;   // Rarity from 1 to 5
};

#endif
