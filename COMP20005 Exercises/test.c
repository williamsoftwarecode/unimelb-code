/* Exercise 5.7: my_isupper checks if parameter c is an uppercase alphabetic letter.
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

int my_isupper(int c); 

int
main(int argc, char *argv[]) {
	int c;

	/* read the value */
	printf("Enter an alphabet: ");
	if (scanf("%d", &c) != 1) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* print output */
	if (my_isupper(c) == 1) {
		printf("%c is an uppercase alphabetical letter\n", c);
	} else { 
		printf("%c is not an uppercase alphabetical letter\n", c);
	}

	/* job done */
	return 0;
}

int
my_isupper(int c) {
	if(c>=65 && c<=90) {
		return 1;
	} else {
		return 0; 
	}
}
