// CMenuItem.h
#pragma once
#include <iostream>
#include <string>

class CMenuItem {
public:
    using Func = int(*)();
    
    CMenuItem(std::string name, Func func);
    Func func{};
    std::string item_name{};
    
    std::string getName();
    void print();
    int run();
};