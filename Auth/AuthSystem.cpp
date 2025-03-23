#include "AuthSystem.h"
#include <iostream>

// Деструктор (освобождение памяти)
AuthSystem::~AuthSystem() {
    for(int i = 0; i < numUsers; ++i) {
        delete users[i];
        users[i] = nullptr;
    }
}

// Аутентификация пользователя
User* AuthSystem::login(const std::string& login, const std::string& pass) const {
    for(int i = 0; i < numUsers; ++i) {
        if(users[i]->getLogin() == login && users[i]->getPassword() == pass) {
            return users[i];
        }
    }
    return nullptr;
}

// Добавление пользователя
void AuthSystem::addUser(User* user) {
    // Проверка на дубликаты логина
    for(int i = 0; i < numUsers; ++i) {
        if(users[i]->getLogin() == user->getLogin()) {
            std::cerr << "Ошибка: Логин уже занят!\n";
            delete user;
            return;
        }
    }
    
    // Проверка на переполнение
    if(numUsers >= MAX_USERS) {
        std::cerr << "Ошибка: Достигнут лимит пользователей!\n";
        delete user;
        return;
    }
    
    users[numUsers++] = user;
}

// Удаление пользователя
void AuthSystem::removeUser(const std::string& login) {
    for(int i = 0; i < numUsers; ++i) {
        if(users[i]->getLogin() == login) {
            delete users[i];
            // Сдвиг элементов массива
            for(int j = i; j < numUsers-1; ++j) {
                users[j] = users[j+1];
            }
            users[numUsers-1] = nullptr;
            numUsers--;
            std::cout << "Пользователь " << login << " удален\n";
            return;
        }
    }
    std::cerr << "Пользователь " << login << " не найден!\n";
}

// Отображение всех пользователей
void AuthSystem::displayAll() const {
    std::cout << "\n=== Список пользователей (" << numUsers << ") ===\n";
    for(int i = 0; i < numUsers; ++i) {
        users[i]->displayInfo();
        if(dynamic_cast<Admin*>(users[i])) {
            std::cout << "Тип: Администратор\n";
        } else {
            std::cout << "Тип: Обычный пользователь\n";
        }
        std::cout << "------------------------\n";
    }
}