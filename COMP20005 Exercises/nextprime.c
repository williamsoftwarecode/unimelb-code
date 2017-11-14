/* Comment: This program calculates the next prime number after a given value. 
   William Ngeow, March 2013
*/

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
	int n;
	int divisor;
	int isprime;

	/* read the value */
	printf("Enter an integer value: ");
	if (scanf("%d", &n) != 1) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* calculate next prime number */
	
	while (isprime==0) {
	n ++;
	isprime=0; 
		for (divisor=2; divisor*divisor<=n; divisor++) {
			if (n%divisor==0) {
				isprime=0;
			} else {isprime=1;}
		}
	}
	
	if (isprime ==1) {
			/* print output */
			printf("The next prime is: %d\n", n);
		}
		else { printf("fail"); }
	/* job done */
	return 0;
}
