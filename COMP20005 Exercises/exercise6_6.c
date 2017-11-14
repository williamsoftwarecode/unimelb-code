/* Exercise 6.6
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>

void int_sort2(int *p1, int *p2); 
void int_sort3(int *p1, int *p2, int *p3); 

int
main(int argc, char *argv[]) {
	int i, j, k;

	/* read the value */
	printf("Enter three values: ");
	if (scanf("%d,%d,%d", &i, &j, &k) != 3) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}
	
	int_sort3(&i,&j,&k); 
	
	/* print output */
	printf("The correct sequence is: %d, %d, %d\n", i, j, k);

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

void 
int_sort3(int *p1, int *p2, int *p3) {
    int_sort2(p1, p2); 
    int_sort2(p1, p3);
    int_sort2(p2, p3);
}

