/* Exercise 6.8
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>

void int_divide(int numerator, int denominator, int *quotient, int *remainder); 

int
main(int argc, char *argv[]) {
	int i, j, q, r;

	/* read the value */
	printf("Enter a numerator and denominator: ");
	if (scanf("%d,%d", &i, &j) != 2) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	int_divide(i,j,&q,&r); 
	
	/* print output */
	printf("Quotient: %d\nRemainder: %d", q, r);

	/* job done */
	return 0;
}

void 
int_divide(int numerator, int denominator, int *quotient, int *remainder) {
    *remainder = numerator%denominator; 
    *quotient = (numerator-*remainder)/denominator; 
}
