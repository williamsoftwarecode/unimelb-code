/* Exercise 9.11
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define FORCE 500.0
#define G 9.81
#define K 0.6
#define A 0.1
#define MROCKET 10.0
#define MFUEL 8.0
#define MLOSS 0.8
#define MIN_Y 0
#define PLOT_LINES 40
#define PLOT_CHARS 72

#define ROCKET_FLAME ">>=>"
#define ROCKET_UP "===>"
#define ROCKET_DOWN "<==="

void altitudeduration(double deltat, double* maxY, double* t); 
void drawjourney(double deltat, double maxY, double maxT);
void drawrocket(double t, double fracy, double v, int hasFuel);

int
main(int argc, char *argv[]) {
	double maxY=0; 
	double maxT;
	double deltat;
	
	deltat = atof(argv[1]); 
	altitudeduration(deltat, &maxY, &maxT);
    
	drawjourney(deltat, maxY, maxT); 
	
	/* print output */
	printf("Maximum altitude is: %f metres\nDuration is: %f seconds\n", maxY, maxT);

	/* job done */
	return 0;
}

void 
altitudeduration(double deltat, double* maxY, double* t) {
    double m, a, v, y; 
    int start = 1;
	
    y=0.0;
    m=MROCKET+MFUEL; 
    v=0.0; 
    *t=0.0; 
    
    while (y>MIN_Y || start) {
        if ((fabs(m-MROCKET))>0.0) {
            a = (1/m)*(FORCE-m*G-K*A*v*fabs(v)); 
        } else { 
            a = (1/m)*(-m*G-K*A*v*fabs(v)); 
        }
        
        v+=deltat*a;
        y+=deltat*v; 
        *t+=deltat; 
        if (m-MLOSS*deltat > MROCKET) { 
            m-= MLOSS*deltat; 
        } else { 
            m = MROCKET; 
        }
        if (*maxY<y) {
            *maxY=y; 
        }
        start=0;
    }
    return;
}
        
void 
drawjourney(double deltat, double maxY, double duration) {
    double a, v, y, m, t, lastY;
    int start = 1;
    int hasFuel = 1;
    int nextLine = 0; 
    
    printf("Seconds\n"); 
    y=0.0;
    m=MROCKET+MFUEL; 
    v=0.0;
    t=0.0;
    lastY=y; 
    
    while (y>MIN_Y || start) { 
        if (t/duration*(PLOT_LINES-1)>= nextLine) {
            drawrocket(t, y/maxY, v, hasFuel); 
            lastY = y;
            nextLine += 1; 
        }
        
        if(fabs(m-MROCKET)>0.0) { 
            a = (1/m)*(FORCE - m*G -K*A*v*fabs(v)); 
        } else {
            a = (1/m)*(- m*G -K*A*v*fabs(v)); 
            hasFuel = 0;
        }
        v+=deltat*a;
        y+=deltat*v;
        t+=deltat; 
        if(m-MFUEL*deltat > MROCKET) { 
            m-=MLOSS*deltat; 
        } else { 
            m=MROCKET; 
        }
        start=0;
    }
    drawrocket(t, 0, 0, hasFuel);
}

void 
drawrocket(double t, double fracy, double v, int hasFuel) {
    int i;
    printf("%4.1f|", t); 
    for (i=0; i< (PLOT_CHARS-strlen(ROCKET_UP))*fracy; i++) {
        printf(" "); 
    }
    if (hasFuel) {
        printf(ROCKET_FLAME); 
    } else if (v>0) { 
        printf(ROCKET_UP); 
    } else { 
        printf(ROCKET_DOWN); 
    }
    printf("\n"); 
    return;
}
