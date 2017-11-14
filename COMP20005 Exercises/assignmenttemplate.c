/* Stage 1: This program reads a file of earthquake records in the specified 
   format and prints out the date, time, magnitude, and location, and 
   energy release of the first earthquake described in the file
   
   Stage 2: This program reads right through the data file and prints a summary 
   of the data in the file: the number of earthquakes, details of the strongest 
   one, and the total amount of energy released
   
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TEN_TERA 10
#define MAX_TERA 1000
#define MAX_PETA 1000000
#define MAX_EXA 1000000000

void print_energy(double magnitude); 
double energy(double magnitude);

int
main(int argc, char *argv[]) {
	int yyyy, mm, dd, hh, min, sec, junki;
	char junkc; 
	double latit, longi, depth, magnitude; 
	
	/* Stage 1: print output format of stage 1 and line separator */ 
	printf("\nStage 1\n"); 
	printf("=======\n"); 
	
	/* reads for header lines and skips to data */
	int ch, inheader=1, read=1, lines=1, nquakes=0;
	int yyyy_max, mm_max, dd_max, hh_max, min_max, sec_max; 
	double max_mag=0, latit_max, longi_max, tot_energy;
	
	while ((ch=getchar()) != EOF) {
		
		if (ch == '\n') {
			/* this is a new line */ 
			lines ++; 
			
			/* if line is less than two lines, still in header 
			(header consists of the first two lines) */ 
			if (lines<=2) {
				inheader = 1;
			} else { 
				inheader = 0; 
			}
		}
		
		if (!inheader) { 	
			/* read data of earthquakes */ 
			scanf("%4d-%2d-%2d%c%2d:%2d:%2d+%2d:%2d,%lf,%lf,%lf,%lf",
				&yyyy, &mm, &dd, &junkc, &hh, &min, &sec, &junki, 
				&junki, &latit, &longi, &depth, &magnitude); 
			printf("%4d %d %d %d\n", yyyy, hh, min, sec); 
			printf("lines = %d\n", lines);
			
			/* if first earthquake, print */
			if (read != 0) {
				/* prints out the date, time, magnitude, and location of the first earthquake described in the file */
				printf("Records commence: %4d-%02d-%02d, %02d:%02d:%02d\n", yyyy, mm, 
					dd, hh, min, sec);
				printf("First earthquake: magnitude %0.1f at (%0.1f,%0.1f)\n", magnitude, latit, longi); 
				print_energy(magnitude); 
				read = 0;
			}
			
			/* count number of earthquakes */ 
			nquakes ++;
			
			/* determine strongest earthquake */ 
			if (magnitude>max_mag) {
				max_mag = magnitude; 
				latit_max = latit; 
				longi_max = longi; 
				yyyy_max = yyyy; 
				mm_max = mm;  
				dd_max = dd;  
				hh_max = hh; 
				min_max = min;  
				sec_max = sec;
			}
			
			/* determine total energy released */ 
			tot_energy += energy(magnitude); 
		}
	}
	
	/* Stage 2: print output format of stage 2 and line separator */ 
	printf("\nStage 2\n"); 
	printf("=======\n"); 
	
	/* prints summary of data: number of earthquakes, details of strongest, 
	and total energy released */ 
	printf("Total earthquakes    : %d\n", nquakes); 
	printf("Strongest earthquake : magnitude %.1f at (%.1f,%.1f)\n", max_mag, latit_max, longi_max); 
	printf("Took place on        : %4d-%02d-%02d, %02d:%02d:%02d\n", yyyy_max, mm_max, 
					dd_max, hh_max, min_max, sec_max);
	print_energy(tot_energy); 
	
	/* job done, programming is fun! */
	return 0;
}

/* prints the energy of the first earthquake */
void 
print_energy(double magnitude) {
	
	/* prints value of energy for different ranges */
	if (energy(magnitude)<TEN_TERA) {
		printf("Energy released : %.1f TJ\n", energy(magnitude)); 
	} else if (energy(magnitude)>=TEN_TERA && energy(magnitude)<MAX_TERA) {
		printf("Energy released : %.0f TJ\n", energy(magnitude)); 
	} else if (energy(magnitude)>=MAX_TERA && energy(magnitude)<MAX_PETA) {  
		printf("Energy released : %.0f PJ\n", energy(magnitude)/1000);
	} else if (energy(magnitude)>=MAX_PETA && energy(magnitude)<MAX_EXA) { 
		printf("Energy released : %.0f EJ\n", energy(magnitude)/1000000);
	} else { 
		/* magnitude too big */
		printf("Error: Magnitude has exceeded bounds\n"); 
	}
}

double
energy(double magnitude) {
	double energy, power; 
	/* compute energy released for the first earthquake */ 
	power = (3.0*(magnitude)/2-7.2); 
	return energy = pow(10,power); 
}
