#include "PricingEngine.h"

double PricingEngine::calculateFare(const std::string& rideType, int hourOfDay) {
    double base = (rideType == "Cab") ? 100 : (rideType == "Shuttle") ? 60 : 40;
    if ((hourOfDay >= 8 && hourOfDay <= 10) || (hourOfDay >= 18 && hourOfDay <= 20))
        base *= 1.5;
    return base;
}
