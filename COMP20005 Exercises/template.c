/* Comment: What this program does
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
	int i;

	/* read the value */
	printf("Enter a value: ");
	if (scanf("%d", &i) != 1) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* compute */
	i = i+1;

	/* print output */
	printf("The computed value is: %d\n", i);

	/* job done */
	return 0;
}
