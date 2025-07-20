#pragma once
#include <string>

class RideService {
public:
    virtual void bookRide(std::string userId) = 0;
    virtual std::string getType() const = 0;
    virtual ~RideService() {}
};

class Cab : public RideService {
public:
    void bookRide(std::string userId) override;
    std::string getType() const override;
};

class Shuttle : public RideService {
public:
    void bookRide(std::string userId) override;
    std::string getType() const override;
};

class ERickshaw : public RideService {
public:
    void bookRide(std::string userId) override;
    std::string getType() const override;
};
