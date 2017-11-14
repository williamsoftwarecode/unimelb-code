/* Exercise 5.1: Returns larger of two integers
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

int max_2_ints(int n,int m); 

int
main(int argc, char *argv[]) {
	int a, b;
	
	/* read the value */
	printf("Enter two value (a,b): ");
	if (scanf("%d,%d", &a, &b) != 2) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* compute */ 
	printf("The larger integer is %d\n", max_2_ints(a,b)); 
	
	/* job done */
	return 0;
}

int
max_2_ints(int n, int m) { 
	if (n>=m) {
		return n; 
	} else {
		return m;
	}
}
