/* Exercise 7.6: Selection sort
   William Ngeow, May 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000
#define MAX 10

void int_swap(int *p1, int *p2); 

int
main(int argc, char *argv[]) {
	int i, j, next, n=0, A[SIZE], excess=0, max=0, m, max_post; 

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
	
	m = n; 
	for (j=0; j<n; j++) { 
	    for (i=0; i<m; i++) { 
		    /* determines max */
		    if (max < A[i]) {
		        max = A[i];
		        max_post = i; 
		    } 

		}
		
		max = 0;   
		/* swap A[i] to correct position */ 
		int_swap(&A[max_post], &A[m-1]);
		m--;
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
