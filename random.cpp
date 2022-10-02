#include <cstdlib>
#include <time.h>
#include <math.h>

#include "headers/io.h"

int main(){
    unsigned int seed = time(0);

    srand(seed*pow((-1), seed%2));      // to increase the range of possibilities
    
    for(int i{0}; i < 5; i++){
        print(rand(), " ");
    }

    print("");

    return 0;
}