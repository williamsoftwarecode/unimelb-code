/* Exercise 7.4
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000
#define COLS 2
#define MAXVALS 1000

void read_array(int A[][COLS], int *n, int maxvals); 
void sort_array(int A[][COLS], int n); 
void int_swap(int *p1, int *p2); 
void print_array(int A[][COLS], int n); 

int
main(int argc, char *argv[]) {
	int A[SIZE][COLS], n;

	read_array(A, &n, MAXVALS); 
	sort_array(A,n);
	print_array(A, n);

	/* job done */
	return 0;
}

void 
sort_array(int A[][COLS], int n) {
    int i, j;
    for (i=1; i<n; i++) {
        for (j=i-1; j>=0 && A[j+1][0]<A[j][0]; j--) {
            int_swap(&A[j][0],&A[j+1][0]);
            int_swap(&A[j][1],&A[j+1][1]);
        }
    }
}

void 
read_array(int A[][COLS], int *n, int maxvals) {
    int n1=0, next1, next2;
	printf("Enter values for array: ");
	while(scanf("%d %d", &next1, &next2) == 2) {
	    if(n1==maxvals) {
	    } else {
	        A[n1][0] = next1;
	        A[n1][1] = next2;
	        n1++; 
	    }
	}
	printf("%d values read into array\n", n1);
	*n = n1; 
}

void 
int_swap(int *p1, int *p2) {
    int tmp; 
    tmp = *p1;
    *p1 = *p2; 
    *p2 = tmp; 
}

void 
print_array(int A[][COLS], int n) { 
    int i;
    for (i=0; i<n; i++) {
        printf("%6d", A[i][0]);
        printf("%4d", A[i][1]);
        printf("\n"); 
    }
}


