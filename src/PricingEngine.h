#pragma once
#include <string>

class PricingEngine {
public:
    double calculateFare(const std::string& rideType, int hourOfDay);
};
