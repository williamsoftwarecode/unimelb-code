/* Exercise 5.1: Expects two int arguments and returns the larger of them
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

int max_2_ints(int a, int b); 
int max_4_ints(int a, int b, int c, int d); 

int
main(int argc, char *argv[]) {
	int a, b, c, d;

	/* read the value */
	printf("Enter two value (a,b,c,d): ");
	if (scanf("%d,%d,%d,%d", &a, &b, &c, &d) != 4) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* print output */
	printf("The larger value is: %d\n", max_4_ints(a,b,c,d));

	/* job done */
	return 0;
}

int 
max_4_ints(int a, int b, int c, int d) {
	return max_2_ints(a,max_2_ints(b,max_2_ints(c,d)));
}

int
max_2_ints(int a, int b) {
	if (a>=b) {
		return a;
	} else {
		return b; 
	}
}
