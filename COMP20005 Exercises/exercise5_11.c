/* Exercise 5.11
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>

double sum_sequence(int n); 
int factorial(int n); 
int sum(int n); 

int
main(int argc, char *argv[]) {
	int i;

	/* read the value */
	printf("Enter a value: ");
	if (scanf("%d", &i) != 1) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	printf("sum_sequence(%d): %f\n", i, sum_sequence(i));

	/* job done */
	return 0;
}

double 
sum_sequence(int n) {
    if (n==1) {
        return (1.0*sum(n))/factorial(n);
    } else {
        return (1.0*sum(n))/factorial(n)+sum_sequence(n-1);
    }
}

int 
factorial(int n) {
    if(n==1) {
        return 1; 
    } else { 
        return n*factorial(n-1);
    }
}

int 
sum(int n) { 
    if(n==1) {
        return 1; 
    } else { 
        return n+sum(n-1); 
    }
}
