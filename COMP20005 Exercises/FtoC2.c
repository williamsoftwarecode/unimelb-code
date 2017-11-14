# include <stdio.h>

int
main(int argc, char *argv[]) {

	double Fahrenheit;	
	double Celcius;
	printf("Enter temperature in Fahrenheit: ");
	scanf("%lf", &Fahrenheit);
	Celcius = (Fahrenheit-32)*5.0/9; 
	printf("The temperature in Celcius is %f\n", Celcius);

	return 0;
}
