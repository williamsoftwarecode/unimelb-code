/* Comment: What this program does
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592654

int
main(int argc, char *argv[]) {
	double radius;
	double volume;

	/* read the value of radius of sphere */
	printf("Enter the radius of sphere: ");
	if (scanf("%lf", &radius) != 1) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* compute volume of sphere */
	volume = (4.0/3.0)*PI*radius*radius*radius;

	/* print output */
	printf("The volume of sphere of radius %f is: %f\n", radius, volume);

	/* job done */
	return 0;
}
