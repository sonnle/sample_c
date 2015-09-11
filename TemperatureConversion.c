#include <stdio.h>

#define LOW 	0 	//Lowest Fahrenheit Value
#define HIGH 	100	//Highest Fahrenheit Value
#define STEP 	10	//Step Per Print

int main()
{
	for(int fahr = LOW; fahr <= HIGH; fahr += STEP)
	{
		printf("%3d :%3.1f\n", fahr, (5.0/9.0)*(fahr-32));
	}
	return 0;
}

