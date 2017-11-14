/* Exercise 7.6
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define MAXVALS 10

int read_array(int A[], int maxvals); 
void selection_sort(int A[], int n); 
void int_swap(int *p1, int *p2); 
void print_array(int A[], int n); 

int
main(int argc, char *argv[]) {
	int A[SIZE], n;

	n = read_array(A,MAXVALS); 
	
	printf("Before:"); 
	print_array(A,n); 
	selection_sort(A,n);
	printf("After :"); 
	print_array(A,n); 

	/* job done */
	return 0;
}

void 
selection_sort(int A[], int n) {
    int i, j, max_p, max=0;
    for (j=n; j>0; j--) {
        for (i=0; i<j; i++) {
            if(max<A[i]) {
                max=A[i]; 
                max_p=i;
            }
        }
        int_swap(&A[max_p],&A[j-1]);
        max=0;
    }
}

int 
read_array(int A[], int maxvals) {
    int n=0, next;
	printf("Enter values for array: ");
	while(scanf("%d", &next) == 1) {
	    if(n==maxvals) {
	    } else {
	        A[n] = next; 
	        n++; 
	    }
	}
	return n; 
}

void 
int_swap(int *p1, int *p2) {
    int tmp; 
    tmp = *p1;
    *p1 = *p2; 
    *p2 = tmp; 
}

void 
print_array(int A[], int n) { 
    int i;
    for (i=0; i<n; i++) {
        printf("%4d", A[i]);
    }
    printf("\n");
}
