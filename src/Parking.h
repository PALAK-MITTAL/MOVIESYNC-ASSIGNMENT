#pragma once
#include <string>
#include <unordered_map>
#include <ctime>

class ParkingSlot {
public:
    int slotId;
    bool isAvailable;
    ParkingSlot(int id);
};

class Reservation {
public:
    std::string reservationId;
    int slotId;
    std::string userId;
    std::time_t reservationTime;
    Reservation(std::string rid, int sid, std::string uid);
    void showQR() const;
};

class ParkingManager {
private:
    std::unordered_map<int, ParkingSlot> slots;
    std::unordered_map<std::string, Reservation> activeReservations;
public:
    ParkingManager(int totalSlots);
    bool bookSlot(const std::string& userId);
    void cancelReservation(const std::string& resId);
    void showAvailability() const;
};
