/* Exercise 5.1
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>

int max_2_ints(int i, int j); 

int
main(int argc, char *argv[]) {
	int i, j;

	/* read the value */
	printf("Enter two values (i,j): ");
	if (scanf("%d,%d", &i, &j) != 2) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	printf("The larger value is %d\n", max_2_ints(i,j)); 

	/* job done */
	return 0;
}

int 
max_2_ints(int i, int j) { 
    if(i>j) {
        return i; 
    } else { 
        return j;
    }
}
