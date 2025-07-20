#pragma once
#include <unordered_map>
#include <string>

class ConflictManager {
public:
    bool checkNoShow(const std::unordered_map<std::string, std::time_t>& reservations);
    void autoReassignSlot(int oldSlotId, int newSlotId);
};
