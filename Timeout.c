//cl /EHsc /sdl /W4 /TC Timeout.c
#include "Timeout.h"
void convertHours(int hour, int* returnCalulation) {
    int multiplyVal = 3600;
    int passedHour = hour;
    *returnCalulation = passedHour * multiplyVal;
    return;
}
int winShutdown(int systemTime) {
    printf("%d", systemTime);
    //typedef char* machineName, *LPSTR;
    char* machineName = NULL; //Current machine
    //typedef char* machineMessage, *LPSTR;
    char* machineMessage = NULL;
    //no message is required/to be displayed to the user since they know the PC's shutting down
    DWORD shutdownTime = systemTime;
    bool forceAppsClosed = false; //Displays box to close applications preventing dataloss
    bool restartImmediately = false; //Safely powers down the system & flushes the caches
    bool systemShutdown = InitiateSystemShutdownA(machineName, machineMessage, shutdownTime, forceAppsClosed, restartImmediately);
    //InitiateSystemShutdownA = bool value
    if (systemShutdown == 0) {
        if (printf("Shutting down Windows in %d", systemTime) < 0) {
            return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
    }
    return 0;
}
int main(void) {
    if (puts("Starting shutdown.") == EOF) {
        return EXIT_FAILURE;
        //In the event put reaches the end of file 1 will be returned
    }
    //Operations begin
    int returnCalulation = 0;
    //const hourConvert = 2; //Value does not change. It eventually will;
    const int instantShutdown = 0; //Testing the program in a W10 Virtual Machine
    convertHours(instantShutdown, &returnCalulation);
    if (printf("2 hours in seconds is %d", returnCalulation) < 0) {
        return EXIT_FAILURE;
    }
    if (printf("\nSystem is shutting down in: %d", returnCalulation) > 0) {
        return 1;
    }
    if (winShutdown(returnCalulation) > 0) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}