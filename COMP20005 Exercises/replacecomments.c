/* Exercise 4.10: Replaces all // with "/ * and * /" pairs 
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
	
	int ch, incomment=0;
	
	while((ch=getchar()) != EOF) { 
		putchar(ch);
		if (ch == '/' && ch == '/') { 
			incomment =1;
			putchar('/');
			putchar('*');
			
			if (!incomment) {
			putchar(ch);
			}	
			
			if (ch == '\n') { 
				incomment = 0; 
				putchar('*');
				putchar('/');
			}
		} 
		
	}
	
	/* job done */
	return 0;
}
