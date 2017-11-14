/* Exercise 5.13
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>

int int_pow(int m, int n); 

int
main(int argc, char *argv[]) {
	int i, j;

	/* read the value */
	printf("Enter a value: ");
	if (scanf("%d,%d", &i, &j) != 2) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	printf("%d to the power of %d is: %d\n", i, j, int_pow(i,j));

	/* job done */
	return 0;
}

int 
int_pow(int m, int n) { 
    if(n==0) { 
        return 1; 
    } else {
        return m*int_pow(m,n-1); 
    }
}
