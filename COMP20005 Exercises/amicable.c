/* Exercise 5.5: Print perfect numbers
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

int isamicable(int n, int m); 
int nextamicable(int n);

int
main(int argc, char *argv[]) {
	int i, j; 
	printf("The amicable pairs between 1 and 3000 are: \n"); 
	
	for (i=1; i<=3000; i++) {
		for (j=1; j<=3000; j++) {
			if(isamicable(i,j)==1) {
				if (i!=j) {
					printf("%d and %d\n", i, j);
				}
			}
		}
	}
	
	/* job done */
	return 0;
}

int 
isamicable(int n, int m) { 
	int i, j, sumfactorsn=0, sumfactorsm=0; 
	
	for (i=1; i<n; i++) {
		if (n%i==0) {
			sumfactorsn += i;
		}
	}
	
	for (j=1; j<m; j++) {
		if (m%j==0) {
			sumfactorsm += j;
		}
	}
	
	if (sumfactorsn==m && sumfactorsm==n) {
		return 1; 
	} else {
		return 0; 
	}
}



		
		
