/* Exercise 5.8: returns true if the two argument values are either both exactly equal to zero,
		 or are 0.01% equal to each other. 
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

int near_equal(double x1, double x2);  

int
main(int argc, char *argv[]) {
	double i, j;

	/* read the value */
	printf("Enter two values (i,j): ");
	if (scanf("%lf,%lf", &i, &j) != 2) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* print output */
	if (near_equal(i,j)==1) {
		printf("True\n");
	} else {
		printf("False\n"); 
	}

	/* job done */
	return 0;
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
			
