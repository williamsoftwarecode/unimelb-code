/* Exercise 3.04: Compute tomorrow's date
   Alistair Moffat, March 2013
*/

#include <stdio.h>
#include <stdlib.h>

/* some useful values to do with months */
#define MONTHS_PER_YEAR 12
#define SHRT_MONTH 30
#define LONG_MONTH 31
#define FEB_NORMAL 28
#define FEB  2
#define APR  4
#define JUN  6
#define SEP  9
#define NOV 11

#define MIN_YEAR 1752
	/* why is this the minimum year that we can handle? */

int
main(int argc, char *argv[]) {
	int dd, mm, yyyy;
	int days_in_month;

	/* read the three input values */
	printf("Enter a date in dd/mm/yyyy format: ");
	if (scanf("%d/%d/%d", &dd, &mm, &yyyy) != 3) {
		printf("Input error, please try again, genius!\n");
		exit(EXIT_FAILURE);
	}

	/* first round of data verification */
	if (yyyy<=MIN_YEAR) {
		printf("Year is outside permitted range, ");
		printf("must be greater than %d\n", MIN_YEAR);
		exit(EXIT_FAILURE);
	}
	if (mm<=0 || mm>MONTHS_PER_YEAR) {
		printf("Month is outside permitted range, ");
		printf("must be between 1 and %d\n", MONTHS_PER_YEAR);
		exit(EXIT_FAILURE);
	}


	/* compute length of month */
	if (mm==SEP || mm==APR || mm==JUN || mm==NOV) {
		/* 30 days hath September, April, June, and November
		*/
		days_in_month = SHRT_MONTH;
	} else if (mm==FEB) {
		/* except February, which only has 28 */
		days_in_month = FEB_NORMAL;
		if (yyyy%4==0 && (yyyy%100!=0 || yyyy%400==0) ) {
			days_in_month += 1;
		}
		/* this is an example where coding constants
		   directly can be (just) tolerated, since the
		   context is (reasonably) clear
		*/
	} else {
		/* all the rest have 31... */
		days_in_month = LONG_MONTH;
	}

	/* second round of data verification */
	if (dd<=0 || dd>days_in_month) {
		printf("Day is outside permitted range, ");
		printf("must be between 1 and %d\n", days_in_month);
		exit(EXIT_FAILURE);
	}

	/* data is checked, now ready to go on with computation */
	printf("The date today is: %02d/%02d/%04d\n",
		dd, mm, yyyy);

	/* shift to next day */
	dd += 1;
	if (dd>days_in_month) {
		/* ooops, carry from day into month */
		dd = 1;
		mm += 1;
	}
	if (mm>MONTHS_PER_YEAR) {
		/* ooops, carry from month into year */
		mm = 1;
		yyyy += 1;
	}
	
	/* output results */
	printf("The date tomorrow is: %02d/%02d/%04d\n",
		dd, mm, yyyy);
	
	/* job done */
	return 0;
}
