/*  Engineering Computation COMP20005, Semester 1, 2013
    Project A

    Stage 1: This program reads a file of earthquake records in the 
    specified format and prints out the date, time, magnitude, and 
    location, and energy release of the first earthquake described in 
    the file
   
    Stage 2: This program reads right through the data file and prints a 
    summary of the data in the file: the number of earthquakes, details 
    of the strongest one, and the total amount of energy released
   
    Stage 3: This program adds in further logic and another set of 
    variables so that a monthly report line is generated. That is, for 
    each month, the number of earthquakes in that month, and the magnitude 
    of the strongest one are printed out 
   
    Stage 4: This program adds a graph of total monthly
    earthquake energy to Stage 3, scaled so that no bar is printed out 
    if the monthly energy is 10 TJ or below, and logarithmic thereafter, 
    with each ten characters representing a multiple of ten in terms of 
    monthly total energy
   
    Written by William Ngeow, April 2013
    Student number: 596301
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N_HEADER 2
#define N_DATA 13
#define TEN_TERA 10
#define MAX_TERA 1000
#define TEN_PETA 10000
#define MAX_PETA 1000000
#define TEN_EXA 10000000
#define MAX_EXA 1000000000
#define MIN_ENERGY 10
#define GRAPH_SCALE 10
#define TEN 10
#define EARTH_MULT_CONSTANT 1.5
#define EARTHQUAKE_CONSTANT 7.2
#define NEXT_YEAR 1
#define FIRST_MONTH 1
#define LAST_MONTH 12
#define MONTH_IN_YEAR 12
#define DEFAULT 0
#define ROUNDING 0.5

void print_energy(double magnitude); 
double energy(double magnitude);
int nbars(double energy); 
void print_graph(double month_energy); 
int is_next(int year_count, int month_count, int yyyy, int mm); 
void print_month_quakes(int month_nquakes, double month_max_mag); 

int
main(int argc, char *argv[]) {
    /* for stage 1 */ 
    int yyyy, mm, dd, hh, min, sec, junki;
    char junkc; 
    double latit, longi, depth, magnitude; 
    
    /* for stage 2 */ 
    int ch, first=1, fmonth=1, lines=1, month_nquakes=0, tot_nquakes=0, 
    month_count=0, year_count=0;
    int yyyy_max, mm_max, dd_max, hh_max, min_max, sec_max; 
    double max_mag=0, latit_max, longi_max, tot_energy=0;
    
    /* for stage 3 */
    double month_max_mag=0;

    /* for stage 4 */
    double month_energy=0; 
    
     /* Stage 1: print output format of stage 1 and line separator */ 
    printf("\nStage 1\n"); 
    printf("=======\n"); 
    
    /* reads for header lines and skips to data */
    while ((ch=getchar()) != EOF) {
        if (ch == '\n') {
            lines ++; 
            /* if line is less than two lines, still in header lines 
            (header consists of the first two lines) */ 
            if (lines>N_HEADER) {
                break;
            }
        }
    }
    
    /* read data of earthquakes */ 
    while(scanf("%4d-%2d-%2d%c%2d:%2d:%2d+%2d:%2d,%lf,%lf,%lf,%lf",
                &yyyy, &mm, &dd, &junkc, &hh, &min, &sec, &junki, 
                &junki, &latit, &longi, &depth, &magnitude) == N_DATA) { 
            
        /* if first earthquake, print */
        if (first != 0) {    
            /* prints out the date, time, magnitude, and location of the 
            first earthquake described in the file */
            printf("Records commence: %4d-%02d-%02d, %02d:%02d:%02d\n", 
                yyyy, mm, dd, hh, min, sec);
            printf("First earthquake: magnitude %0.1f at (%0.1f,%0.1f)\n", 
                magnitude, latit, longi); 
            printf("Energy released : ");
            print_energy(energy(magnitude)); 
            first = 0;
                 
            /* Stage 3/4: print output format of stage 3/4 
            and line separator */
            printf("\nStage 3/4\n"); 
            printf("=========\n");
        }
            
        /* initialise the first year count and month count */
        if (fmonth != 0) { 
            year_count = yyyy; 
            month_count = mm;
            printf("%d-%02d: ", yyyy, mm);
            fmonth = 0; 
        }
            
        if (year_count != yyyy || month_count != mm) {   
            print_month_quakes(month_nquakes, month_max_mag); 
            
            /* resets counter for monthly number of earthquakes and
            monthly maximum magnitude */ 
            month_nquakes = DEFAULT;   
            month_max_mag = DEFAULT;  
            
            /* prints graph of total monthly earthquake energy */
            print_graph(month_energy); 
            month_energy = DEFAULT; 
            
            if (!is_next(year_count, month_count, yyyy, mm)) {
                while (!is_next(year_count, month_count, yyyy, mm)) { 
                    if (month_count < MONTH_IN_YEAR) { 
                        month_count ++;
                    } else { 
                        year_count ++; 
                        month_count = FIRST_MONTH; 
                    }
                    
                    /* print year, month and graph of total monthly 
                    earthquake energy */ 
                    printf("%d-%02d: ", year_count, month_count);
                    print_month_quakes(month_nquakes, month_max_mag); 
                    print_graph(month_energy); 
                    month_energy = DEFAULT; 
                }
            }            
                
            /* print year and month */ 
            year_count = yyyy; 
            month_count = mm;
            printf("%d-%02d: ", yyyy, mm); 
        }
            
        if (year_count == yyyy && month_count == mm) { 
            /* count monthly number of earthquakes and energy*/ 
            month_nquakes ++;
            month_energy += energy(magnitude);
                
            /* determine strongest earthquake in month */ 
            if (magnitude>month_max_mag) {
            month_max_mag = magnitude; 
            }
        }
            
        /* count total number of earthquakes */
        tot_nquakes ++;
            
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
        
    /* prints number of earthquakes and strongest one for final month */ 
    /* also prints graph of total monthly earthquake energy */
    printf("%3d, ", month_nquakes); 
    printf("max %.1f ", month_max_mag); 
    print_graph(month_energy);
        
    /* Stage 2: print output format of stage 2 and line separator */ 
    printf("\nStage 2\n"); 
    printf("=======\n"); 
    
    /* prints summary of data: number of earthquakes, details of strongest, 
    and total energy released */ 
    printf("Total earthquakes    : %d\n", tot_nquakes); 
    printf("Strongest earthquake : magnitude %.1f at (%.1f,%.1f)\n", 
        max_mag, latit_max, longi_max); 
    printf("Took place on        : %4d-%02d-%02d, %02d:%02d:%02d\n", 
        yyyy_max, mm_max, dd_max, hh_max, min_max, sec_max);
    printf("Total energy released: "); 
    print_energy(tot_energy); 
    printf("\n");
    
    /* job done, programming is fun! */
    return 0;
}

/* prints the energy of the first earthquake 
and prints value of energy for different ranges */
void 
print_energy(double energy) {

    if (energy<TEN_TERA) {
        printf("%.1f TJ\n", energy); 
    } else if (energy>=TEN_TERA && energy<MAX_TERA) {
        printf("%.0f TJ\n", energy); 
    } else if (energy>=MAX_TERA && energy<TEN_PETA) {
        printf("%.1f PJ\n", energy/MAX_TERA); 
    } else if (energy>=TEN_PETA && energy<MAX_PETA) {  
        printf("%.0f PJ\n", energy/MAX_TERA);
    } else if (energy>=MAX_PETA && energy<TEN_EXA) {  
        printf("%.1f EJ\n", energy/MAX_PETA);
    } else if (energy>=TEN_EXA && energy<MAX_EXA) { 
        printf("%.0f EJ\n", energy/MAX_PETA);
    } else { 
        /* magnitude too big */
        printf("Error: Magnitude has exceeded bounds\n"); 
    }
}

/* compute energy released by earthquake */ 
double
energy(double magnitude) {
    double energy, power; 
    /* this is the formula to calculate the energy of an earthquake */
    /* energy = 10^(3.0*magnitude/2-7.2) */
    power = (EARTH_MULT_CONSTANT*(magnitude)-EARTHQUAKE_CONSTANT); 
    return energy = pow(TEN,power); 
}

/* counts number of bars to print for graph */
int 
nbars(double energy) {
    double nbars; 
    int n;
    nbars = ((double)log10(energy/MIN_ENERGY))*GRAPH_SCALE; 
    /* for rounding, 0.5 is add */
    return n = (int)(nbars+ROUNDING);
}

/* print graph of total monthly earthquake energy */    
void 
print_graph(double month_energy) {
    int i;
    
    printf("|");
    for (i=1; i<nbars(month_energy); i++) {
        if (i%GRAPH_SCALE != 0) { 
            printf("-");
        } else {
            printf("+"); 
        }
    }
                
    if (nbars(month_energy)>0) {
        printf("|\n");
    } else { 
        printf("\n");
    }
}

/* checks if the next month read is the adjacent month */ 
int 
is_next(int year_count, int month_count, int yyyy, int mm) { 
    
    if (year_count == yyyy && mm-month_count == FIRST_MONTH) {
        return 1; 
    } else if (year_count+NEXT_YEAR == yyyy && mm == FIRST_MONTH && 
        month_count == LAST_MONTH) {
        return 1; 
    } else { 
        return 0;
    }
}

/* print number of earthquakes and strongest one in month */ 
void 
print_month_quakes(int month_nquakes, double month_max_mag) {
    
    if (month_nquakes == DEFAULT && month_max_mag == DEFAULT) { 
        printf("%3d, ", month_nquakes); 
        printf("max --- ");
    } else {
        printf("%3d, ", month_nquakes); 
        printf("max %.1f ", month_max_mag); 
    }
}

