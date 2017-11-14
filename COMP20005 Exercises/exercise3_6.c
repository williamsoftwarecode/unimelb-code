/* Exercise 3.6
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>
#define FIFTY 50
#define TWENTY 20
#define TEN 10
#define FIVE 5
#define TWO 2
#define ONE 1
#define TYPES 7

int
main(int argc, char *argv[]) {
	int i, cents;
	int cents_type[TYPES] = {FIFTY, TWENTY, TEN, FIVE, TWO, ONE}; 

	/* read the value */
	printf("Enter amount in cents: ");
	if (scanf("%d", &cents) != 1) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}
	
	for (i=0; i<TYPES;) {
	    if (cents == 0) {
	        break;
	    }
	    if ((cents-cents_type[i])<0) {
	        i++; 
	    } else { 
	        cents -= cents_type[i]; 
	        if (i==0) {
	            printf("%d", cents_type[i]); 
	        } else { 
	            printf(", %d", cents_type[i]); 
	        }
	    }
	}
	
	/* job done */
	return 0;
}

