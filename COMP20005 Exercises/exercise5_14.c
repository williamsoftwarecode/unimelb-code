/* Exercise 5.14
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN 1

int log_star(double n, int base); 

int
main(int argc, char *argv[]) {
	int i, j;

	/* read the value */
	printf("Enter a value: ");
	if (scanf("%d,%d", &i, &j) != 2) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}
	
	/* print output */
	printf("log_star(%d) of base %d is: %d\n", i, j, log_star(i,j));

	/* job done */
	return 0;
}

int 
log_star(double n, int base) { 
    int n_itr=1; 
    while ((n=1.0*log(n)/log(base))>MIN) {
        n_itr++; 
    }
    return n_itr; 
}
