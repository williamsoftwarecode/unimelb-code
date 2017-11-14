/* Exercise 4.5
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int
main(int argc, char *argv[]) {
	int A[MAX], i=0, n, m;

	/* read the value */
	printf("Enter numbers: ");
	while((scanf("%d", &A[i])) == 1) { 
	    if(A[i]<0 || A[i]>70) {
	        printf("Error: Numbers are not between 1 and 70\n"); 
	        exit(EXIT_FAILURE); 
	    }
	    i++; 
	}
	
	for (n=0; n<i; n++) {
	    printf("%2d |", A[n]); 
	    for (m=1; m<=A[n]; m++) {
	        printf("*");
	    }
	    printf("\n"); 
	}
	
	/* job done */
	return 0;
}
