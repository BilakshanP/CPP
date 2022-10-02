#include <iostream>

template <typename Datatype>
void print(Datatype value, const char* end="\n"){
    end ?: end = "\n";
    std::cout << value << end;
}

template <typename Datatype>
int int_in(Datatype value){
    int number;

    std::cout << value;
    std::cin >> number;

    return number;
}