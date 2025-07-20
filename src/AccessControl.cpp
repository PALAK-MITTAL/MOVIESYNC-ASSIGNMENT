#include "AccessControl.h"
#include <iostream>

bool AccessControl::scanLicensePlate(const std::string& plate) {
    std::cout << "Scanning License Plate: " << plate << "\n";
    return plate.length() >= 5; // dummy rule
}

bool AccessControl::readRFID(const std::string& tag) {
    std::cout << "Reading RFID tag: " << tag << "\n";
    return tag.substr(0, 3) == "RF-"; // dummy rule
}
