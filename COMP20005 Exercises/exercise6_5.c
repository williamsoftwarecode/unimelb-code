/* Exercise 6.5
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>

void int_sort2(int *p1, int *p2); 

int
main(int argc, char *argv[]) {
	int i, j;

	/* read the value */
	printf("Enter two values: ");
	if (scanf("%d,%d", &i, &j) != 2) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}
	
	int_sort2(&i,&j); 
	
	/* print output */
	printf("The correct sequence is: %d, %d\n", i, j);

	/* job done */
	return 0;
}

void 
int_sort2(int *p1, int *p2) {
    int tmp; 
    if (*p1>*p2) {
        tmp=*p1; 
        *p1=*p2; 
        *p2=tmp; 
    } 
}
