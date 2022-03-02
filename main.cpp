#include "timeout.h"

int main() {
    timeout hello;
    hello.printWelcome();

    timeConversion instance;
    instance.setValue(1);
    instance.convert();
    instance.shutdown();
    return 0;
}
