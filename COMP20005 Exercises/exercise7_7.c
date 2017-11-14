/* Exercise 7.7
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define MAXVALS 10

int read_array(int A[], int maxvals); 
int maxfreq(int A[], int n); 

int
main(int argc, char *argv[]) {
	int A[SIZE], n;

	n = read_array(A,MAXVALS); 
	printf("The most frequent item is %d\n",
		maxfreq(A, n));
	
	/* job done */
	return 0;
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

int 
maxfreq(int A[], int n) {
    int i, j, maxfreq=0, freq=0, value;
    if (n==0) {
        exit(EXIT_FAILURE); 
    }
    
    for(i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if(A[i]==A[j]) {
                freq++;
            }
        }
        if (maxfreq<freq || (maxfreq==freq && A[i]<value)) {
            maxfreq=freq;
            value=A[i]; 
        }
        freq=0;
    }
    return value;
}
