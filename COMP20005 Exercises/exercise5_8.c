/* Exercise 5.8
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define MIN 0.0001

int near_equal(double x1, double x2); 

int
main(int argc, char *argv[]) {
	double i=0, j=0;

	/* read the value */
	printf("Enter two value: ");
	if (scanf("%lf,%lf", &i, &j) != 2) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	if(near_equal(i,j)) {
	    printf("%f and %f are near equal\n", i, j);
	} else {
	    printf("%f and %f are not near equal\n", i, j);
	}
	
	/* job done */
	return 0;
}

int 
near_equal(double x1, double x2) {
    int big, small;
    
    if(x1==x2) {
        return 1; 
    }
    
    if (x1<x2) {
        small=x1; 
        big=x2; 
    } else if (x2<x1) {
        small=x2; 
        big=x1; 
    }
    
    if (small==0) {
        small=FLT_EPSILON;
    }
     
    if(((big-small)/small)<=MIN) {
            return 1;
        } else {
            return 0;
        }
}
