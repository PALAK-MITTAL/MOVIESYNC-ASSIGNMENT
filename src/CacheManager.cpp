#include "CacheManager.h"

void CacheManager::store(const std::string& key, const std::string& value) {
    cache[key] = value;
}

std::string CacheManager::retrieve(const std::string& key) {
    if (cache.find(key) != cache.end()) {
        return cache[key];
    }
    return "";
}
