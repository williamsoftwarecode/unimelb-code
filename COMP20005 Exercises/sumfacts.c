/* Exercise 1 in ch04 slides: Sum of factors from 1 to 100
   Alistair Moffat, March 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int
main(int argc, char *argv[]) {
	int n, d;
	int sum;

	/* process numbers one by one */
	for (n=1; n<=MAX; n++) {
		sum = 0;
		/* check all factors */
		for (d=1; d<n; d++) {
			if (n%d == 0) {
				/* aha, d is a factor */
				sum += d;
			}
		}
		
		printf("The sum of the factors of %d is: %d\n",
			n, sum);
	}

	/* job done */
	return 0;
}
