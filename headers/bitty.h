#include <bitset>

#define TEMPLATE template <typename Datatype>

TEMPLATE
std::bitset<8> _8bit(Datatype value){       // 1 byte
    return std::bitset<8>(value);
}

TEMPLATE
std::bitset<16> _16bit(Datatype value){     // 2 bytes
    return std::bitset<16>(value);
}

TEMPLATE
std::bitset<32> _32bit(Datatype value){     // 4 bytes
    return std::bitset<32>(value);
}

TEMPLATE
std::bitset<64> _64bit(Datatype value){     // 8 bytes
    return std::bitset<64>(value);
}