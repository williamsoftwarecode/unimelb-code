/* Exercise 7.3: Modify the program of Figure 7.3 on page 104 so that 
	after the array has been sorted only the distinct values are 
	retained in the array (with variable n suitably reduced)
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000
#define MAX 1000

void int_swap(int *p1, int *p2); 
void shiftleft(int A[], int i, int n); 

int
main(int argc, char *argv[]) {
	int i, j, next, n=0, A[SIZE], excess=0; 

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
	
	printf("\nBefore :"); 
	for (i=0; i<n; i++) { 
		printf("%4d", A[i]); 
	} 
	
	/* assume that A[0] to A[n-1] have valid values */
	for (i=1; i<n; i++) { 
		/* swap A[i] left into correct position */ 
		for (j=i-1; j>=0 && A[j+1]<A[j]; j--) {
			/* not there yet */
			int_swap(&A[j], &A[j+1]); 
		}
	}
	
	/* discard duplicates */
	for (i=1; i<n; i++) {  
		while ((A[i-1]==A[i]) && i<n) { 
			shiftleft(A, i, n); 
			n--;
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

void 
shiftleft(int A[], int i, int n) {
	int j;
	for (j=i; j<n-1; j++) { 
		A[j] = A[j+1];
	}
}
