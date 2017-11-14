/* Exercise 7.2: Modify the program of Figure 7.3 on page 104 so that the 
	array of values is sorted into decreasing order
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000
#define MAX 10

void int_swap(int *p1, int *p2); 

int
main(int argc, char *argv[]) {
	int i, j, next, n=0, A[SIZE], excess=0; 

	/* read the value */
	printf("Enter as many as 10 values, ^D to end\n");
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
	printf("\nBefore :"); 
	for (i=0; i<n; i++) { 
		printf("%4d", A[i]); 
	} 
	
	/* assume that A[0] to A[n-1] have valid values */
	for (i=1; i<n; i++) { 
		/* swap A[i] left into correct position */ 
		for (j=i-1; j>=0 && A[j+1]>A[j]; j--) {
			/* not there yet */
			int_swap(&A[j], &A[j+1]); 
		}
	}
	
	printf("\nAfter  :"); 
	for (i=0; i<n; i++) { 
		printf("%4d", A[i]); 
	} 

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
