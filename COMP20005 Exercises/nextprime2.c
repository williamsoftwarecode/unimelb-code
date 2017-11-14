/* Exercise 4.9: Calculates the next prime after a given value
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

int isprime(int n); 

int
main(int argc, char *argv[]) {
	int n, prime_found, isprime, divisor;

	/* read the value */
	printf("Enter a value: ");
	if (scanf("%d", &n) != 1) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* compute */
	prime_found = 0; 
	while (!prime_found) {
		/* step to next number */
		n++;
		
		/* test to see if it is a prime number */
		isprime = 1; 
		for (divisor=2; divisor*divisor<=n; divisor++) { 
			if (n%divisor==0) { 
				isprime = 0;
				break; 
			}
		}
		
		/* if no factors are found, n is a prime number */ 
		prime_found = isprime;
	}

	if (isprime == 1) {
	printf("The next prime number is %d\n", n); 
	}
	
	/* job done */
	return 0;
}


		

