/* Comment: This program reads a sequence of integers and draws a simple graph. 
   William Ngeow, March 2013
*/

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
	int number;
	int n;
	
	printf ("Enter numbers, press control-D to end: ");   
	
	n=1; 
	int i;
	
	/*read further values*/
	while(scanf("%d", &number)==1) {
		
		if(number<1||number>70) {
		printf("\nThe value is not between 1 and 70\n");
		exit(EXIT_FAILURE);}
		
		/* prints graph */
		printf("%d |", number); 
		for (i=0; i<number; i++){
		printf("*"); 
		}
		printf("\n");
	}
		
	/* job done */
	return 0;
}
