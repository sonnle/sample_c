#include <stdio.h>

int power(int base, int power);

int main()
{
	for(int i = 1; i < 10; i++)
	{
		printf("%5d %10d %15d\n", i, power(i,i), power(i,i+2));
	}
	return 0;
}

int power(int base, int power)
{
	long temp = 1;
	for(int i = 0; i < power; i++)
	{
		temp = temp * base;
	}
	return temp;
}
