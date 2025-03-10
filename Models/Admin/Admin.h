#pragma once
#include "User.h"

class Admin : public User {
private:
    int adminLevel;

public:
    Admin() : User(), adminLevel(0) {}
    Admin(const std::string& fName, const std::string& lName, int age,
          const std::string& login, const std::string& pass, int level);
    
    void displayInfo() const override;
    void changePassword(const std::string& newPass) override;
    
    void setAdminLevel(int level) { adminLevel = level; }
    int getAdminLevel() const { return adminLevel; }

    friend std::ostream& operator<<(std::ostream& os, const Admin& admin);
    friend std::istream& operator>>(std::istream& is, Admin& admin);
};