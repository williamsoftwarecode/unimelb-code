/* Exercise 5.4: Calculates the number of different ways of selecting a k item subset of n distinct items
		 given C = n!/((n-k)!*k!), where n! = 1*2*...(n-1)*n
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

int n_choose_k(int n, int k);
int fact(int n);

int
main(int argc, char *argv[]) {
	int n, k;

	/* read the value */
	printf("Enter (n,k): ");
	if (scanf("%d,%d", &n, &k) != 2) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* print output */
	printf("The number of different ways of selecting a %d item \n", k); 
	printf("subset of %d distinct items is: %d\n", n, n_choose_k(n,k));

	/* job done */
	return 0;
}

int
n_choose_k(int n, int k) {
	int C=0;
	C = ((fact(n))/((fact(n-k))*(fact(k)))); 
	return C; 
}


int fact(int n) {
	int lcv;    
	int p; 
	lcv = 2;
	for(p=1; lcv <= n; lcv++) {
		p=p*lcv;
	}
	return p;
}
