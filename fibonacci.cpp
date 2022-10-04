#include "headers/io.h"

int *fibonacci(int number){
    static int fib[64] = {1, 1, 0};
    for(int i{0}; i < number-2; i++){
        fib[2+i] = fib[1+i] + fib[i];
    }

    return fib;
}

int main(){
    int upto{32};
    int *fib = fibonacci(upto);

    for(int i{0}; i < upto; i++){
        print(i+1, " ");
        print(*(fib+i));
    }

    return 0;
}