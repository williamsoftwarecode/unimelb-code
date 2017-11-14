/* Exercise 8.3
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 101

typedef struct {
    double x;
    double y;
} vector_t; 

typedef struct { 
    int n; 
    vector_t vertices[SIZE]; 
} poly_t; 

double distance(vector_t p1, vector_t p2); 
double square(double value); 
double perimeter(poly_t P); 
void read_polygon(poly_t* P); 

int
main(int argc, char *argv[]) {
	poly_t P; 

	read_polygon(&P);
	printf("The polygon has %d vertices\n", P.n);
	printf("The perimeter of the polygon is: %f\n", perimeter(P));

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

double 
perimeter(poly_t P) {
    int i; 
    double perimeter=0; 
    for(i=1; i<P.n; i++) {
        perimeter+=distance(P.vertices[i], P.vertices[i-1]); 
    }
    perimeter+=distance(P.vertices[P.n-1], P.vertices[0]);
    return perimeter; 
}

void 
read_polygon(poly_t* P) {
    (*P).n=0; 
    printf("Enter coordinates of vertices (maximum of %d): ", SIZE-1); 
    while(scanf("%lf,%lf", &(*P).vertices[(*P).n].x, &(*P).vertices[(*P).n].y) != EOF) {
        (*P).n++;
    }
}
