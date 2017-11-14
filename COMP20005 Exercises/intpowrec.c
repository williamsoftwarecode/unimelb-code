/* Exercise 5.13: Recursive function for Exercise 5.3
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

int int_pow(int a, int b); 

int
main(int argc, char *argv[]) {
	int a, b;

	/* read the value */
	printf("Enter a to the power of b (a,b): ");
	if (scanf("%d,%d", &a, &b) != 2) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* print output */
	printf("%d to the power of %d is: %d\n", a, b, int_pow(a,b));

	/* job done */
	return 0;
}

int 
int_pow(int a, int b) { 
	if (b==0) {
		return 1; 
	} else {
		return a*int_pow(a,b-1);
	}
}
		
