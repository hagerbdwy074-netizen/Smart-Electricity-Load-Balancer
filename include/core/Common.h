#pragma once
enum class priority {
    Normal,
    Middle,
    High
};

enum class ConnectionStatus {
    Connected,
    Disconnected
};

#define RESET   "\033[0m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define BCYAN   "\033[96m"
#define MAGENTA "\033[35m"
#define RED     "\033[31m"
#define WHITE   "\033[97m"

#include <iostream>
inline void setColor(const char* colorCode) { std::cout << colorCode; }
inline void setColor(const std::string& colorCode) { std::cout << colorCode; }