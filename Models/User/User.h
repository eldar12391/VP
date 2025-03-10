#pragma once
#include <string>

class User {
protected:
    std::string firstName;
    std::string lastName;
    std::string login;
    std::string password;
    int age;
    int userId;
public:
    User() : userId(-1) {}
    User(const std::string& fName, const std::string& lName, int age, 
         const std::string& login, const std::string& pass);
    virtual ~User() = default;

    std::string getFirstName() const;
    std::string getLastName() const;
    int getAge() const;
    std::string getLogin() const;
    std::string getPassword() const;

    void setFirstName(const std::string& fName);
    void setLastName(const std::string& lName);
    void setAge(int age);
    void setLogin(const std::string& login);
    void setPassword(const std::string& pass);
    void setId(int id);


    virtual void displayInfo() const = 0;
    virtual void changePassword(const std::string& newPass) = 0;

    bool operator==(const User& other) const;
    bool operator<(const User& other) const;

    friend std::ostream& operator<<(std::ostream& os, const User& user);
    friend std::istream& operator>>(std::istream& is, User& user);
};
