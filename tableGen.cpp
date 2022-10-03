#include "headers/io.h"

int main(){
    int number, upto{10};

    number = int_in("Enter the number to find table of: ");
    upto   = int_in("Enter number to find table upto: ");

    for(int i{1}; i < upto+1; i++){
        print(number, " x ");
        print(i, " = ");
        print(number*i);
    }
}