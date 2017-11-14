/* Exercise 8.5
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double re; 
    double im; 
} complex_t;

complex_t complex_add(complex_t v1, complex_t v2); 
complex_t complex_mpy(complex_t v1, complex_t v2); 
void read_complex(complex_t* v1, complex_t* v2); 
void print_complex(complex_t v1, complex_t v2); 

int
main(int argc, char *argv[]) {
	complex_t v1, v2;
    read_complex(&v1,&v2); 
    print_complex(v1,v2); 

	/* job done */
	return 0;
}

complex_t 
complex_add(complex_t v1, complex_t v2) { 
    complex_t v;
    v.re=v1.re+v2.re; 
    v.im=v1.im+v2.im;
    return v;
}

complex_t 
complex_mpy(complex_t v1, complex_t v2) {
    complex_t v;
    v.re=v1.re*v2.re-v1.im*v2.im;
    v.im=v1.re*v2.im+v1.im*v2.re; 
    return v;
}

void 
read_complex(complex_t* v1, complex_t* v2) {
    printf("Enter complex numbers (a+bi,c+di) as (a,b,c,d): "); 
    scanf("%lf,%lf,%lf,%lf", &(*v1).re, &(*v1).im, &(*v2).re, &(*v2).im);
}

void 
print_complex(complex_t v1, complex_t v2) {
    complex_t v;
    v=complex_add(v1,v2);
    printf("The sum is %3f + %3fi\n", v.re, v.im); 
    v=complex_mpy(v1,v2);
    printf("The product is %3f + %3fi\n", v.re, v.im); 
}
    
