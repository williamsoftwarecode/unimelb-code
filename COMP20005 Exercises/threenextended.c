/* Exercise 4.8

   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define PERLINE 8

int
main(int argc, char *argv[]) {
	int i, seed, max, n, cycles, nmax, longestcycle=0;

	/* read the value */
	printf("Enter nmax: ");
	if (scanf("%d", &nmax) != 1) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* compute */
	
	for (i=2; i<=nmax; i++) {
		n=i; 
		max = n; 
		cycles = 0; 
		while (n>1) {
			if (n%2==0) { 
				n = n/2; 
			} else { 
				n = 3*n+1; 
			} 	
			if (n>max) { 
				max = n; 
			}
			cycles += 1; 
		}
		
		if (cycles>longestcycle) {
			longestcycle=cycles;
			seed = i;
		}
	}
	
		n = seed;
		max = n; 
		cycles = 0; 
		while (n>1) {
			printf("%5d ", n); 
			if (n%2==0) { 
				n = n/2; 
			} else { 
				n = 3*n+1; 
			} 	
			if (n>max) { 
				max = n; 
			}
			cycles += 1; 
			if (cycles%PERLINE == 0) { 
				printf("\n"); 
			}
		}
	
	/* print output */
	printf("\nSeed of longest cycle generated is %d\n%d cycles consumed, maximum was %d\n", seed, cycles, max);

	/* job done */
	return 0;
}
