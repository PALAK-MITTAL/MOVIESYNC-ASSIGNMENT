#include "RideService.h"
#include <iostream>

void Cab::bookRide(std::string userId) {
    std::cout << "Cab booked for " << userId << "\n";
}
std::string Cab::getType() const { return "Cab"; }

void Shuttle::bookRide(std::string userId) {
    std::cout << "Shuttle booked for " << userId << "\n";
}
std::string Shuttle::getType() const { return "Shuttle"; }

void ERickshaw::bookRide(std::string userId) {
    std::cout << "E-Rickshaw booked for " << userId << "\n";
}
std::string ERickshaw::getType() const { return "E-Rickshaw"; }
