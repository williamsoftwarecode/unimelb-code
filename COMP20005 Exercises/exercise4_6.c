/* Exercise 4.6
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int
main(int argc, char *argv[]) {
	int ch, n_lines=0, n_char=0;

	/* read the value */
	printf("Enter text: \n");
	while ((ch=getchar()) != EOF) {
		if(ch >= 32 && ch <=126) {
		    n_char++; 
		} else if (ch=='\n') {
		    n_lines++; 
		}
	}

	/* print output */
	printf("Lines:%7d\n", n_lines);
	printf("Chars:%7d\n", n_char); 

	/* job done */
	return 0;
}
