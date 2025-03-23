// Admin.cpp (пример реализации операторов)
#include "Admin.h"
#include <iostream>


Admin::Admin(const std::string& fName, const std::string& lName, int age,
    const std::string& login, const std::string& pass, int level)
: User(fName, lName, age, login, pass), adminLevel(level) {}

void Admin::displayInfo() const {
std::cout << "Администратор: "
        << getFirstName() << " " << getLastName() << "\n"
        << "Уровень доступа: " << adminLevel << "\n"
        << "Логин: " << getLogin() << "\n";
}

void Admin::changePassword(const std::string& newPass) {
setPassword(newPass);
std::cout << "Пароль администратора изменен!\n";
}


std::istream& operator>>(std::istream& is, Admin& admin) {
    std::string fName, lName, login, pass;
    int age, level;
    is >> fName >> lName >> age >> login >> pass >> level;
    admin.setFirstName(fName);
    admin.setLastName(lName);
    admin.setAge(age);
    admin.setLogin(login);
    admin.setPassword(pass);
    admin.setAdminLevel(level);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Admin& admin) {
    os << admin.getFirstName() << " "
       << admin.getLastName() << " "
       << admin.getAge() << " "
       << admin.getLogin() << " "
       << admin.getPassword() << " "
       << admin.getAdminLevel();
    return os;
}
