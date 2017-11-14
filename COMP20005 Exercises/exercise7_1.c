/* Exercise 7.1
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define MAXVALS 10

int read_array(int A[], int maxvals); 
int all_zero(int A[], int n); 

int
main(int argc, char *argv[]) {
	int A[SIZE], n;

	n = read_array(A,MAXVALS); 
	
	if(all_zero(A,n)) {
	        printf("All zero\n"); 
	} else {
	    printf("Have non-zero values\n"); 
	}

	/* job done */
	return 0;
}

int 
all_zero(int A[], int n) {
    int i; 
    for (i=0; i<n; i++) { 
        if (A[i]!=0) {
            return 0; 
        }
    }
    return 1; 
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
