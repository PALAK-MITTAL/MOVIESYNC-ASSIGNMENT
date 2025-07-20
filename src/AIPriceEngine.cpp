#include "AIPriceEngine.h"

double AIPriceEngine::adjustPriceForFactors(double baseFare, bool badWeather, int crowdLevel, bool eventNearby) {
    if (badWeather) baseFare *= 1.2;
    if (crowdLevel > 50) baseFare *= 1.3;
    if (eventNearby) baseFare += 50;
    return baseFare;
}
