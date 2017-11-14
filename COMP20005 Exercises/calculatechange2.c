/* Exercise 3.6: Reads an integer amount of cents between 0 and 99 
   and prints out the coins necessary to make up that amount of money
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define FIFTY 50
#define TWENTY 20
#define TEN 10
#define FIVE 5
#define TWO 2
#define ONE 1

int
main(int argc, char *argv[]) {
	int cents;

	/* read the value */
	printf("Enter amount in cents: ");
	if (scanf("%d", &cents) != 1) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	} else if (cents<0 || cents>99) {
		printf("Error: Amount in cents not between 0 and 99\n");
		exit(EXIT_FAILURE);
	}

	printf("The coins required to make %d cents are: \n", cents); 
	
	/* compute */
	if (cents>=FIFTY) {
		cents -= FIFTY; 
		printf("%d, ", FIFTY); 
	}

	if (cents>=TWENTY) {
		cents -= TWENTY; 
		printf("%d, ", TWENTY); 
	}
	
	if (cents>=TWENTY) {
		cents -= TWENTY; 
		printf("%d, ", TWENTY); 
	}
	
	if (cents>=TEN) {
		cents -= TEN; 
		printf("%d, ", TEN); 
	}
	
	if (cents>=FIVE) {
		cents -= FIVE; 
		printf("%d, ", FIVE); 
	}
	
	if (cents>=TWO) {
		cents -= TWO; 
		printf("%d, ", TWO); 
	}
	
	if (cents>=TWO) {
		cents -= TWO; 
		printf("%d, ", TWO); 
	}
	
	if (cents>=ONE) {
		cents -= ONE; 
		printf("%d, ", ONE); 
	}
	
	/* job done */
	return 0;
}
