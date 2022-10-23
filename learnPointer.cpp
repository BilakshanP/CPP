// What are pointers?

/*
            MEMORY
    address     values    c equivalent       english transcription

    0x1000      0x4       int x = 4;         integer named x is set to 4
    0x1004      0x1000    int *pX = &x;      integer pointer named pX is set to address of x   
    0x1008     
    0x100c     
    0x1010     
    0x1014     
    0x1018     
*/

#include <stdio.h>
#include "headers/io.h"

int main(){
    /*
    int x = 4;          // integer named x is set to 4
    int *pX = &x;       // integer pointer named pX is set to address of x  
    int y = *pX;        // integer named y is set to the thing pointed to by pX
    
    // int x = 4, *pX = &x, y = *pX;
    // value of/indirection/dereference operator is used to access value stored
    // at an address pointed by a pointer "*variable"

    printf("%d\n", *pX);

    *pX = 5;

    printf("%d\n", *pX); 

    // don't use * if pointer is not defined int *ptr; printf("%d", *ptr); *ptr = 6 it's dangerous
    // else segmentation fault is generated
    */

    // POINTER ARITMETIC

    int test[] {0, 2, 4, 6, 8};

    // p = p + j === &a[i + j]

    int *ptrT = &test[0];

    print(*(ptrT+3));

    // p = p + i === p = baseAdd + i ** sizeof(dataType)
}