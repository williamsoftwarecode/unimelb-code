/* Exercise 2.3
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>
#define PI 3.141592654
#define SEC_PER_HOUR 3600
#define SEC_PER_MIN 60

int
main(int argc, char *argv[]) {
    double r, area, perimeter, elapsed_hour; 
	int start_hour, start_min, start_sec, finish_hour, finish_min, finish_sec;

	/* read the value */
	printf("Enter radius: ");
	if (scanf("%lf", &r) != 1) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}
	
	printf("Enter finish h,min,sec and start h,min,sec: ");
	if (scanf("%d,%d,%d,%d,%d,%d", &finish_hour, &finish_min, &finish_sec, &start_hour, &start_min, &start_sec) != 6) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* compute */
	area = r*r; 
	printf("Area of square: %f\n", area); 
	perimeter = 4.0*r; 
	printf("Perimeter of square: %f\n", perimeter); 
	area = PI*r*r; 
	printf("Area of circle: %f\n", area); 
	perimeter = 2.0*PI*r; 
	printf("Perimeter of circle: %f\n", perimeter); 
	
	elapsed_hour = 1.0*(finish_hour*SEC_PER_HOUR+finish_min*SEC_PER_MIN+finish_sec-start_hour*SEC_PER_HOUR-start_min*SEC_PER_MIN-start_sec)/3600;
	printf("Elapsed hours: %2.3f\n", elapsed_hour); 
	
	/* job done */
	return 0;
}
