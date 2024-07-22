#include <stdio.h>
#include "stdout.h"
//conditional compilation to check if the code is being tested or not
#ifndef RUN_TEST 
int main() {
    print_hello();
    return 0;
}
#endif