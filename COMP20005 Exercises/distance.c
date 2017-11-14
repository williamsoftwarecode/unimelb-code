/*  Exercise 8.2: Define a vector_t that could be used to store points in 
    two dimensions x and y (such as on a map). 
    
    The function double distance(vector_t p1, vector_t p2) returns the
    Euclidean distance between p1 and p2. If p1 = (x1,y1) and p2 = (x2, y2), 
    then the Euclidean distance between them is given by 
    sqrt((x1-x2)^2+(y1-y2)^2). 
    
    William Ngeow, May 2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 2

typedef struct { 
    double x;
    double y;
} vector_t; 

double distance(vector_t p1, vector_t p2); 

int
main(int argc, char *argv[]) {
	vector_t A, B;

	/* read the value */
	printf("Enter coordinates of p1 and p2 (x1,y1,x2,y2): "); 
	scanf("%lf,%lf,%lf,%lf", &A.x, &A.y, &B.x, &B.y); 
	
	/* print output */
	printf("The Euclidean distance is is: %.3f\n", distance(A, B));
	
	/* job done */
	return 0;
}

double 
distance(vector_t p1, vector_t p2) {  
    double x=(pow((p1.x-p2.x),2)); 
    double y=(pow((p1.y-p2.y),2));
    return sqrt(x+y);
}



