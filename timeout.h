//
// Created by Caleb on 2/19/2022.
//

#ifndef TEST_TIMEOUT_H
#define TEST_TIMEOUT_H
#define FMT_HEADER_ONLY
#include <fmt/core.h>
#include <compare>
#include <iostream>
#include <windows.h>
#define WIN32_LEAN_AND_MEAN //Define WIN32_LEAN_AND_MEAN to exclude APIs such as Cryptography, DDE, RPC, Shell, and Windows Sockets.
#include <stdbool.h>
//These are currently broken in cmake; the file is not configured
//This will compile on MSVC
#pragma comment(lib, "ADVAPI32")
#pragma comment(lib, "USER32")

class timeout {
public:
    static void printWelcome();
};

class timeConversion {
public:
    int errorMessage {0};
    timeConversion();
    void setValue(int);
    void message();
    void convert();
    void shutdown();
    ~timeConversion();
private:
    int timeInput{};
    unsigned int complete{};
};

#endif //TEST_TIMEOUT_H
