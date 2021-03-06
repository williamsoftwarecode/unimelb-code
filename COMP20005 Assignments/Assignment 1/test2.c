/* Stage 1: This program reads a file of earthquake records in the specified 
   format and prints out the date, time, magnitude, and location, and 
   energy release of the first earthquake described in the file
   
   Stage 2: This program reads right through the data file and prints a summary 
   of the data in the file: the number of earthquakes, details of the strongest 
   one, and the total amount of energy released
   
   Stage 3: This program adds in further logic and another set of variables 
   so that a monthly report line is generated. That is, for each month, the 
   number of earthquakes in that month, and the magnitude of the strongest
   one are printed out. 
   
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TEN_TERA 10
#define MAX_TERA 1000
#define TEN_PETA 10000
#define MAX_PETA 1000000
#define TEN_EXA 10000000
#define MAX_EXA 1000000000

void print_energy(double magnitude); 
double energy(double magnitude);

int
main(int argc, char *argv[]) {
    /* for stage 1 */ 
    int yyyy, mm, dd, hh, min, sec, junki;
    char junkc; 
    double latit, longi, depth, magnitude; 
    
    /* Stage 1: print output format of stage 1 and line separator */ 
    printf("\nStage 1\n"); 
    printf("=======\n"); 
    
    /* for stage 2 */ 
    int ch, first=1, fmonth=1, lines=1, month_nquakes=0, tot_nquakes=0, month_count=0,
    year_count=0;
    int yyyy_max, mm_max, dd_max, hh_max, min_max, sec_max; 
    double max_mag=0, latit_max, longi_max, tot_energy=0;
    
    /* for stage 3 */
    double month_max_mag=0;
    
    /* reads for header lines and skips to data */
    while ((ch=getchar()) != EOF) {
        
        if (ch == '\n') {
            /* this is a new line */ 
            lines ++; 
            
            /* if line is less than two lines, still in header 
            (header consists of the first two lines) */ 
            if (lines>2) {
                break;
            }
        }
    }
            /* read data of earthquakes */ 
        while(scanf("%4d-%2d-%2d%c%2d:%2d:%2d+%2d:%2d,%lf,%lf,%lf,%lf",
                &yyyy, &mm, &dd, &junkc, &hh, &min, &sec, &junki, 
                &junki, &latit, &longi, &depth, &magnitude) == 13) { 
            
            /* if first earthquake, print */
            if (first != 0) {
                
                /* prints out the date, time, magnitude, and location of the 
                first earthquake described in the file */
                printf("Records commence: %4d-%02d-%02d, %02d:%02d:%02d\n", 
                    yyyy, mm, dd, hh, min, sec);
                printf("First earthquake: magnitude %0.1f at (%0.1f,%0.1f)\n", magnitude, latit, longi); 
                print_energy(energy(magnitude)); 
                first = 0;
                 
                /* Stage 3: print output format of stage 3 and line separator */
                printf("\nStage 3\n"); 
                printf("=======\n");
            }
            
            /* initialise the first year count and month count */
            if (fmonth != 0) { 
                year_count = yyyy; 
                month_count = mm;
                printf("%d-%02d: ", yyyy, mm);
                fmonth = 0; 
            }
            
            if (year_count != yyyy || month_count != mm) {   
                /* print number of earthquakes and strongest one in month */ 
                printf("%d, ", month_nquakes); 
                month_nquakes = 0; 
                printf("max %.1f\n", month_max_mag); 
                month_max_mag = 0;
                
                /* print year and month */ 
                year_count = yyyy; 
                month_count = mm;
                printf("%d-%02d: ", yyyy, mm); 
            }
            
            if (year_count == yyyy && month_count == mm) { 
                /* count monthly number of earthquakes */ 
                month_nquakes ++;
                
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
         printf("%d, ", month_nquakes); 
         printf("max %.1f\n", month_max_mag); 
        
    /* Stage 2: print output format of stage 2 and line separator */ 
    printf("\nStage 2\n"); 
    printf("=======\n"); 
    
    /* prints summary of data: number of earthquakes, details of strongest, 
    and total energy released */ 
    printf("Total earthquakes    : %d\n", tot_nquakes); 
    printf("Strongest earthquake : magnitude %.1f at (%.1f,%.1f)\n", max_mag, latit_max, longi_max); 
    printf("Took place on        : %4d-%02d-%02d, %02d:%02d:%02d\n", yyyy_max, mm_max, 
                    dd_max, hh_max, min_max, sec_max);
    print_energy(tot_energy); 
    
    /* job done, programming is fun! */
    return 0;
}


void 
print_energy(double energy) {
    
    /* prints the energy of the first earthquake */
    /* prints value of energy for different ranges */
    if (energy<TEN_TERA) {
        printf("Energy released : %.1f TJ\n", energy); 
    } else if (energy>=TEN_TERA && energy<MAX_TERA) {
        printf("Energy released : %.0f TJ\n", energy); 
    } else if (energy>=MAX_TERA && energy<TEN_PETA) {
        printf("Energy released : %.1f PJ\n", energy/MAX_TERA); 
    } else if (energy>=TEN_PETA && energy<MAX_PETA) {  
        printf("Energy released : %.0f PJ\n", energy/MAX_TERA);
    } else if (energy>=MAX_PETA && energy<TEN_EXA) {  
        printf("Energy released : %.1f EJ\n", energy/MAX_PETA);
    } else if (energy>=TEN_EXA && energy<MAX_EXA) { 
        printf("Energy released : %.0f EJ\n", energy/MAX_PETA);
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
