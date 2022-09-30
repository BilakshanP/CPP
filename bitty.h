#include <iostream>
#include <bitset>

#define TEMPLATE template <typename Datatype>

TEMPLATE
std::bitset<8> _8bit(Datatype value){
    return std::bitset<8>(value);
}

TEMPLATE
std::bitset<16> _16Bit(){
    return std::bitset<16>(value);
}