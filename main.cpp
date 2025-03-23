#include "menu/CMenu.h"
#include "menu/CMenuItem.h"
#include "Admin.h"
#include "RegularUser.h"
#include "AuthSystem.h"
#include <iostream>
#include <limits>

AuthSystem authSystem;
User* currentUser = nullptr;

// Прототипы функций меню
int loginUser();
int registerUser();
int logout();
int exitProgram();
int createAdmin();
int createRegularUser();
int showUserInfo();
int changePassword();
int deleteAccount();
int listAllUsers();

// Меню для гостей
CMenuItem guestItems[] = {
    {"Войти в систему", loginUser},
    {"Зарегистрироваться", registerUser},
};

// Для пользователей:
CMenuItem userItems[] = {
    {"Показать информацию", showUserInfo},
    {"Сменить пароль", changePassword},
    {"Удалить аккаунт", deleteAccount}
    // УДАЛЕН "Выход"
};

// Для администраторов:
CMenuItem adminItems[] = {
    {"Создать администратора", createAdmin},
    {"Создать пользователя", createRegularUser},
    {"Список всех пользователей", listAllUsers},
    {"Удалить пользователя", deleteAccount}
    // УДАЛЕН "Выход"
};

// Создание динамического меню
CMenu* createDynamicMenu() {
    if(!currentUser) return new CMenu("Главное меню", guestItems, 2); // было 3
    if(dynamic_cast<Admin*>(currentUser))
        return new CMenu("Админ-меню", adminItems, 4); // было 5
    return new CMenu("Пользовательское меню", userItems, 3); // было 4
}
int main() {
    while (true) {
        CMenu* currentMenu = createDynamicMenu();
        currentMenu->print();
        int result = currentMenu->runCommand();
        delete currentMenu;
        
        if (result == 0) break;
        std::cout << "\nНажмите Enter для продолжения...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }
    return 0;
}

// Реализации функций меню
int loginUser() {
    std::string login, pass;
    std::cout << "Логин: ";
    std::cin >> login;
    std::cout << "Пароль: ";
    std::cin >> pass;

    currentUser = authSystem.login(login, pass);
    if (currentUser) {
        std::cout << "Успешный вход!\n";
        if (dynamic_cast<Admin*>(currentUser)) {
            std::cout << "Добро пожаловать, администратор!\n";
        } else {
            std::cout << "Добро пожаловать, пользователь!\n";
        }
    } else {
        std::cout << "Неверные учетные данные!\n";
    }
    return 1;
}

int registerUser() {
    int choice;
    std::cout << "1. Администратор\n2. Обычный пользователь\nВыберите тип: ";
    std::cin >> choice;

    if (choice == 1) {
        Admin a;
        std::cout << "Введите данные (Имя Фамилия Возраст Логин Пароль Уровень): ";
        std::cin >> a;
        authSystem.addUser(new Admin(a));
    } else if (choice == 2) {
        RegularUser u;
        std::cout << "Введите данные (Имя Фамилия Возраст Логин Пароль): ";
        std::cin >> u;
        authSystem.addUser(new RegularUser(u));
    } else {
        std::cout << "Некорректный выбор!\n";
    }
    return 1;
}

int logout() {
    currentUser = nullptr;
    std::cout << "Выход выполнен.\n";
    return 1;
}

int exitProgram() {
    std::cout << "Завершение работы...\n";
    return 0;
}

int showUserInfo() {
    if (currentUser) {
        currentUser->displayInfo();
    }
    return 1;
}

int changePassword() {
    if (currentUser) {
        std::string newPass;
        std::cout << "Введите новый пароль: ";
        std::cin >> newPass;
        currentUser->changePassword(newPass);
    }
    return 1;
}

int deleteAccount() {
    if (currentUser) {
        authSystem.removeUser(currentUser->getLogin());
        currentUser = nullptr;
        std::cout << "Аккаунт удален!\n";
    }
    return 1;
}

int listAllUsers() {
    if (dynamic_cast<Admin*>(currentUser)) {
        authSystem.displayAll();
    } else {
        std::cout << "Доступ запрещен!\n";
    }
    return 1;
}

// Добавьте в main.cpp
int createAdmin() {
    Admin a;
    std::cout << "Введите данные админа: ";
    std::cin >> a;
    authSystem.addUser(new Admin(a));
    return 1;
}

int createRegularUser() {
    RegularUser u;
    std::cout << "Введите данные пользователя: ";
    std::cin >> u;
    authSystem.addUser(new RegularUser(u));
    return 1;
}