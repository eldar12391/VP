#include "User.h"
#include <iostream>
#include <limits>

User::User(const std::string& fName, const std::string& lName, int age, 
           const std::string& login, const std::string& pass)
    : firstName(fName), lastName(lName), age(age), login(login), password(pass) {}

std::string User::getFirstName() const { return firstName; }
std::string User::getLastName() const { return lastName; }
int User::getAge() const { return age; }
std::string User::getLogin() const { return login; }
std::string User::getPassword() const { return password; }

void User::setFirstName(const std::string& fName) { firstName = fName; }
void User::setLastName(const std::string& lName) { lastName = lName; }
void User::setAge(int age) { this->age = age; }
void User::setLogin(const std::string& login) { this->login = login; }
void User::setPassword(const std::string& pass) { password = pass; }
void User::setId(int id) { userId = id; }


bool User::operator==(const User& other) const {
    return userId == other.userId;
}

bool User::operator<(const User& other) const {
    return lastName < other.lastName;
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "ID: " << user.userId << "\n";
    os << "Имя и фамилия: " << user.firstName << " " << user.lastName << "\n";
    os << "Возраст: " << user.age << "\n";
    os << "Логин: " << user.login << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, User& user) {
    std::cout << "Имя: ";
    is >> user.firstName;
    std::cout << "Фамилия: ";
    is >> user.lastName;
    std::cout << "Возраст: ";
    is >> user.age;
    std::cout << "Логин: ";
    is >> user.login;
    std::cout << "Пароль: ";
    is >> user.password;
    return is;
}