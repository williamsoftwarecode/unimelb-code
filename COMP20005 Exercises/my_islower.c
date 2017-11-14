/* Exercise 5.7: my_islower checks if parameter c is an lowercase alphabetic letter.
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

int my_islower(char c); 

int
main(int argc, char *argv[]) {
	char c;

	/* read the value */
	printf("Enter an alphabet: ");
	if (scanf("%c", &c) != 1) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* print output */
	if (my_islower(c) == 1) {
		printf("%c is a lowercase alphabetical letter\n", c);
	} else { 
		printf("%c is not a lowercase alphabetical letter\n", c);
	}

	/* job done */
	return 0;
}

int
my_islower(char c) {
	if(c>=97 && c<=122) {
		return 1;
	} else {
		return 0; 
	}
}
