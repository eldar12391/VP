#include "menu/CMenu.h"
#include "menu/CMenuItem.h"
#include <cmath>
#include "Admin.h"
#include "User.h"
#include "RegularUser.h"

#include <algorithm>
using namespace std;

const int MAX_USERS = 100;
User* users[MAX_USERS] = {nullptr};
int userCount = 0;
Admin* currentAdmin = nullptr;


#pragma region Новые функции для управления пользователями
int addUser() {
    if(userCount >= MAX_USERS) {
        cout << "Ошибка: достигнуто максимальное количество пользователей!\n\n";
        return -1;
    }
    
    RegularUser* newUser = new RegularUser();
    cin >> *newUser;
    newUser->setId(userCount + 1);
    users[userCount++] = newUser;
    
    cout << "Пользователь успешно добавлен!\n\n";
    return 4;
}

int displayUsers() {
    if(userCount == 0) {
        cout << "Список пользователей пуст!\n\n";
        return -1;
    }
    
    cout << "\n=== Список пользователей ===" << endl;
    for(int i = 0; i < userCount; ++i) {
        users[i]->displayInfo();
        cout << "-------------------------" << endl;
    }
    return 5;
}

int sortUsers() {
    if(userCount < 2) {
        cout << "Недостаточно пользователей для сортировки!\n\n";
        return -1;
    }
    
    sort(users, users + userCount, [](User* a, User* b) {
        return *a < *b;
    });
    
    cout << "Пользователи отсортированы по фамилии!\n\n";
    return 6;
}

int deleteUser() {
    if(userCount == 0) {
        cout << "Список пользователей пуст!\n\n";
        return -1;
    }
    
    int index;
    cout << "Введите индекс пользователя для удаления (1-" << userCount << "): ";
    cin >> index;
    
    if(index < 1 || index > userCount) {
        cout << "Неверный индекс!\n\n";
        return -1;
    }
    
    delete users[index-1];
    for(int i = index-1; i < userCount-1; ++i) {
        users[i] = users[i+1];
    }
    userCount--;
    
    cout << "Пользователь успешно удален!\n\n";
    return 7;
}
#pragma endregion

#pragma region Функции меню
int printHello() {
    string name;
    std::cout << "Введите имя: ";
    std::cin >> name;
    std::cout << std::endl;
    std::cout << "Привет, " << name << "\n\n";
    return 1;
}

int calcProduct() {
    int num1{}, num2{};
    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите второе число: ";
    cin >> num2;
    cout << "Результат: " << num1 * num2;
    cout << "\n\n";
    return 2;
}

int printSquare() {
    int width{}, height{};
    cout << "Введите ширину прямоугольника: ";
    cin >> width;
    cout << "Введите длину прямоугольника: ";
    cin >> height;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << "\n\n";
    return 3;
}

int createAdmin() {
    string fName, lName, login, pass;
    int age, level;
    
    cout << "\n=== Создание администратора ===" << endl;
    cout << "Имя: ";
    cin >> fName;
    cout << "Фамилия: ";
    cin >> lName;
    cout << "Возраст: ";
    cin >> age;
    cout << "Логин: ";
    cin >> login;
    cout << "Пароль: ";
    cin >> pass;
    cout << "Уровень доступа: ";
    cin >> level;
    
    if(currentAdmin) delete currentAdmin;
    currentAdmin = new Admin(fName, lName, age, login, pass, level);
    
    cout << "Администратор создан!\n\n";
    return 1;
}

int showAdminInfo() {
    if(!currentAdmin) {
        cout << "Ошибка: администратор не создан!\n\n";
        return -1;
    }
    cout << "\n=== Информация об администраторе ===" << endl;
    currentAdmin->displayInfo();
    cout << endl;
    return 2;
}

int changeAdminPass() {
    if(!currentAdmin) {
        cout << "Ошибка: администратор не создан!\n\n";
        return -1;
    }
    
    string newPass;
    cout << "\n=== Смена пароля ===" << endl;
    cout << "Новый пароль: ";
    cin >> newPass;
    
    currentAdmin->changePassword(newPass);
    cout << "Пароль успешно изменен!\n\n";
    return 3;
}

int exitProgram() {
    if(currentAdmin) delete currentAdmin;
    cout << "Выход из программы...\n";
    return 0;
}

#pragma endregion

const int ITEMS_NUMBER = 7;


int main() {
    CMenuItem items[ITEMS_NUMBER] {
        CMenuItem{"Поздороваться с пользователем", printHello}, 
        CMenuItem{"Посчитать произведение двух целых чисел", calcProduct}, 
        CMenuItem{"Напечатать прямоугольник", printSquare},
        CMenuItem{"Создать администратора", createAdmin},
        CMenuItem{"Показать информацию", showAdminInfo},
        CMenuItem{"Сменить пароль", changeAdminPass},
        CMenuItem{"Выход", exitProgram}};

        CMenu menu("=== Система управления пользователями ===", items, ITEMS_NUMBER);
    while (menu.runCommand()) {};

    return 0;
}