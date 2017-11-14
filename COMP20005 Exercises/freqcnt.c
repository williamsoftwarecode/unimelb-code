/* Exercise 7.3: Reads as many as 1000 integer values and counts the 
frequency of each value in the input
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000
#define MAX 1000

void int_swap(int *p1, int *p2); 

int
main(int argc, char *argv[]) {
	int i, j, next, n=0, A[SIZE], excess=0, new=0, first=0, nnum=0; 

	/* read the value */
	printf("Enter as many as 1000 values, ^D to end\n");
	while (scanf("%d", &next) == 1) {
		if (n >= MAX) { 
			excess++; 
		} else { 
			A[n] = next; 
			n++;
		}
	}
	
	printf("%d values read into array", n);
	if (excess) { 
		printf(", %d excess values discarded", excess); 
	}
	
	/* assume that A[0] to A[n-1] have valid values */
	for (i=1; i<n; i++) { 
		/* swap A[i] left into correct position */ 
		for (j=i-1; j>=0 && A[j+1]<A[j]; j--) {
			/* not there yet */
			int_swap(&A[j], &A[j+1]); 
		}
	}
	
	printf("\nValue    Freq\n");
	
	for (i=0; i<n-1; i++) {
	    if (first == 0) {
	        printf("%4d    ", A[i]); 
	        nnum=1;
	        first=1;
	    }
	    if ((A[i+1] != A[i])) { 
	        printf("%4d\n", nnum);
	        nnum=1;
	        new++; 
	        printf("%4d    ", A[i+1]);
	        first=1;       
	        } else {
	        nnum++;	  
	    }
	}
	
	printf("%4d\n", nnum);
	
	/* job done */
	return 0;
}

void 
int_swap(int *p1, int *p2) { 
	int tmp;
	tmp = *p1;
	*p1 = *p2; 
	*p2 = tmp; 
} 
