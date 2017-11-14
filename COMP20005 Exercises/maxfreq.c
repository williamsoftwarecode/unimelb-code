/* Exercise 7.7: Takes an integer array A and an integer n that indicates
how many elements of A may be accessed and returns the value of the 
integer A that appears most frequently. 
   William Ngeow, May 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000
#define MAX 10

int maxfreq(int A[], int n, int *freq); 
void int_swap(int *p1, int *p2); 

int
main(int argc, char *argv[]) {
	int i, next, n=0, A[SIZE], excess=0, freq=0; 

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
	printf("\nArray :"); 
	for (i=0; i<n; i++) { 
		printf("%4d", A[i]); 
	} 
	
	printf("\nValue in A of highest frequency: %d\n", maxfreq(A, n, &freq)); 
	printf("Frequency: %d\n", freq);

	/* job done */
	return 0;
}

int 
maxfreq(int A[], int n, int *freq) {
    int i, j, next=0, max=0, nextfreq=0, maxfreq=0; 
    
    for (j=0; j<n; j++) {
        
        next = A[j];
        nextfreq = 0;
        for (i=0; i<n; i++) {
            if (next == A[i]) {
                nextfreq++;
            }
        }
         
		/* compares next number with max number */ 
		if (maxfreq < nextfreq) {
		        maxfreq = nextfreq; 
		        max = next; 
		} else if ((maxfreq == nextfreq) && (max > next)) {
		    max = next;	
		}
		
		}
		*freq = maxfreq; 
	return max; 
}
		

void 
int_swap(int *p1, int *p2) { 
	int tmp;
	tmp = *p1;
	*p1 = *p2; 
	*p2 = tmp; 
} 
