#pragma once
#include <string>

class User {
public:
    std::string userId;
    std::string name;
    bool isAuthenticated;

    User(std::string id, std::string uname);
    bool login(std::string enteredId);
};
