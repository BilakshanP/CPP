#include "print.h"

// int fib[] = {0, 1};
// 
//     for(int i{0}; i < 30; i++){
//         fib[2] = fib[0] + fib[1];
//         print(fib[2]);
//         fib[0] = fib[1];
//         fib[1] = fib[2];
//     }


int *fibonacci(int number){
    static int fib[32] = {1, 1, 0};
    for(int i{0}; i < 32; i++){
        fib[2+i] = fib[1+i] + fib[i];
    };
    return fib;
}

int main(){
    int *fib = fibonacci(0);
    for(int i{0}; i < 32; i++){
        print(i, ""); print(*(fib+i));
    }
}