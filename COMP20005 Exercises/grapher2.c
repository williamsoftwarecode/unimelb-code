/* Exercise 4.5: Reads a sequence of integers and draws a simple graph. 
   Values read are between 1 and 70. 
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
	int i, n;

	/* read the value */
	printf("Enter numbers: ");
	while (scanf("%d", &i) == 1) {
		
		if(i<1 || i>70) {
			printf("Error: Value not between 1 and 70\n");
			exit(EXIT_FAILURE);
		}
		
		printf("%2d |", i);
		for (n=1; n<=i; n++) {
			printf("*"); 
		}
		printf("\n");
	}

	/* job done */
	return 0;
}
