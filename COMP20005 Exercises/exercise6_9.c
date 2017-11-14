/* Exercise 6.9
   William Ngeow, June 2013
*/

#include <stdio.h>
#include <stdlib.h>

#define ONE_DOLLAR 100
#define TWO_DOLLAR 200
#define FIFTY 50
#define TWENTY 20
#define TEN 10
#define FIVE 5
#define TYPES 7

int try_one_coin(int *cents, int coin);
void print_change(int cents); 
int round_to_5(int cents); 

int
main(int argc, char *argv[]) {
	int i;

	/* read the value */
	printf("Enter a value in cents: ");
	if (scanf("%d", &i) != 1) {
		printf("Invalid input, please try again\n");
		exit(EXIT_FAILURE);
	}
	
	i=round_to_5(i); 
	print_change(i); 

	/* job done */
	return 0;
}

int 
try_one_coin(int *cents, int coin) {
    int num_coin=0;
    num_coin = (*cents-(*cents%coin))/coin; 
    *cents = *cents%coin; 
    return num_coin;
}

void 
print_change(int cents) { 
    int A[TYPES]={TWO_DOLLAR, ONE_DOLLAR, FIFTY, TWENTY, TEN, FIVE}; 
    char B[TYPES]={'2', '1', '5', '2', '1', '5'};                  
    int i; 
    
    for (i=0; i<TYPES-1; i++) {
        printf("%c: %d\n", B[i], try_one_coin(&cents, A[i])); 
    }
}

int 
round_to_5(int cents) {
    int change; 
    change=cents%5; 
    if (change<=2) {
        return cents-change; 
    } else { 
        return cents+5;
    }
}
