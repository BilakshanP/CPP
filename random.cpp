#include <cstdlib>
#include <iostream>
#include <time.h>
#include <math.h>

int main(){
    unsigned int seed = time(0);

    srand(seed*pow((-1), seed%2)); // to increase the range of possibilities
    
    for(int i{0}; i < 5; i++){
        std::cout << rand() << " ";
    }

    std::cout << "\n";

    return 0;
}