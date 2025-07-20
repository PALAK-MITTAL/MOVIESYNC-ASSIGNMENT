#include "Parking.h"
#include <iostream>

ParkingSlot::ParkingSlot(int id) : slotId(id), isAvailable(true) {}

Reservation::Reservation(std::string rid, int sid, std::string uid)
    : reservationId(rid), slotId(sid), userId(uid), reservationTime(std::time(nullptr)) {}

void Reservation::showQR() const {
    std::cout << "QR Code [Simulated]: #" << reservationId << std::endl;
}

ParkingManager::ParkingManager(int totalSlots) {
    for (int i = 1; i <= totalSlots; ++i)
        slots[i] = ParkingSlot(i);
}

bool ParkingManager::bookSlot(const std::string& userId) {
    for (auto& entry : slots) {
        if (entry.second.isAvailable) {
            entry.second.isAvailable = false;
            std::string resId = "RES" + std::to_string(entry.first) + "_" + userId;
            Reservation res(resId, entry.first, userId);
            activeReservations[resId] = res;
            std::cout << "Slot #" << entry.first << " booked!\n";
            res.showQR();
            return true;
        }
    }
    std::cout << "No slots available.\n";
    return false;
}

void ParkingManager::cancelReservation(const std::string& resId) {
    if (activeReservations.count(resId)) {
        int sid = activeReservations[resId].slotId;
        slots[sid].isAvailable = true;
        activeReservations.erase(resId);
        std::cout << "Reservation " << resId << " canceled.\n";
    } else {
        std::cout << "Reservation not found.\n";
    }
}

void ParkingManager::showAvailability() const {
    std::cout << "Slot Availability:\n";
    for (const auto& entry : slots) {
        std::cout << "Slot #" << entry.first << ": "
                  << (entry.second.isAvailable ? "Available" : "Reserved") << "\n";
    }
}
