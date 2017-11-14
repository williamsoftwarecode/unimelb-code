/* Exercise 5.14: Calculates the number of times that you can take the 
		  logarithm of its argument before getting a value less than one
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

int log_star(int base, double n); 

int
main(int argc, char *argv[]) {
	int base;
	double n; 

	/* read the value */
	printf("Enter a base for logarithm: ");
	if (scanf("%d", &base) != 1) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}
	
	printf("Enter argument: ");
	if (scanf("%lf", &n) != 1) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}
	
	printf("\n"); 
	
	/* print output */
	printf("log* for %f when the base for logarithm is %d is %d", n, base, log_star(base,n));

	/* job done */
	return 0;
}

int 
log_star(int base, double n) {
	int logstar = 0;
	double balance; 
	balance = n; 
	
	while (balance >= 1) {
		printf("Application #%d	=> log(%f)=", logstar+1, balance);
		balance = log(balance)/log(base);
		logstar++; 
		printf("%f\n", balance); 
	}
	return logstar;
}
	
