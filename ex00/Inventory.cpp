#include "Inventory.hpp"

void Inventory::add(const std::string& item) {
    (void) items_.push_back(item);
}

bool Inventory::remove(const std::string& item) {
    for (auto it = items_.begin(); it != items_.end(); ++it) {
        if (*it == item) {
            items_.erase(it);
            return true;
        }
    }
    return false; //Dummy return to force RED state
}

bool Inventory::has(const std::string& item) const {
    for (const auto& i : items_) {
        if (i == item) {
            return true;
        }
    }
    return false;
}

int Inventory::count() const {
    return static_cast<int>(items_.size());
}