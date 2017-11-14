/* Exercise 4.3
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>

int fib(int i); 

int
main(int argc, char *argv[]) {
	int i, n;
	
	for (i=1; n<=10000000 ; i++) {
	    n = fib(i);
	    if (n<=10000000) {
	        printf("%d\n", n);
	    }
    }

	/* job done */
	return 0;
}

int 
fib(int i) {
    if (i==1 || i==2) {
        return 1;
    } else { 
        return (fib(i-1)+fib(i-2));
    }
}
