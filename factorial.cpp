#include "headers/io.h"

int looping_factorial(int number){
    int fact{1};

    for(int i{2}; i <= number; i++){
        fact *= i;
    }

    return fact;
}

int recursive_factorial(int n){
    if(n < 2){
        return 1;
    }
    return n * recursive_factorial(n-1);
}

int main(){
    int num;

    num = int_in("Enter a number to find factorial of: ");
    print("Factorial of ", "");

    print(num, " is: ");
    print("");

    print("    1. Recursive factorial: ", "");
    print(recursive_factorial(num));
    print("    2. Looping factorial: ", "");
    print(looping_factorial(num));

    return 0;
}