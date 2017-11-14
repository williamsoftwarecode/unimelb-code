/* Comment: What this program does
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define PERLINE 8

int
main(int argc, char *argv[]) {
	int max, n, cycles;

	/* read the value */
	printf("Enter starting value for n: ");
	if (scanf("%d", &n) != 1) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* compute */
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
	printf("\n%d cycles consumed, maximum was %d\n", cycles, max);

	/* job done */
	return 0;
}
