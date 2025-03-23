#include "CMenu.h"
#include <iostream>
#include <limits>

CMenu::CMenu(std::string title, CMenuItem* items, size_t count)
    : title(std::move(title)), items(items), count(count) {}

void CMenu::print() {
    std::cout << "\n=== " << title << " ===\n";
    for(size_t i = 0; i < count; ++i) {
        std::cout << i+1 << ". " << items[i].getName() << "\n"; // Добавляем перевод строки
    }
    std::cout << "0. Выход\n\n"; // Добавляем отступ после меню
}
int CMenu::runCommand() {
    int choice;
    while(true) {
        std::cout << "Выберите пункт: ";
        std::cin >> choice;
        
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Ошибка ввода! Введите число.\n";
            continue;
        }
        
        if(choice < 0 || choice > static_cast<int>(count)) {
            std::cerr << "Неверный выбор! Попробуйте снова.\n";
            continue;
        }
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;
    }

    if(choice == 0) return 0;
    return items[choice-1].run();
}

int CMenu::getSelect() const {
    return select;
}

bool CMenu::isRun() const {
    return running;
}

std::string CMenu::getTitle() {
    return title;
}

size_t CMenu::getCount() const {
    return count;
}

CMenuItem* CMenu::getItems() {
    return items;
}