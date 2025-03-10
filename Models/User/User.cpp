#include "User.h"

User::User(const std::string& fName, const std::string& lName, int age, 
           const std::string& login, const std::string& pass)
    : firstName(fName), lastName(lName), age(age), login(login), password(pass) {}

// Реализация геттеров
std::string User::getFirstName() const { return firstName; }
std::string User::getLastName() const { return lastName; }
int User::getAge() const { return age; }
std::string User::getLogin() const { return login; }
std::string User::getPassword() const { return password; }

// Реализация сеттеров
void User::setFirstName(const std::string& fName) { firstName = fName; }
void User::setLastName(const std::string& lName) { lastName = lName; }
void User::setAge(int age) { this->age = age; }
void User::setLogin(const std::string& login) { this->login = login; }
void User::setPassword(const std::string& pass) { password = pass; }