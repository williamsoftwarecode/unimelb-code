/* Exercise 4.8
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
	int n, max, cycles, nmax, seed_max=0, cycles_max=0, seed; 
	
	printf("Enter nmax: "); 
	if (scanf("%d", &nmax) != 1) { 
	    printf("Error\n"); 
	    exit(EXIT_FAILURE); 
	}
	
	for (seed=1; seed<=nmax; seed++) { 
	
	    n=seed;
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
	    if (cycles_max<cycles) { 
	        cycles_max=cycles; 
	        seed_max=seed; 
	    }

	}
	
	}

	printf("Maximum of %d cycles consumed, with seed of %d\n", 
	    cycles_max, seed_max); 

	/* job done */
	return 0;
}
