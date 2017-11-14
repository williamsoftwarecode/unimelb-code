#include <stdio.h>

int
main (int argc, char *argv[]) {
	
	int cents;
	printf("Enter amount in cents: ");
	scanf("%d", &cents); 
	printf("The coins required to make %d cents are: \n",cents);

	if ((cents-50)>=0) {
		printf("50, ");
		cents-=50;
	} 
	
	if ((cents-20)>=0) {
		printf("20, ");
		cents-=20;
	}
	
	if ((cents-20)>=0) {
		printf("20, ");
		cents-=20;
	} 
	
	if ((cents-10)>=0) {
		printf("10, ");
		cents-=10;
	} 
	
	if ((cents-5)>=0) {
		printf("5, ");
		cents-=5;
	} 
	
	if ((cents-2)>=0) {
		printf("2, ");
		cents-=2;
	} 
	
	if ((cents-2)>=0) {
		printf("2, ");
		cents-=2;
	} 
	
	if ((cents-1)>=0) {
		printf("1, ");
		cents-=1;
	}

return 0; 
}
