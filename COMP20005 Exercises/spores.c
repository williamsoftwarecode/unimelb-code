/* Exercise 4.3: Prints out the number of spores present at the end of each day
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SPORES 10000000

int
main(int argc, char *argv[]) {
	int day; 
	
	int
	spores(int day) { 
		if (day==1 || day==2) { 
			return 1; 
		} else {
			return spores(day-1) + spores(day-2); 
		}
	}
	
	day = 1; 
	printf("Day %5d - %8d spores\n", day, spores(day));

	day++; 
	printf("Day %5d - %8d spores\n", day, spores(day)); 
	
	for (day = 3; spores(day)<=MAX_SPORES; day++) { 
		printf("Day %5d - %8d spores\n", day, spores(day));  
	} 

	
	
	/* job done */
	return 0;
}
