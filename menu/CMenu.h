// CMenu.h
#pragma once
#include <string>
#include "./CMenuItem.h"

class CMenu {
public:
    CMenu(std::string title, CMenuItem* items, size_t count);
    ~CMenu() = default;
    
    int getSelect() const;
    bool isRun() const;
    std::string getTitle();
    size_t getCount() const;
    CMenuItem* getItems();
    void print();
    int runCommand();

private:
    int select{-1};
    size_t count{};
    bool running{};
    std::string title{};
    CMenuItem* items{};
};