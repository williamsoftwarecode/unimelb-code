/* Exercise 3.7
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
	double value, C, F, K, M, G, P;
	char units; 

	/* read the value */
	printf("Enter a value with units: ");
	if (scanf("%lf %c", &value, &units) != 2) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* compute */
	if (units=='F') {
	    C = (value-32)*5.0/9; 
	    printf("The temperature %0.1fF converts to %0.1fC\n", value, C); 
	} else if (units=='C') {
	    F = (value*9.0/5)+32; 
	    printf("The temperature %0.1fC converts to %0.1fF\n", value, F); 
	} else if (units=='M') {
	    K = value*1.609; 
	    printf("The distance %0.1f miles converts to %0.1f kilometers\n", value, K); 
	} else if (units=='K') {
	    M = value/1.609;  
	    printf("The distance %0.1f kilometers converts to %0.1f miles\n", value, M); 
	} else if (units=='P') {
	    G = value*0.454; 
	    printf("The mass %0.1f pounds converts to %0.1f kilograms\n", value, G); 
	} else if (units=='G') {
	    P = value/0.454; 
	    printf("The mass %0.1f kilograms converts to %0.1f pounds\n", value, P); 
	} else {
	    printf("Unknown units\n"); 
	}

	/* job done */
	return 0;
}
