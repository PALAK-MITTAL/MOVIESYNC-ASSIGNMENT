#include "User.h"

User::User(std::string id, std::string uname)
    : userId(id), name(uname), isAuthenticated(false) {}

bool User::login(std::string enteredId) {
    isAuthenticated = (enteredId == userId);
    return isAuthenticated;
}
