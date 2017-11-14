/* Exercise 5.5: Find perfect numbers
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

int isperfect(int n); 
int nextperfect(int n); 

int
main(int argc, char *argv[]) {
	int j;

	/* print output */
	for (j=1; j<=100000000; j++) {
		printf("The next perfect number is: %d\n", nextperfect(j));
		j = nextperfect(j); 
	}
	/* job done */
	return 0;
}

int 
isperfect(int n) {
	int i, sumfacts=0;
	for (i=1; i<n; i++) {
		if (n%i==0) {
			sumfacts += i;
		}
	}
	if (sumfacts == n) {
		return 1;
	} else { 
		return 0; 
	}
}

int
nextperfect(int n) { 
	n++;
	while (isperfect(n)==0) { 
		n++;
	}
	return n; 
}
	
	
	
	
