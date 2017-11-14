/* Exercise 7.9: Returns the number of runs present in the integer
array A of size n. 
   William Ngeow, May 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000
#define MAX 1000

int runs(int A[], int n); 

int
main(int argc, char *argv[]) {
	int i, next, n=0, A[SIZE], excess=0; 

	/* read the value */
	printf("Enter as many as %d values, ^D to end\n", MAX);
	while (scanf("%d", &next) == 1) {
		if (n == MAX) { 
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
	
	printf("\nNumber of runs: %d\n", runs(A, n)); 

	/* job done */
	return 0;
}

int 
runs(int A[], int n) {
    int i, runs=1; 
    
    for (i=0; i<n; i++) { 
        if (A[i+1] < A[i]) { 
            runs++;
        }
    }
	return runs; 
}
		

