/* Exercise 5.1: Expects two int arguments and returns the larger of them
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

int max_2_ints(int a, int b); 

int
main(int argc, char *argv[]) {
	int a, b;

	/* read the value */
	printf("Enter two value (a,b): ");
	if (scanf("%d,%d", &a, &b) != 2) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* print output */
	printf("The larger value is: %d\n", max_2_ints(a,b));

	/* job done */
	return 0;
}

int
max_2_ints(int a, int b) {
	if (a>=b) {
		return a;
	} else {
		return b; 
	}
}
