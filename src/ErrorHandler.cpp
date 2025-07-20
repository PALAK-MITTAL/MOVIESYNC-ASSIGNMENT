#include "ErrorHandler.h"
#include <iostream>

void ErrorHandler::displayError(const std::string& msg) {
    std::cerr << "[ERROR]: " << msg << "\n";
}
