/* Calculates an approximate cube root for a double argument
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CUBE_LOWER 1e-6
#define CUBE_UPPER 1e6
#define CUBE_ITERATIONS 25

double cube_root(double v); 

int
main(int argc, char *argv[]) {
	double i;

	/* read the value */
	printf("Enter a value: ");
	if (scanf("%lf", &i) != 1) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}
	
	/* print output */
	printf("The cube root of %f value is: %f\n", i, cube_root(i));

	/* job done */
	return 0;
}

double 
cube_root(double v) { 
	double next=1.0; 
	int i; 
	if (fabs(v)<CUBE_LOWER || fabs(v)>CUBE_UPPER) {
		printf("Warning: cube root may be inaccurate\n"); 
	}
	for (i=0; i<CUBE_ITERATIONS; i++) { 
		next = (2*next + v/(next*next))/3; 
	}
	return next; 
}
