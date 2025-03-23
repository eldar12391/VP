// User.cpp
#include "User.h"

User::User(const std::string& fName, const std::string& lName, int age,
         const std::string& login, const std::string& pass)
    : firstName(fName),
      lastName(lName),
      age(age),
      login(login),
      password(pass) {}