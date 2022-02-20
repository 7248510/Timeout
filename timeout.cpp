//
// Created by Caleb on 2/19/2022.
//
#include "timeout.h"

int errorMessage {0};

void timeout::printWelcome() {
    std::string welcome{"Hello you started TimeOut"};
    std::cout << fmt::format("{}",welcome) << std::endl;
}

    timeConversion::timeConversion() {
        message();
    }

    void timeConversion::setValue(int tmp) {
        std::strong_ordering result{tmp <=> 0};
        if (result == std::strong_ordering::equal) {
            std::cout << "Zero has been entered. This is an invalid value.";
            errorMessage = -1;
            exit(errorMessage);
        }
        if (result == std::strong_ordering::less) {
            std::cout << "The value is less than 0 that is an invalid value ";
            errorMessage = -2;
            exit(errorMessage);
        } else {
            std::cout << fmt::format("The value has been set to {}", tmp) << std::endl;
            timeInput = tmp;
        }
    }


    void timeConversion::message() {
        std::cout << fmt::format("Please enter an hour. You would like converted to seconds.") << std::endl;
    }

    void timeConversion::convert() {
        const unsigned int multiplyVal = 3600;
        unsigned int complete = timeInput * multiplyVal;
        std::cout << fmt::format("The computer will shutdown in {}",complete) << std::endl;
    }

    timeConversion::~timeConversion() {
    std::cout << "Cleaning up and exiting";
    exit(errorMessage);
};
