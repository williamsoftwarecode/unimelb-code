/* Exercise 5.6
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 3000

int sumfactor(int n);
int isamicable(int m, int n); 
void amicablepairs(void);

int
main(int argc, char *argv[]) {   
    amicablepairs();
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
isamicable(int m, int n) { 
    if ((m==sumfactor(n) && n==sumfactor(m)) && (m!=n)) {
        return 1; 
    } else { 
        return 0; 
    }
}

void 
amicablepairs(void) {
    int i, j;
    printf("Amicable pairs below %d: \n", MAX); 
    for (i=1; i<=MAX; i++) {
        for (j=1; j<=MAX; j++) {
            if(isamicable(i,j)) {
                printf("%d and %d\n", i, j);
            }
        }
    }
}
