#include "OfflineHelper.h"
#include <fstream>

void OfflineHelper::saveDataOffline(const std::string& data) {
    std::ofstream f("assets/offline_cache.txt");
    if (f.is_open()) { f << data; f.close(); }
}

std::string OfflineHelper::loadDataOffline() {
    std::ifstream f("assets/offline_cache.txt");
    std::string d; getline(f, d); f.close(); return d
