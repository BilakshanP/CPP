#include "headers/io.h"

int main(){
    const char          string1[]{"Test"};
    const long long int integer  {*(int * ) &string1};     // i = *(int *) &string1; if non-const
    const char          string2[]{*(char *) &integer};     // {integer} coz, of \0 output is diff

    print(integer);
    print(string2);     // prints TTest
}