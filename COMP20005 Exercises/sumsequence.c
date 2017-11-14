/* Exercise 5.11: Calculates and returns the sum
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

double sum_sequence(int n); 
int sum_int(int n);
int sum_multi(int n);

int
main(int argc, char *argv[]) {
	int i;

	/* read the value */
	printf("Enter a value: ");
	if (scanf("%d", &i) != 1) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* print output */
	printf("sum_sequence(%d): %f\n", i, sum_sequence(i));

	/* job done */
	return 0;
}

double 
sum_sequence(int n) {
	int i; 
	double sum=0.0; 
	for (i=1; i<=n; i++) {
		sum += 1.0*sum_int(i)/(1.0*sum_multi(i));
	}
	return sum;
}

int
sum_int(int n) {
	int i, sum=0; 
	for (i=1; i<=n; i++) {
		sum += i;
	}
	return sum;	
}

int 
sum_multi(int n) { 
	int i, sum=1; 
	for (i=1; i<=n; i++) {
		sum *= i;
	}
	return sum;
} 
