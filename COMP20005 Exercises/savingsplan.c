/* Exercise 5.10: Edited function savings_plan to allow for possibility that the interest rate
	 	  levied on debit balances might be different to the interest rate paid on
	 	  credit balances
   William Ngeow, April 2013
*/

#include <stdio.h>
#include <stdlib.h>

double savings_plan(double initial, double amount, double credit_ann_rate, 
	int years, double debit_ann_rate); 

int
main(int argc, char *argv[]) {
	int years; 
	double crate, drate, per_month, initial, answer; 
	
	/* read in values to be processed */
	printf("Enter number of years	      : "); 
	scanf("%d", &years);
	printf("Enter annual credit rate (%%)  : "); 
	scanf("%lf", &crate);
	printf("Enter annual debit rate (%%)   : "); 
	scanf("%lf", &drate);
	printf("Enter monthly amount 	      : $"); 
	scanf("%lf", &per_month);
	printf("Enter initial balance	      : $"); 
	scanf("%lf", &initial);
	
	
	if (initial >= 0) {
	
	} else { 
		
	}
	/* print out the desired answers */ 
	printf("Saving $%.0f per month for %d years\n", 
		per_month, years); 
	answer = savings_plan(initial, per_month, crate-1, years, drate-1); 
	printf("\tat %.1f%% and %.1f%% per year: $%.0f\n", crate-1, drate-1, answer); 
	answer = savings_plan(initial, per_month, crate, years, drate); 
	printf("\tat %.1f%% and %.1f%% per year: $%.0f\n", crate, drate, answer); 
	answer = savings_plan(initial, per_month, crate+1, years, drate+1); 
	printf("\tat %.1f%% and %.1f%% per year: $%.0f\n", crate+1, drate+1, answer); 
	
	/* job done */
	return 0;
}

double 
savings_plan(double initial, double amount, double credit_ann_rate, 
	int years, double debit_ann_rate) { 
	
		int month; 
		double monthly_mult_debit, monthly_mult_credit, balance = initial; 
		
		monthly_mult_debit = 1.00 + (debit_ann_rate/100.00)/12;
		monthly_mult_credit = 1.00 + (credit_ann_rate/100.00)/12;
		for (month=1; month<=12*years; month++) { 
				if (balance<0) {
					balance *= monthly_mult_debit; 
					balance += amount;
				} else {
					balance *= monthly_mult_credit; 
					balance += amount;
				}
		} 
	return balance;
}
	
