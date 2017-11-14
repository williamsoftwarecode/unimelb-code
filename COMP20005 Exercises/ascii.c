/* Exercise 4.4: Generates a table of the printable ASCII character set
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define FIRST 32
#define LAST 126
#define PERROW 8

int
main(int argc, char *argv[]) {
	int c; 
	
	/* prints the first and second row for formatting */
	
	printf("         "); 
	for (c=0; c<PERROW; c++) {
		printf("  %+d", c); 
	}
	printf("\n        +"); 
	
	/* prints separator row */ 
	for (c=0; c<PERROW; c++) { 
		printf("----"); 
	}
	
		/* prints ASCII character set */ 
		for (c=FIRST; c<=LAST; c++) {
			
			if(c%PERROW==0) {
				printf("\n    %3d |", c);
			}
			printf("   %c", c);
		}
	
	/* job done */
	return 0;
}
