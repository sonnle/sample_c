#include <stdio.h>
#include <string.h>

void strcopy(char *source, char *target);

#define ARRAY_LENGTH 10

char charSource[] = "Hello Son. This is a test.";
char *psource = charSource;
char charTarget[ARRAY_LENGTH];
char *ptarget = charTarget;


int main(void)
{
	printf("Source Before: %s\n",psource);
	printf("Target Before: %s\n",ptarget);
	printf("Running strcopy..........\n");
	strcopy(psource, ptarget);
	printf("Source After: %s\n",psource);
	printf("Target After: %s\n",ptarget);
}

void strcopy(char *source, char *target)
{
	if(strlen(source) < ARRAY_LENGTH)
		while((*target++ = *source++) != '\0');
	else
		printf("Error, source string exceeds limit.\n");
}