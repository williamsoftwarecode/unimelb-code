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
#define MIN_LUX 1.0

typedef struct {
	double x; 
	double y;
} point_t; 

typedef struct {
	point_t point; 
	double lumens; 
} source_t; 

typedef struct { 
	source_t source[SIZE]; 
	int n_poles; 
} pole_t; 

typedef struct { 
	point_t location[SIZE]; 
	int n_location; 
} location_t;

double distance(point_t p1, point_t p2); 
double illuminance(source_t point, point_t location); 
void stage_one(pole_t P); 
void stage_two(pole_t P, location_t L); 
/*void stage_three(pole_t P, location_t L);*/

int
main(int argc, char *argv[]) {
	int ch;
	pole_t P; 
	location_t L;
	P.n_poles = 0; 
	L.n_location = 0;
	
	while((ch=getchar()) != EOF) {
		
		/*if (ch!='P' || (ch!='L' && ch!='B')) {
			printf("Error: The input does not contain any P ");
			printf("lines, L lines or B lines\n");
		}*/
		
		if (ch=='P') {
			scanf("%lf %lf %lf \n", &P.source[P.n_poles].point.x, 
				&P.source[P.n_poles].point.y, 
				&P.source[P.n_poles].lumens); 
			P.n_poles++; 
		}
		
		if (ch=='L') {
			scanf("%lf %lf \n", &L.location[L.n_location].x, 
				&L.location[L.n_location].y); 
			L.n_location++;
		}
	}
	
	stage_one(P); 
	
	if (L.n_location) {
		stage_two(P,L);
	}

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
illuminance(source_t source, point_t location) {
	double illuminance; 
	
	illuminance = source.lumens/
	(S_AREA_CONST*(pow(TOWER_HEIGHT,2)+pow(distance(source.point, location),2)));
	
	return illuminance; 
}

/* calculates the aggregate light intensity at the origin */ 
void 
stage_one(pole_t P) {
	int i=0;
	double tot_illuminance=0; 
	point_t origin; 
	
	origin.x = 0; 
	origin.y = 0; 
	
	for(i=0; i<P.n_poles; i++) {
		tot_illuminance+=illuminance(P.source[i], origin); 
	}
	
	printf("\n"); 
	printf("Stage 1\n");
	printf("=========\n");
	printf("Number of light poles: %d\n", P.n_poles);
	printf("Illuminance at (%2.1f,%2.1f):  %2.2f lux\n", 
		origin.x, origin.y, tot_illuminance);
}
		
void 
stage_two(pole_t P, location_t L) { 
	
	int i=0, j=0;
	double tot_illuminance=0; 
	
	printf("\n");
	printf("Stage 2\n");
	printf("=========\n");
	
	for(i=0; i<L.n_location; i++) { 
		
		for(j=0; j<P.n_poles; j++) {
		tot_illuminance+=illuminance(P.source[j], L.location[i]); 
		}
		
		printf("Illuminance at (%2.1f,%2.1f):  %2.2f lux\n", 
			L.location[i].x, L.location[i].y, 
			tot_illuminance);
		tot_illuminance = 0;
	}
}

/*void 
stage_three(pole_t P, location_t L) {
	printf("With %d poles in use and %d points ", P.n_poles); 
	printf("sampled, %d points (%2.1f%)", ???, ??? ); 
	printf("\nhave illuminance below the %.1f lux acceptable level\n", 
		MIN_LUX); 
}*/
