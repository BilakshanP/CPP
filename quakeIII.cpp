#include "headers/io.h"
#include <math.h>

float invsqrt(float number){
	long i;
	float x2{number*0.5F}, y{number};
	const float threehalfs = 1.5F;	   // F == float

	i  = *(long *) &y;                 /* making address of y as a long and then
	                                      copying its contents to an actual long */

	//i  = 0x5f3759df - ( i >> 1 );    // 1597463007 is 0x5f3759df in Hex 
	i  = 1597463007 - (i >> 1);        // happens to be the accumulated error

	y  = *(float *) &i;
	y  = y*(threehalfs-(x2*y*y));   // 1st iteration, Newtonian Approximation
    y  = y*(threehalfs-(x2*y*y));   // 2nd iteration, this could be removed
    y  = y*(threehalfs-(x2*y*y));   // 3rd iteration, this should be removed
	                                // It yields same result as 1/sqrt(number)

	return y;
}

int main(){
    print(invsqrt(999));
    print(1/sqrt(999));

	return 0;
}