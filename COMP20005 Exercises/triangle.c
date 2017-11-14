/* Program to print a triangle */ 

#include <stdio.h> 

int 
main(int argc, char *argv[]) { 
	int n;
	int nx, nspace; 
	
	printf("Enter a number: "); 
	scanf("%d", &n); 
	
	for(nx=1; nx<=n; nx+=1) { 
		nspace=n-nx; 
		int i,j;
		
		for(i=1; i<=nspace; i+=1) {
			printf(" "); 
		}
		
		for(j=1; j<=nx; j+=1) { 
			printf("X"); 
		}
		printf("\n"); 
	}
	return 0; 
}
