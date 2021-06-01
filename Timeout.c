//cl /EHsc /sdl /W4 /TC Timeout.c
#include "Timeout.h"
void convertHours(int hour, int* returnCalulation) {
    int multiplyVal = 3600;
    int passedHour = hour;
    *returnCalulation = passedHour * multiplyVal;
    return;
}
int winShutdown(int systemTime) {
    HANDLE hToken; //handle the process tokens
    TOKEN_PRIVILEGES tkp; //pointer to the token structure
    //^= get the current process token handle to get the correct privleges to shut down the system
    if (!OpenProcessToken(GetCurrentProcess(),TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) {
        return false;
    }
        
    //Get the LUID? for the shutdown privilege.
    LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid);
    tkp.PrivilegeCount = 1; //One privilege to set
    tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED; //Enable Privileges
    //Get the shutdown privilege
    AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES) NULL,0);
    if (GetLastError() != ERROR_SUCCESS) {
        return EXIT_FAILURE;
    }
    char* machineName = NULL; //Current machine
    char* machineMessage = "TimeOut is shutting down your computer";
    printf("\nSHUTDOWN TIME: %d", systemTime);
    //Message will be displayed
    bool forceAppsClosed = false; //Displays box to close applications preventing dataloss
    bool restartImmediately = false; //Safely powers down the system & flushes the caches
    bool systemShutdown = InitiateSystemShutdown(machineName, machineMessage, systemTime, forceAppsClosed, restartImmediately);
    if (!systemShutdown) {
        if (printf("\nFunction succesfully executes. Shutting down in: %d", systemTime) < 0) {
            return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
    }
    if (systemShutdown > 0 && systemShutdown < 0) {
        return EXIT_FAILURE;
    }
    tkp.Privileges[0].Attributes =0;
    AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES) NULL, 0);
    return EXIT_SUCCESS;
}
int main(void) {
    if (puts("Starting shutdown.") == EOF) {
        return EXIT_FAILURE;
        //In the event put reaches the end of file 1 will be returned
    }
    //Operations begin
    int returnCalulation = 0;
    int twoHours = 2;
    //const hourConvert = 2; //Value does not change. It eventually will;
    //const int instantShutdown = 0; //Testing the program in a W10 Virtual Machine
    int testSeconds = 1; //Testing the program in a W10 Virtual Machine
    convertHours(twoHours, &returnCalulation);
    if (printf("2 hours in seconds is %d", returnCalulation) < 0) {
        return EXIT_FAILURE;
    }
    if (winShutdown(testSeconds) > 0) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

