/* Exercise 4.7: Counts the number of characters, lines in the input
		 and number of words in the input stream
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
	int i, text, words=0, num_char=0, num_lines=0, num_words=0, inaword=0;
	
	/* read the value */
	printf("Enter text: \n");
	
	while ((text = getchar()) != EOF) {
		i = inaword; 
		if ((text >= 65 && text <= 90) || (text >= 97 && text <= 122)) { 
			inaword = 1;
		} else {
			inaword = 0; 	
		}
		
		words += (i-inaword)*(i-inaword);
		
		if (text >= 32 && text <= 126) { 
			num_char+=1; 
		} 
		
		if (text == '\n') {
			num_lines+=1; 
		}	
	}

	num_words = words/2;
	
	/* print output */
	printf("Lines: %d\nWords: %d\nChars: %d\n", num_lines, num_words, num_char);

	/* job done */
	return 0;
}
