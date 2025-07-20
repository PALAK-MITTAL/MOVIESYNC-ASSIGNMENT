#include <iostream>
#include <ctime>
#include "User.h"
#include "Parking.h"
#include "RideService.h"
#include "PricingEngine.h"
#include "AIPriceEngine.h"
#include "OfflineHelper.h"
#include "ErrorHandler.h"
#include "CacheManager.h"
#include "Logger.h"
#include "ConflictManager.h"
#include "AccessControl.h"

void simulateMonitoring() {
    Logger::logInfo("Monitoring system OK.");
}

int main() {
    User palak("palak123", "PALAK");
    ParkingManager manager(3);
    Cab cab; Shuttle shuttle; ERickshaw erick;
    PricingEngine basicPricing;
    AIPriceEngine smartPricing;

    std::string id;
    std::cout << "Enter login ID: ";
    std::cin >> id;

    if (!palak.login(id)) {
        ErrorHandler::displayError("Authentication Failed.");
        return 0;
    }
    Logger::logInfo("User authenticated.");

    manager.bookSlot(palak.userId);
    manager.showAvailability();

    cab.bookRide(palak.userId);

    std::time_t now = std::time(nullptr);
    std::tm* timeInfo = std::localtime(&now);
    int hour = timeInfo->tm_hour;

    double fare = basicPricing.calculateFare("Cab", hour);
    fare = smartPricing.adjustPriceForFactors(fare, true, 70, true);
    std::cout << "Final Cab Fare: ₹" << fare << "\n";

    OfflineHelper::saveDataOffline("Reservation: RES1_palak123");
    std::cout << "Offline Data: " << OfflineHelper::loadDataOffline() << "\n";

    CacheManager cache;
    cache.store("lastRide", "Cab");
    std::cout << "From cache: " << cache.retrieve("lastRide") << "\n";

    AccessControl access;
    access.scanLicensePlate("DL3CAB1234");
    access.readRFID("RF-349XY");

    simulateMonitoring();
    return 0;
}
