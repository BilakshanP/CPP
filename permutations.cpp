#include <iostream>

// void a_multiply(auto value, int times){
//     for(int i{1}; i <= times; i++){
//         std::cout << value; 
//     }
// }

int main(){
    const char *str = "Hello";
    const int c = 1;
    const int *pconst = &c;
    const int c2 = 2;
    const int *const pconst2 = &c;
    std::cout << *pconst2 <<" "<< pconst2 << std::endl
              << *pconst  <<" "<< pconst;
}