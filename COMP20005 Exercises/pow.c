/* Exercise 5.3: Raises its first argument to the power of its second argument
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

int int_pow(int n, int m); 

int
main(int argc, char *argv[]) {
	int a, b;

	/* read the value */
	printf("Enter two arguments (a,b) \n");
	printf("(the first is the base and second is the power): ");
	if (scanf("%d,%d", &a, &b) != 2) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* print output */
	printf("%d to the power of %d is %d\n", a, b, int_pow(a,b));

	/* job done */
	return 0;
}

int
int_pow(int n, int m) {
	int i, out=1; 
	for (i=1; i<=m ;i++) {
		out *= n; 
	}
	return out;
}
