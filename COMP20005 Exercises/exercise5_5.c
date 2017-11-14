/* Exercise 5.5
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100000000

int sumfactor(int n); 
int isperfect(int n); 
int nextperfect(int n); 

int
main(int argc, char *argv[]) {
	int i;

	/* read the value */
	printf("Enter a value: ");
	if (scanf("%d", &i) != 1) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* print output */
	printf("The next perfect integer after %d is: %d\n", i, nextperfect(i));

	/* job done */
	return 0;
}

int 
sumfactor(int n) {
    int i, sum=0; 
    for (i=1; i<n; i++) {
        if(n%i==0) {
            sum+=i;
        }
    }
    return sum; 
}

int 
isperfect(int n) {
    if(sumfactor(n)==n) {
        return 1; 
    } else { 
        return 0; 
    }
}

int 
nextperfect(int n) { 
    while(n<=MAX) {
        if(isperfect(n)==1) {
            return n;
        } 
        n++;
    }
    return 0;
}
        
