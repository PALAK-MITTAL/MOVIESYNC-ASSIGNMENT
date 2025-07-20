#pragma once
#include <unordered_map>
#include <string>

class CacheManager {
private:
    std::unordered_map<std::string, std::string> cache;
public:
    void store(const std::string& key, const std::string& value);
    std::string retrieve(const std::string& key);
};
