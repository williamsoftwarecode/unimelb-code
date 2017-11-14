/* Exercise 5.8: Calculates an approximate cube root for a double argument
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CUBE_LOWER 1e-6
#define CUBE_UPPER 1e6

double cube_root(double v); 
int near_equal(double x1, double x2); 

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
	int n=0; 
	if (fabs(v)<CUBE_LOWER || fabs(v)>CUBE_UPPER) {
		printf("Warning: cube root may be inaccurate\n"); 
	}
	while (near_equal(next*next*next,v) == 0) { 
		next = (2*next + v/(next*next))/3; 
		printf("%f", next);
		n++; 
		printf("	%d\n", n);
	}
	return next; 
}

int
near_equal(double x1, double x2) {
	double small, big; 
	if (x1==x2) {
		return 1; 
	} else if (x1>x2) {
		big =x1; 
		small =x2; 
	} else {
		big =x2;
		small =x1; 
	}
	
	if (((big-small)/small)<=(0.01/100)) { 
		return 1; 
	} else {
		return 0; 
	}
}
			
