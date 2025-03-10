#pragma once
#include "User.h"

class Admin : public User {
private:
    int adminLevel;

public:
    Admin(const std::string& fName, const std::string& lName, int age,
          const std::string& login, const std::string& pass, int level);
    
    void displayInfo() const override;
    void changePassword(const std::string& newPass) override;
    
    void setAdminLevel(int level);
    int getAdminLevel() const;
};
