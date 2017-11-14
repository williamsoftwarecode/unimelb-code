/* Exercise 4.7
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int
main(int argc, char *argv[]) {
	int ch, n_lines=0, n_char=0, inaword, n_words=0, wcounter=0;

	/* read the value */
	printf("Enter text: \n");
	while ((ch=getchar()) != EOF) {
		if(ch >= 32 && ch <=126) {
		    n_char++; 
		} else if (ch=='\n') {
		    n_lines++; 
		}
		
		if((ch>=65 && ch<=90) || (ch>=97 && ch<=122)) {
		    inaword = 1; 
		} else { 
		    inaword = 0; 
		}
		
		if(wcounter != inaword) {
		    if (inaword) {
		        n_words++;
		    }
		    wcounter = inaword; 
		}
	}

	/* print output */
	printf("Lines:%7d\n", n_lines);
	printf("Chars:%7d\n", n_char); 
	printf("Words:%7d\n", n_words); 

	/* job done */
	return 0;
}
