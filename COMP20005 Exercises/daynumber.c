/* Comment: Exercise 3.5 - Reads a date in dd/mm/yyyy format and calculates the day number within the year. 
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
	int dd, mm, yyyy;
	int days, days_feb, month, daynumber; 

	/* read the value */
	printf("Enter date in format dd/mm/yyyy: ");
	if (scanf("%d/%d/%d", &dd, &mm, &yyyy) != 3) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}
	
	/* determines day number within year */ 
		daynumber = dd; 
	
	/* determine if leap year */
	if(yyyy%4==0 && (yyyy%100!=0 || yyyy%400==0)) {
		days_feb = 29; 
	} else { 
		days_feb = 28; 
	}

	/* determine number of days in month */ 
	if (mm>1) {
	for (month=1; month<mm; month++) {
		if(month==2) {
			days = days_feb;
		} else if (month==4 || month==6 || month==9 || month==11) { 
			days = 30; 
		} else {
			days = 31; 
		}
		daynumber = daynumber + days; 
	}
	}
		 
	
	/* print day number within year */
	printf("%02d/%02d/%04d is day number %d in the year\n", dd, mm, yyyy, daynumber);

	/* job done */
	return 0;
}
