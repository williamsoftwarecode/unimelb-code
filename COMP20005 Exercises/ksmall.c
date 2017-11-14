/* Exercise 7.8: Takes an integer array A and an integer n that indicates
how many elements of A may be accessed and an integer k; and returns the 
value of the k'th smallest integer in A. 
   William Ngeow, May 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000
#define MAX 1000

int ksmall(int A[], int n, int k); 
void int_swap(int *p1, int *p2); 

int
main(int argc, char *argv[]) {
	int i, k, next, n=0, A[SIZE], excess=0; 
	
	printf("Enter the the value of k: "); 
	if (scanf("%d", &k) != 1) {
	    printf("Error: k must be an integer\n"); 
	    exit(EXIT_FAILURE); 
	}

	/* read the value */
	printf("Enter as many as %d values, ^D to end\n", MAX);
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
	printf("\nArray :"); 
	for (i=0; i<n; i++) { 
		printf("%4d", A[i]); 
	} 
	
	printf("\nValue of the %d'th smallest value: %d\n", k, ksmall(A, n, k)); 

	/* job done */
	return 0;
}

int 
ksmall(int B[], int n, int k) {
    int A[SIZE], i, j; 
    
    for (i=0; i<n; i++) { 
        A[i] = B[i]; 
    }
    
    /* assume that A[0] to A[n-1] have valid values */
	for (i=1; i<n; i++) { 
		/* swap A[i] left into correct position */ 
		for (j=i-1; j>=0 && A[j+1]>A[j]; j--) {
			/* not there yet */
			int_swap(&A[j], &A[j+1]); 
		}
	}
    
	return A[k-1]; 
}
		

void 
int_swap(int *p1, int *p2) { 
	int tmp;
	tmp = *p1;
	*p1 = *p2; 
	*p2 = tmp; 
} 
