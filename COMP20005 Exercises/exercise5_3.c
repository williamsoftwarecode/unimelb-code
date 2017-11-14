/* Exercise 5.3
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>

int int_pow(int arg, int pow); 

int
main(int argc, char *argv[]) {
	int i, j;

	/* read the value */
	printf("Enter a value raised to another value (i,j): ");
	if (scanf("%d, %d", &i, &j) != 2) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* print output */
	printf("%d to the power of %d is: %d\n", i, j, int_pow(i,j));

	/* job done */
	return 0;
}

int    
int_pow(int arg, int pow) { 
    int i, intpow=1;
    for (i=1; i<=pow; i++) {
        intpow*=arg; 
    }
    return intpow; 
}
