/* Exercise 3.3
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main(int argc, char *argv[]) {
	double a, b, c, d, root1, root2;
	int n_roots=0; 

	/* read the value */
	printf("Enter a, b, c for ax^2+bx+c: ");
	if (scanf("%lf,%lf,%lf", &a, &b, &c) != 3) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* compute */
	d = b*b-4.0*a*c; 
	
	if (d==0) { 
	    n_roots=1;
	    root1 = -b/(2.0*a);
	} else if (d<0) {
	    n_roots=0;
	} else { 
	    if(a==0) {
	        n_roots=1; 
	        root1 = -c/b; 
	    } else { 
	        n_roots=2; 
	        root1 = (-b+sqrt(d))/(2*a); 
	        root2 = (-b-sqrt(d))/(2*a); 
	    }
	}

	/* print output */

	if(n_roots==0) {
	    printf("There are no roots\n");
	    printf("Complex roots\n"); 
	} else if (n_roots==1) {
	    printf("There is %d root\n", n_roots);
	    printf("Root is %f\n", root1); 
	} else { 
	    printf("There are %d roots\n", n_roots);
	    printf("Roots are %f and %f\n", root1, root2); 
	}

	/* job done */
	return 0;
}
