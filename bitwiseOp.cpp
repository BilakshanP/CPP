#include "bitty.h"
#include "headers/io.h"

template <typename Datatype>
void printBinary(Datatype Value){
    print(_16bit(Value));
}

int main(){
    int val1 = 782882, val2 = 662826;

    print(val1, " in binary is: ");
    printBinary(val1);

    print(val2, " in binary is: ");
    printBinary(val2);
    
    print("\n");

    print("1. and &:                ", "");
    print(val1&val2, "  and in binary is: ");
    printBinary(val1&val2);

    print("2. or |:                 ", "");
    print(val1|val2, "  and in binary is: ");
    printBinary(val1|val2);

    print("3. xor ^:                ", "");
    print(val1^val2, "  and in binary is: ");
    printBinary(val1^val2);

    print("4. complement ~ of val1: ", "");
    print(~val1, " and in binary is: ");
    printBinary(~val1);

    print("5. shift << 3:           ", "");
    print(val1 << 3, " and in binary is: ");
    printBinary(val1 << 3);

    print("6. shift >> 3:           ", "");
    print(val1 >> 3, "   and in binary is: ");
    printBinary(val1 >> 3);
}