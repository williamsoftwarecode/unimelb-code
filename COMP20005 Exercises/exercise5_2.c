/* Exercise 5.2
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>

int max_2_ints(int i, int j); 
int max_4_ints(int i, int j, int k, int l); 

int
main(int argc, char *argv[]) {
	int i, j, k, l;

	/* read the value */
	printf("Enter four values (i,j,k,l): ");
	if (scanf("%d,%d,%d,%d", &i, &j, &k, &l) != 4) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	printf("The larger value is %d\n", max_4_ints(i,j,k,l)); 

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

int 
max_4_ints(int i, int j, int k, int l) { 
    return max_2_ints(max_2_ints(i,j), max_2_ints(k,l)); 
}
