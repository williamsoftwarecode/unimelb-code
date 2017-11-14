/* Exercise 7.5: Suppose that a set of "student number, mark" pairs are
provided, one pair of numbers per line, with the lines in no particular order. 
This program reads this data and outputs the same data, but ordered by 
student number. 
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE_STUNUM 1000
#define SIZE_MARKS 1000
#define MAX 1000

void int_swap(int *p1, int *p2);  
void print_array(int A[], int B[], int n); 

int
main(int argc, char *argv[]) {
	int stunum[SIZE_STUNUM], marks[SIZE_MARKS], next1, next2, n=0, i, j;

	/* reads student number and corresponding marks */
	while (scanf("%d  %d", &next1, &next2) == 2) {
		if (n == MAX) { 
		} else { 
		    stunum[n] = next1;
		    marks[n] = next2; 
		    n++;
		}
	}

	/* sorts in correct order */
	/* assume that A[0] to A[n-1] have valid values */
	for (i=1; i<n; i++) { 
		/* swap A[i] left into correct position */ 
		for (j=i-1; j>=0 && stunum[j+1]<stunum[j]; j--) {
			/* not there yet */
			int_swap(&stunum[j], &stunum[j+1]); 
			int_swap(&marks[j], &marks[j+1]); 
		}
	}

	/* print output */
	print_array(stunum, marks, n); 

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
print_array(int A[], int B[], int n) {
    int i;
    for (i=0; i<n; i++) {
        printf("%d %3d\n", A[i], B[i]);
    }
}
