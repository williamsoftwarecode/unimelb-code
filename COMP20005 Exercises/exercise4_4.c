/* Exercise 4.4
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define FIRST 32
#define LAST 126
#define PERLINE 8

int
main(int argc, char *argv[]) {
	int i;
	
	printf("\n       +0  +1  +2  +3  +4  +5  +6  +7\n");
	printf("    +--------------------------------"); 
	
	for (i=FIRST; i<=LAST; i++) {
	    if(i%PERLINE==0) { 
	        printf("\n%3d |", i); 
	    }
	    printf("   %c", i); 
	}
	printf("\n"); 
	/* job done */
	return 0;
}
