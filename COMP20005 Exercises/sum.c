/* Comment: Calculates sum of input and gives the average (mean)
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
	int n;
	double sum, next;

	/* requests for input */ 
	printf("Enter the values to be added, control-D to end: "); 
	if (scanf("%lf", &next)!=1) {
		printf("Error: No input\n"); 
		exit(EXIT_FAILURE); 
	}
	
	sum = next;
	n=1; 
	while(scanf("%lf", &next)==1) {
		sum = sum + next;
		n++;
	}
	
	/* prints sum */
	printf("Sum of %d values is %f\n", n, sum); 	
	
	/* prints average (mean) */
	printf("Average (Mean) of %d values is %f", n, sum/n); 
	
	/* job done */
	return 0;
}
