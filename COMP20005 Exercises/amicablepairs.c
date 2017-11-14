/* Exercise 5.6: Search and print amicable pairs
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define LOWER 1
#define UPPER 3000

int isamicable(int a, int b);

int
main(int argc, char *argv[]) {
	int i, j;
	printf("Amicable pairs between %d and %d are: \n", LOWER, UPPER);  
	
	for (i=LOWER; i<=UPPER; i++) {
		for (j=LOWER; j<=UPPER; j++) { 
			if (isamicable(i,j)==1) {
				/* print output */
				printf("%d and %d\n", i, j);
			}
		}
	}
	
	/* job done */
	return 0;
}

int 
isamicable(int a, int b) { 
	int i, sumfactsa=0, sumfactsb=0;
	
	for (i=1; i<a; i++) {
		if(a%i==0) {
			sumfactsa += i; 
		}
	}
	
	for (i=1; i<b; i++) {
		if(b%i==0) {
			sumfactsb += i; 
		}
	}
	
	if ((sumfactsa == b && sumfactsb == a) && (a != b)) {
		return 1; 
	} else {
		return 0; 
	}
}
