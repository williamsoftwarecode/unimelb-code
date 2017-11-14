/* Exercise 5.7
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int my_isupper(int c); 
int my_tolower(int c); 

int
main(int argc, char *argv[]) {
	int i;

	/* read the value */
	printf("Enter an uppercase alphabet: ");
	i=getchar();
	
	if (my_isupper(i) && isupper(i)) {
	    printf("%c is an uppercase alphabet\n", i); 
	    printf("The lowercase alphabet (my_tolower) is %c\n", my_tolower(i));  
	    printf("The lowercase alphabet (tolower) is %c\n", tolower(i));  	
	} else { 
	    printf("Not an uppercase alphabet\n"); 
	}

	/* job done */
	return 0;
}

int 
my_isupper(int c) { 
    if(c>=65 && c<=90) {
        return 1; 
    } else { 
        return 0; 
    }
}

int 
my_tolower(int c) {
    return (c+32); 
}
