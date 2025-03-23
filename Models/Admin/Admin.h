// Admin.h
#pragma once
#include "User.h"

class Admin : public User {
private:
    int adminLevel;

public:
    Admin(const std::string& fName, const std::string& lName, int age,
          const std::string& login, const std::string& pass, int level);
    Admin() : User("", "", 0, "", ""), adminLevel(0) {}

    void displayInfo() const override;
    void changePassword(const std::string& newPass) override;
    
    void setAdminLevel(int level) { adminLevel = level; }
    int getAdminLevel() const { return adminLevel; }

    bool operator==(const Admin& other) const;
    bool operator<(const Admin& other) const;

    friend std::istream& operator>>(std::istream& is, Admin& admin);
    friend std::ostream& operator<<(std::ostream& os, const Admin& admin);
};