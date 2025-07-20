#pragma once
class AIPriceEngine {
public:
    double adjustPriceForFactors(double baseFare, bool badWeather, int crowdLevel, bool eventNearby);
};
