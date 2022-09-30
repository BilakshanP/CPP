#include "print.h"

int main () {
    int fib[] = {0, 1};

    for(int i{0}; i < 30; i++){
        fib[2] = fib[0] + fib[1];
        print(fib[2]);
        fib[0] = fib[1];
        fib[1] = fib[2];
    }
    return 0;
}