/* Exercise 3.4
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
	int dd, mm, yyyy, t_dd, t_mm, t_yyyy;

	/* read the value */
	printf("Enter a date in dd/mm/yyyy format: ");
	if (scanf("%d/%d/%d", &dd, &mm, &yyyy) != 3) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	printf("Date read: %02d/%02d/%04d\n", dd, mm, yyyy);
	
	/* compute */
	t_dd = dd+1; 
	t_mm = mm; 
	t_yyyy = yyyy;
	
	if (t_dd>month_array[is_leap_year(dd, mm, yyyy)][mm]) { 
	    t_dd = 1; 
	    t_mm++; 
	} 
	
	if (t_mm>12) { 
	    t_mm = 1; 
	    t_yyyy++; 
	}

	/* print output */
	printf("Tomorrow: %02d/%02d/%04d\n", t_dd, t_mm, t_yyyy);

	/* job done */
	return 0;
}

int 
is_leap_year(int dd, int mm, int yyyy) {
    return (yyyy%4==0 && (yyyy%100!=0 || yyyy%400==0));
}
    
