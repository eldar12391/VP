// RegularUser.h
#pragma once
#include "User.h"

class RegularUser : public User {
public:
    RegularUser(const std::string& fName, const std::string& lName, int age,
              const std::string& login, const std::string& pass);
    RegularUser() : User("", "", 0, "", "") {}

    void displayInfo() const override;
    void changePassword(const std::string& newPass) override;

    bool operator==(const RegularUser& other) const;
    bool operator<(const RegularUser& other) const;

    friend std::istream& operator>>(std::istream& is, RegularUser& user);
    friend std::ostream& operator<<(std::ostream& os, const RegularUser& user);
};