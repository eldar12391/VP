// User.h
#pragma once
#include <string>

class User {
protected:
    std::string firstName;
    std::string lastName;
    int age;
    std::string login;
    std::string password;

public:
    User(const std::string& fName, const std::string& lName, int age, 
         const std::string& login, const std::string& pass);
    virtual ~User() = default;

    // Геттеры
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    int getAge() const { return age; }
    std::string getLogin() const { return login; }
    std::string getPassword() const { return password; }

    // Сеттеры
    void setFirstName(const std::string& fName) { firstName = fName; }
    void setLastName(const std::string& lName) { lastName = lName; }
    void setAge(int age) { this->age = age; }
    void setLogin(const std::string& login) { this->login = login; }
    void setPassword(const std::string& pass) { password = pass; }

    virtual void displayInfo() const = 0;
    virtual void changePassword(const std::string& newPass) = 0;
};