//
// Created by Caleb on 2/19/2022.
//

#ifndef TEST_TIMEOUT_H
#define TEST_TIMEOUT_H
#define FMT_HEADER_ONLY
#include <fmt/core.h>
#include <compare>
#include <iostream>

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
    ~timeConversion();
private:
    int timeInput{};
};

#endif //TEST_TIMEOUT_H
