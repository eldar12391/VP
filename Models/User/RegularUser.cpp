#include "RegularUser.h"
#include <iostream>

// Конструктор с параметрами
RegularUser::RegularUser(const std::string& fName, const std::string& lName, int age,
                       const std::string& login, const std::string& pass)
    : User(fName, lName, age, login, pass) {}

// Отображение информации о пользователе
void RegularUser::displayInfo() const {
    std::cout << "Обычный пользователь: "
              << getFirstName() << " " << getLastName() << "\n"
              << "Возраст: " << getAge() << "\n"
              << "Логин: " << getLogin() << "\n";
}

// Смена пароля
void RegularUser::changePassword(const std::string& newPass) {
    setPassword(newPass);
    std::cout << "Пароль успешно изменен!\n";
}

// Операторы сравнения
bool RegularUser::operator==(const RegularUser& other) const {
    return this->getLogin() == other.getLogin();
}

bool RegularUser::operator<(const RegularUser& other) const {
    return this->getLogin() < other.getLogin();
}

// Операторы ввода/вывода
std::istream& operator>>(std::istream& is, RegularUser& user) {
    std::string fName, lName, login, pass;
    int age;
    is >> fName >> lName >> age >> login >> pass;
    
    user.setFirstName(fName);
    user.setLastName(lName);
    user.setAge(age);
    user.setLogin(login);
    user.setPassword(pass);
    
    return is;
}

std::ostream& operator<<(std::ostream& os, const RegularUser& user) {
    os << user.getFirstName() << " "
       << user.getLastName() << " "
       << user.getAge() << " "
       << user.getLogin() << " "
       << "[пароль скрыт]";
    return os;
}