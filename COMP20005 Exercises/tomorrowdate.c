/* Comment: Exercise 3.4 - Reads a date indd/mm/yyyy format and writes, in the same fromat, the date it will be tomorrow. 
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
	int dd, mm, yyyy;
	int days, days_feb, month; 

	/* read the value */
	printf("Enter date in format dd/mm/yyyy: ");
	if (scanf("%d/%d/%d", &dd, &mm, &yyyy) != 3) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}
	
	/* prints date read */ 
	printf("Date read: %02d/%02d/%04d\n", dd, mm, yyyy);
	
	/* determine if leap year */
	if(yyyy%4==0 && (yyyy%100!=0 || yyyy%400==0)) {
		days_feb = 29; 
	} else { 
		days_feb = 28; 
	}
	
	/* determine number of days in month */ 
	if(mm==2) {
		days = days_feb;
	} else if (mm==4 || mm==6 || mm==9 || mm==11) { 
		days = 30; 
	} else {
		days = 31; 
	}
	
	/* determine next dd */
	
	month = mm; 
	if(dd<days) {
		dd ++;
	} else if (dd == days) {
		dd = 1; 
		month ++; 
	} else { 
		printf("Error: Date not within days in month\n");
		exit(EXIT_FAILURE);
	}
	
	/* determine next mm */ 
	if (month!=mm) {
		if (mm<12) { 
			mm = month; 
		} else if (mm==12) { 
			mm = 1; 
			yyyy ++; 
		} else {
			printf("Error: Month not within months in year\n");
			exit(EXIT_FAILURE);
		}
	} 

	/* print tomorrow's date */
	printf("Tomorrow:  %02d/%02d/%04d\n", dd, mm, yyyy);

	/* job done */
	return 0;
}
