/* Exercise 2.8
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
	double F, C;
	

	/* read the value */
	printf("Enter temperature in degrees Fahrenheit: ");
	if (scanf("%lf", &F) != 1) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* compute */
	C = (F-32)*5.0/9; 

	/* print output */
	printf("%f degrees Fahrenheit is %f degrees Celcius\n", F, C);

	/* job done */
	return 0;
}
