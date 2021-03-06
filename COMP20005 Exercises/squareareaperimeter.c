/* Comment: Exercise 2.3: Program calculates area of square, perimeter of square, area of circle and perimeter of circle
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592654

int
main(int argc, char *argv[]) {
	double r, area, perimeter, elapsed_hours;
	int start_hour, start_min, start_sec, finish_hour, finish_min, finish_sec; 

	/* read the value of r */
	printf("Enter a value: ");
	if (scanf("%lf", &r) != 1) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* compute */
	area = r*r; 
	perimeter = 4*r; 

	/* print output */
	printf("The area of square is %f and perimeter of square is %f for r = %f\n", area, perimeter, r);

	/* job done */
	return 0;
}
