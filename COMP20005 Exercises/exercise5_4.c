/* Exercise 5.4
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>

int n_choose_k(int n, int k); 
int factorial(int n); 

int
main(int argc, char *argv[]) {
	int n, k;

	/* read the value */
	printf("Enter n choose k: ");
	if (scanf("%d,%d", &n, &k) != 2) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* print output */
	printf("The value of %d choose %d is: %d\n", n, k, n_choose_k(n,k));

	/* job done */
	return 0;
}

int 
n_choose_k(int n, int k) { 
    return factorial(n)/(factorial(n-k)*factorial(k));
}
    
int 
factorial(int n) { 
    if (n==1) {
        return 1;
    } else {
        return n*factorial(n-1); 
    }
}

