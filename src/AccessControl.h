#pragma once
#include <string>

class AccessControl {
public:
    bool scanLicensePlate(const std::string& plate);
    bool readRFID(const std::string& tag);
};
