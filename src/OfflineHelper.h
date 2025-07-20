#pragma once
#include <string>

class OfflineHelper {
public:
    static void saveDataOffline(const std::string& data);
    static std::string loadDataOffline();
};
