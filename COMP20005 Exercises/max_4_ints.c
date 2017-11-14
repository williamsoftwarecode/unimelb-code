/* Exercise 5.2: Returns larger of four integers
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

int max_2_ints(int n,int m); 

int
main(int argc, char *argv[]) {
	int a, b, c, d, max_4_ints;
	
	/* read the value */
	printf("Enter four value (a,b,c,d): ");
	if (scanf("%d,%d,%d,%d", &a, &b, &c, &d) != 4) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* compute */ 
	max_4_ints = max_2_ints(max_2_ints(a,b),max_2_ints(c,d));
	printf("The larger integer is %d\n", max_4_ints); 
	
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
