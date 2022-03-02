//
// Created by Caleb on 2/19/2022.
//
#include "timeout.h"

int errorMessage{0};

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
        complete = timeInput * multiplyVal;
        std::cout << fmt::format("The computer will shutdown in {}",complete) << std::endl;
    }

    void timeConversion::shutdown() {
        //std::cout << fmt::format("The system is shutting down in: {}\n", complete);
        HANDLE hToken; //handle the process tokens
        TOKEN_PRIVILEGES tkp; //pointer to the token structure
        //^= get the current process token handle to get the correct privleges to shut down the system
        if (!OpenProcessToken(GetCurrentProcess(),TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) {
            std::cout << "The process cannot be opened\nThe program failed";
        }
        //Get the LUID? for the shutdown privilege.
        LookupPrivilegeValue(nullptr, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid);
        tkp.PrivilegeCount = 1; //One privilege to set
        tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED; //Enable Privileges
        //Get the shutdown privilege
        AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES) nullptr,nullptr);
        if (GetLastError() != ERROR_SUCCESS) {
           std::cout << "The program exited in failure.";
            errorMessage = 1;
           exit(errorMessage);
        }
        char* machineName = nullptr; //Current machine
        char* machineMessage = "TimeOut is shutting down your computer";
        //Message will be displayed
        bool forceAppsClosed = false; //Displays box to close applications preventing dataloss
        bool restartImmediately = false; //Safely powers down the system & flushes the caches
        bool systemShutdown = InitiateSystemShutdown(machineName, machineMessage, complete, forceAppsClosed, restartImmediately);
        if (!systemShutdown) {
            if (printf("\nFunction successfully executes. Shutting down in: %d", complete) < 0) {
                errorMessage = 1;
                exit(errorMessage);
            }
            std::cout << "Success block";
        }
        tkp.Privileges[0].Attributes =0;
        AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES) nullptr, nullptr);
        std::cout << "The program has successfully executed";

}

    timeConversion::~timeConversion() {
    std::cout << "Cleaning up and exiting";
    exit(errorMessage);
};
