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

void timeout::printWelcome() {
    std::string welcome{"Hello you started TimeOut"};
    std::cout << fmt::format("{}",welcome) << std::endl;
}





class timeConversion {
public:
    int errorMessage {0};

    timeConversion() {
        errorMessage = -1;
        std::cout << fmt::format("Number not declared exiting with error code {}", errorMessage);
        exit(errorMessage);
    }

    timeConversion(int tmp) {
        timeInput = tmp;
    }


    void message() {
        std::cout << fmt::format("Please enter an hour. You would like converted to seconds.") << std::endl;
    }
    void convert() {
        std::strong_ordering result{ timeInput <=> 0 };
        if (result == std::strong_ordering::equal) {
            std::cout << "You entered zero. This is an invalid value.";
        }

        const unsigned int multiplyVal = 3600;
        unsigned int complete = timeInput * multiplyVal;

        std::cout << complete;
    }

private:
    int timeInput;
};




#endif //TEST_TIMEOUT_H
