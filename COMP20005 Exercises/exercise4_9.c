/* Exercise 4.9
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
	int isprime=0, divisor, n, value;

	/* read the value */
	printf("Enter an integer value: ");
	if (scanf("%d", &value) != 1) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}
	n=value+1;
	while (isprime==0) {
	    n++;
	    isprime=1;
	    for (divisor=2; divisor*divisor<=n; divisor++) { 
	        if (n%divisor==0) { 
	            isprime=0;
	            break; 
	        }
	    }
    }
	
	printf("The next prime is     : %d\n", n); 
	
	/* job done */
	return 0;
}
