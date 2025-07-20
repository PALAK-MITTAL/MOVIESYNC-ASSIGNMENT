#include "ConflictManager.h"
#include <iostream>
#include <ctime>

bool ConflictManager::checkNoShow(const std::unordered_map<std::string, std::time_t>& reservations) {
    std::time_t now = std::time(nullptr);
    for (auto& entry : reservations) {
        if (difftime(now, entry.second) > 1800) { // 30 min grace period
            std::cout << "No-show detected for " << entry.first << "\n";
            return true;
        }
    }
    return false;
}

void ConflictManager::autoReassignSlot(int oldSlotId, int newSlotId) {
    std::cout << "Reassigning from Slot #" << oldSlotId << " to #" << newSlotId << "\n";
}
