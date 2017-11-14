/* Comment: Calculate roots of quadratic equation
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main(int argc, char *argv[]) {
	double a, b, c;
	double d, root1, root2;

	/* read the value roots of quadratic equation in the form a*x^2+b*x+c*/
	printf("Enter values a, b and c for quadratic equation (a*x^2+b*x+c): ");
	if (scanf("%lf" "%lf" "%lf", &a, &b, &c) != 3) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* compute roots */
	d = b*b-4*a*c; 
	
	if (a==0) { 
		root1 = -c/b;
		printf("One real root is %f\n", root1);
	} else if (b==0) {
		if (c<=0) {
		root1 = sqrt(-c/a);
		printf("One real root is %f\n", root1);
		} else { 
			printf("Complex roots"); 
		}
	}else{
		if (d>0) {
			root1 = (-b+sqrt(d))/(2*a); 
			root2 = (-b-sqrt(d))/(2*a);
			printf("Two real roots are %f and %f\n", root1, root2);
		} else if (d==0) {
			root1 = root2 = -b/(2*a);
			printf("One real root is %f\n", root1);
		} else { 
			printf("Complex roots"); 
		}
	}
	
	/* job done */
	return 0;
}
