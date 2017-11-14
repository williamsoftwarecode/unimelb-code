# include <stdio.h>

int
main(int argc, char *argv[]) {
	char unit;
	double value;
	double Fahrenheit;	
	double Celcius;
	printf("Enter temperature: ");
	scanf("%lf %c", &value, &unit);
	
	if (unit=='F') {
		Fahrenheit = value;
		Celcius = (Fahrenheit-32)*5.0/9; 
		printf("The temperature in Celcius is %f\n", Celcius);
	} else if (unit=='C') {
		Celcius = value;
		Fahrenheit = (Celcius*9.0/5.0)+32; 
		printf("The temperature in Fahrenheit is %f\n", Fahrenheit);
	}
	return 0;
}
