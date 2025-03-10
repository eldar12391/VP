#pragma once
#include "User.h"
#include <iostream>

class RegularUser : public User {
public:
    RegularUser() : User() {}
    RegularUser(const std::string& fName, const std::string& lName, int age,
                const std::string& login, const std::string& pass)
        : User(fName, lName, age, login, pass) {}

    void displayInfo() const override {
        std::cout << *this;
    }

    void changePassword(const std::string& newPass) override {
        setPassword(newPass);
    }
};