/*  THIS CODE IS NOT THE ASSIGNMENT. 
    THIS PROGRAM IS MADE FOR THE SPECIFIC PURPOSE OF PRINTING THE
    TEXT-O.TXT FILE FROM THE VERIFY FUNCTION IN PUTTY. 
    
    WRITTEN BY WILLIAM NGEOW, APRIL 2013 */ 
        
#include <stdio.h> 
#include <stdlib.h> 

int
main(int argc, char *argv[]) { 
    int character; 
        while((character = getchar()) != EOF) { 
        printf("%c", character); 
        }  
return 0;
}
        
