/* Exercise 3.5
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define MONTH_ARRAY 13
#define YEAR_TYPE 2

int is_leap_year(int dd, int mm, int yyyy); 

int month_array[YEAR_TYPE][MONTH_ARRAY] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},
                                    {0,31,29,31,30,31,30,31,31,30,31,30,31}}; 

int
main(int argc, char *argv[]) {
	int dd, mm, yyyy, day_num, i;

	/* read the value */
	printf("Enter a date in dd/mm/yyyy format: ");
	if (scanf("%d/%d/%d", &dd, &mm, &yyyy) != 3) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}
	
	/* compute */
	day_num = dd;
	
	for(i=0; i<mm; i++) {
	    day_num += month_array[is_leap_year(dd, mm, yyyy)][i]; 
	}
	    
	/* print output */
	printf("%02d/%02d/%04d is day number %d in the year\n", dd, mm, yyyy, day_num);

	/* job done */
	return 0;
}

int 
is_leap_year(int dd, int mm, int yyyy) {
    return (yyyy%4==0 && (yyyy%100!=0 || yyyy%400==0));
}
    
