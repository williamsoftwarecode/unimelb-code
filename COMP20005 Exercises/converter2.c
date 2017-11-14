# include <stdio.h>

int
main(int argc, char *argv[]) {
	char unit;
	double value;
	double Fahrenheit;	
	double Celcius;
	double Miles;
	double Kilometers; 
	double Pounds;
	double Kilograms; 
	
	printf("Enter a quantity: ");
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
	
	if (unit=='M') {
		Miles = value;
		Kilometers = Miles*1.609; 
		printf("The distance %f miles converts to %f kilometers\n", Miles, Kilometers);
	} else if (unit=='K') {
		Kilometers = value;
		Miles = Kilometers/1.609; 
		printf("The distance %f kilometers converts to %f miles\n", Kilometers, Miles);
	}
	
	if (unit=='P') {
		Pounds = value;
		Kilograms = Pounds*0.454;
		printf("The mass %f pounds converts to %f kilograms\n", Pounds, Kilograms);
	} else if (unit=='G') {
		Kilograms = value;
		Pounds = Kilograms/0.454; 
		printf("The mass %f kilograms converts to %f pounds\n", Kilograms, Pounds);
	}
	
	return 0;
}
