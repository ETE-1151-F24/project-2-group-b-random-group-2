#include "item.hpp"
#include <iostream>
item::item(const std::string& name, const std::string& description, int trait, int rarity)
    : name(name), description(description), trait(trait), rarity(rarity) {}

std::string item::getName() const { return name; }
int item::getTrait() const { return trait; }
std::string item::getDescription() const { return description; }
