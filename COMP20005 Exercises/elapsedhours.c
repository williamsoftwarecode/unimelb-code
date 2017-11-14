/* Comment: Exercise 2.3: Program calculates time in elapsed hours
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define MINS_PER_HOUR 60
#define SECS_PER_MIN 60

int
main(int argc, char *argv[]) {
	double finish_total, start_total, elapsed_secs, elapsed_min, elapsed_hours;
	int start_hour, start_min, start_sec, finish_hour, finish_min, finish_sec; 

	/* read the value of start_hour, start_min and start_sec*/
	printf("Enter value of start_hour, start_min, start_sec, finish_hour, finish_min, finish_sec(with spaces): ");
	if (scanf("%d" "%d" "%d" "%d" "%d" "%d", &start_hour, &start_min, &start_sec, &finish_hour, &finish_min, &finish_sec) != 6) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}

	/* compute elapsed hour */
	finish_total = (finish_hour*MINS_PER_HOUR*SECS_PER_MIN)+(finish_min*SECS_PER_MIN)+finish_sec;
	start_total = (start_hour*MINS_PER_HOUR*SECS_PER_MIN)+(start_min*SECS_PER_MIN)+start_sec;
	elapsed_secs = finish_total-start_total; 
	elapsed_min = elapsed_secs/SECS_PER_MIN; 
	elapsed_hours = elapsed_min/MINS_PER_HOUR; 

	if (elapsed_hours <= 0){
		printf("Error: Elapsed time is negative"); 
	} else {
	
	/* print output */
	printf("The time in elapsed hours is %f \n", elapsed_hours);
	}
	
	/* job done */
	return 0;
}
