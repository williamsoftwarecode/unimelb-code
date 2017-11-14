/*  Exercise 8.3: Returns length of the perimeter of polygon P 
    represented in format 
    
    William Ngeow, May 2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

typedef struct { 
    double x;
    double y; 
} vertex_t; 

typedef struct { 
    vertex_t polygon[MAX];
    int n_vertices;
} poly_t;

double distance(vertex_t p1, vertex_t p2); 

int
main(int argc, char *argv[]) {
    double next1, next2, tot_dist=0; 
    int i=0; 
    poly_t P; 
    
    P.n_vertices = 0;
    
	/* read the value */
	printf("Enter coordinates of vertices (x,y): "); 
	while(scanf("%lf,%lf", &next1, &next2) == 2) {
	    
	    if (P.n_vertices > MAX) {
	        printf("The polygon has more than 100 vertices\n"); 
	        break;
	    }
	    
	    P.polygon[P.n_vertices].x = next1; 
	    P.polygon[P.n_vertices].y = next2;  
	    P.n_vertices++; 
	}
	
	for(i=0; i<P.n_vertices-1; i++) {
	    tot_dist+=distance(P.polygon[i], P.polygon[i+1]); 
	}
	
	/* print output */
	printf("The perimeter of polygon P is: %.3f\n", tot_dist);
	
	/* job done */
	return 0;
}

double 
distance(vertex_t p1, vertex_t p2) {  
    double x=(pow((p1.x-p2.x),2)); 
    double y=(pow((p1.y-p2.y),2));
    return sqrt(x+y);
}



