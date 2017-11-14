/* Comment: What this program does
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

int t_itr(int n); 
int t_rec(int n); 

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
	printf("%d\nt_itr = %d\nt_rec = %d\n", i, t_itr(i), t_rec(i));

	/* job done */
	return 0;
}

int
t_itr(int n) { 
	int sum, i; 
	sum = 0; 
	for (i=1; i<=n; i++) { 
		sum += i; 
	}
	return sum; 
}

int
t_rec(int n) { 
	if (n<0) {
		return 0;
	}
	if (n==0) { 
		return 0; 
	} else { 
		return n + t_rec(n-1); 
	}
}

