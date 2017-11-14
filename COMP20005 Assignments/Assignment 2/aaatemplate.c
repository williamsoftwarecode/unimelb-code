/* Comment: What this program does
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159
#define S_AREA_CONST 4*M_PI
#define TOWER_HEIGHT 8.25
#define SIZE 100
#define MAX_POLE 100
#define MAX_OTHERS 100

typedef struct {
	double x; 
	double y;
	double lumens; 
} point_t; 

typedef struct { 
	point_t point[SIZE]; 
	int n_poles; 
} pole_t; 

double distance(point_t p1, point_t p2); 
double illuminance(point_t point); 
void stage_one(pole_t P); 

int
main(int argc, char *argv[]) {
	int ch;
	pole_t P; 
	P.n_poles = 0; 
	
	while((ch=getchar()) != EOF) {
		
		/*if (ch!='P' || (ch!='L' && ch!='B')) {
			printf("Error: The input does not contain any P ");
			printf("lines, L lines or B lines\n");
		}*/
		
		if (ch=='P') {
			scanf("%lf %lf %lf \n", &P.point[P.n_poles].x, 
				&P.point[P.n_poles].y, 
				&P.point[P.n_poles].lumens); 
			P.n_poles++; 
		}	
	}
	
	stage_one(P); 

	/* job done */
	/* PROGRAMMING IS FUN! */
	return 0;
}

/* calculates distance between two points */ 
double 
distance(point_t p1, point_t p2) { 
	return sqrt(pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2)); 
}
	
/* calculates the illuminance of one light pole at the origin */
double 
illuminance(point_t point) {
	point_t origin; 
	double illuminance; 
	
	origin.x = 0; 
	origin.y = 0; 
	origin.lumens = 0; 
	
	illuminance = point.lumens/
	(S_AREA_CONST*(pow(TOWER_HEIGHT,2)+pow(distance(point, origin),2)));
	
	return illuminance; 
}

/* calculates the aggregate light intensity at the origin */ 
void 
stage_one(pole_t P) {
	int i=0;
	point_t origin; 
	
	origin.x = 0; 
	origin.y = 0; 
	origin.lumens = 0; 
	
	for(i=0; i<P.n_poles; i++) {
		origin.lumens+=illuminance(P.point[i]); 
	}
	
	printf("\n"); 
	printf("Stage 1\n");
	printf("=========\n");
	printf("Number of light poles: %d\n", P.n_poles);
	printf("Illuminance at (%2.1f,%2.1f): %2.2f lux\n", 
		origin.x, origin.y, origin.lumens);
}
		
	
