/* Gaussian Elimination
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

double findxi(double matrix[SIZE][SIZE], int i, int n); 

int
main(int argc, char *argv[]) {
	int n, i=0, j=0;
	double next;

	/* read the value */
	printf("Enter the size of the matrix (n): "); 
	scanf("%d", &n); 
	double matrix[n][n+1]; 
	printf("Enter a n*(n+1) matrix: ");
	while (scanf("%lf", &next) == 1) {
	   
	    if (i==n+1) {
	        j++;
	        i=0;
	    }
	    matrix[j][i] = next; 
	    i++;
	}
	
	/* print input */
	for (j=0; j<n; j++) {
        for (i=0; i<n+1; i++) { 
            printf("%7.2f", matrix[j][i]); 
        }
        printf("\n"); 
    }
    
    /* form upper triangle matrix */
    int k;
    for (k=0; k<n; k++) {
        for (j=k+1; j<n; j++) {
            for (i=k+1; i<n+1; i++) {
                matrix[j][i] = matrix[j][i]- (matrix[j][k])*(matrix[k][i])/(matrix[k][k]);
            }
            matrix[j][k] = matrix[j][k]- (matrix[j][k])*(matrix[k][k])/(matrix[k][k]);
        }
    }
    
    /* print input */
    printf("\n");
	for (j=0; j<n; j++) {
        for (i=0; i<n+1; i++) { 
            printf("%7.2f", matrix[j][i]); 
        }
        printf("\n"); 
    }
    
    
    for (k=0; k<n; k++) {
        printf("x%d: %f\n", k, findxi(matrix, k, n));
    }

	/* job done */
	return 0;
}

double 
findxi(double matrix[SIZE][SIZE], int i, int n) {
     /* print input */
     int j, k;
    printf("\n");
	for (j=0; j<n; j++) {
        for (k=0; k<n+1; k++) { 
            printf("%7.2f", matrix[j][k]); 
        }
        printf("\n"); 
    }
    if (i==n-1) {
        printf("%f\n", (matrix[n-1][n])/(matrix[n-1][n-1]));
        return ((matrix[n-1][n])/(matrix[n-1][n-1])); 
    } else {
        return (matrix[i][n]-(matrix[i][n-1])*findxi(matrix, i+1, n))/matrix[i][i];
    }
}
