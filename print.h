#include <iostream>

template <typename Datatype>
void print(Datatype value, const char* end="\n"){
    end ?: end = "\n";
    std::cout << value << end;
}