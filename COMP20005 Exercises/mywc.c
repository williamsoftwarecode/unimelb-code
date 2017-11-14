/* Exercise 4.6: Counts the number of characters and lines in the input
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
	int text, num_char=0, num_lines=0;
	/* read the value */
	printf("Enter text: \n");
	
	while ((text = getchar()) != EOF) {
			
		if (text >= 32 && text <= 126) { 
			num_char+=1; 
		} 
		
		if (text == '\n') {
			num_lines+=1; 
		}	
	}

	/* print output */
	printf("Lines: %d\nChars: %d\n", num_lines, num_char);

	/* job done */
	return 0;
}
