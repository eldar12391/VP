// AuthSystem.h
#pragma once
#include "User.h"
#include "Admin.h"
#include "RegularUser.h"

class AuthSystem {
    static const int MAX_USERS = 100;
    User* users[MAX_USERS]{};
    int numUsers = 0;

public:
    ~AuthSystem();
    User* login(const std::string& login, const std::string& pass) const;
    void addUser(User* user);
    void removeUser(const std::string& login);
    void displayAll() const;
};
