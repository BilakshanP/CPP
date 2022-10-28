#include <iostream>

using ::std::cout;
using ::std::cin;

template <typename Datatype>
void print(Datatype value, const char* end="\n"){
    end ?: end = "\n";
    cout << value << end;
}

template <typename Datatype>
int int_in(Datatype value){
    int number;

    cout << value;
    cin >> number;

    return number;
}