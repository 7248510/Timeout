//cl /EHsc /sdl /W4 /TC Timeout.c
#include "Timeout.h"
void convertHours(int hour, int *returnCalulation) {
    int multiplyVal = 3600;
    int passedHour = hour;
    *returnCalulation = passedHour * multiplyVal;
    return;
}
int main(void) {
    if (puts("Starting shutdown.") == EOF) {       
        return EXIT_FAILURE;
        //In the event put reaches the end of file 1 will be returned
    }
    //Operations begin
    int returnCalulation = 0;
    int hourConvert = 2; //Value does not change
    convertHours(hourConvert, &returnCalulation);
    if (printf("2 hours in seconds is %d", returnCalulation) < 0) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}