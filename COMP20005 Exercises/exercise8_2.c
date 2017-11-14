/* Exercise 8.2
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} vector_t; 

double distance(vector_t p1, vector_t p2); 
double square(double value); 

int
main(int argc, char *argv[]) {
	vector_t p1, p2; 

	/* read the value */
	printf("Enter two pairs of coordinates (x1,y1),(x2,y2): ");
	if (scanf("%lf,%lf,%lf,%lf", &p1.x, &p1.y, &p2.x, &p2.y) != 4) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	printf("The Euclidean distance is: %f\n", distance(p1,p2));

	/* job done */
	return 0;
}

double 
distance(vector_t p1, vector_t p2) {
    return sqrt(square(p1.x-p2.x)+square(p1.y-p2.y)); 
}
        
double 
square(double value) {
    return value*value; 
}
