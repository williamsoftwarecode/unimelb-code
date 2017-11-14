/* Comment: Print a table of numbers to show the effect of regular savings habits. 
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_YEARS 7
#define MONTHLY 100
#define MIN_RATE 2
#define MAX_RATE 7

int
main(int argc, char *argv[]) {
	int month, rate, year;
	double balance, monthly_rate; 
	
	/* print the table heading lines */ 
	printf("Monthly savings of $%d, with monthly compounded interest\n", MONTHLY); 
	printf("Annual Rate   |"); 
	
	for(rate=MIN_RATE; rate<=MAX_RATE; rate++) {
		printf("%3d%%   ", rate); 
	}
	printf("\n"); 

	/* rows of table, one by one */
	for(year=1; year<=MAX_YEARS; year++) { 
		printf("After %d years |", year); 
		for(rate=MIN_RATE; rate<=MAX_RATE; rate++) {
			balance = 0.0; 
			monthly_rate = 1.00 + ((rate/100.00)/12); 
			for(month=1; month<=12*year; month++) { 
				balance *= monthly_rate; 
				balance += MONTHLY; 
			}
			printf("%5.0f  ", balance); 
		}
		printf("\n"); 
	}
	
	/* job done */
	return 0;
}
