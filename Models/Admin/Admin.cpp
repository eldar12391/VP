#include "Admin.h"
#include <iostream>

Admin::Admin(const std::string& fName, const std::string& lName, int age,
       const std::string& login, const std::string& pass, int level)
    : User(fName, lName, age, login, pass), adminLevel(level) {}

void Admin::displayInfo() const {
    std::cout << *this;
    std::cout << "Уровень админа: " << adminLevel << "\n";
}

void Admin::changePassword(const std::string& newPass) {
    setPassword(newPass);
}

std::ostream& operator<<(std::ostream& os, const Admin& admin) {
    os << static_cast<const User&>(admin);
    os << "Уровень админа: " << admin.adminLevel << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, Admin& admin) {
    is >> static_cast<User&>(admin);
    std::cout << "Уровень админа: ";
    is >> admin.adminLevel;
    return is;
}