#include "Logger.h"
#include <fstream>
#include <iostream>

void Logger::logInfo(const std::string& msg) {
    std::ofstream log("system.log", std::ios::app);
    log << "[INFO]: " << msg << "\n";
    log.close();
}

void Logger::logError(const std::string& msg) {
    std::ofstream log("system.log", std::ios::app);
    log << "[ERROR]: " << msg << "\n";
    log.close();
    std::cerr << "[ERROR]: " << msg << "\n";
}
