/* Exercise 7.3
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define MAXVALS 10

int read_array(int A[], int maxvals); 
void sort_array(int A[], int n); 
void int_swap(int *p1, int *p2); 
void print_array(int A[], int n); 
void remove_duplicates(int A[], int *n); 

int
main(int argc, char *argv[]) {
	int A[SIZE], n;

	n = read_array(A,MAXVALS); 
	
	printf("Before:"); 
	print_array(A,n); 
	sort_array(A,n);
	remove_duplicates(A,&n);
	printf("After :"); 
	print_array(A,n); 

	/* job done */
	return 0;
}

void 
sort_array(int A[], int n) {
    int i, j;
    for (i=1; i<n; i++) {
        for (j=i-1; j>=0 && A[j+1]<A[j]; j--) {
            int_swap(&A[j],&A[j+1]);
        }
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
	printf("%d values read into array\n", n);
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

void 
remove_duplicates(int A[], int *n) {
    int i, j, n_dup=0;
    for (i=0; i<*n-1; i++) {
        if(A[i+1]==A[i]) { 
            for(j=i;j<*n; j++) {
                A[j+1]=A[j+2];
            }
            n_dup++; 
        }
    }
    *n -= n_dup;
}
