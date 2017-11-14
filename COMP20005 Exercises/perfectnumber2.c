/* Exercise 5.9: Print perfect numbers
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

int isperfect(int n); 
int nextperfect(int n);

int
main(int argc, char *argv[]) {
	int i;

	printf("The perfect numbers from 1 to 1000000000 are: \n"); 
	
	for (i=1; i<1000000000; i++) {
		printf("%d\n", nextperfect(i));
		i = nextperfect(i);
	}
	
	/* job done */
	return 0;
}

