/* Defining main loop */

#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

/* Adding other things for merge conflict */

int getop(char[]);
void push(double);
double pop(void);

int main()
{
	int type;
	double op2;
	double test1, test2;
	char s[MAXOP];
	
	while((type = getop(s)) != EOF)
	{
		switch(type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				printf("Addition\n");
				test1 = pop();
				test2 = pop();
				printf("%f,%f\n", test1, test2);
				push(test1 + test2);
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0)
					push(pop() / op2);
				else
					printf("ERROR: Division by zero.\n");
				break;
			case '%':
				op2 = pop();
				double op1 = pop();
				if(op1 >= 0 && op2 > 0)
				{
					int whole = (int)(op1 / op2);
					push(((op1 / op2) - whole) * op2);
				}
				else if(op2 == 0)
				{
					printf("ERROR:Division by zero.\n");
				}
				else
				{
					printf("ERROR:Arguments can not be negative.\n");
				}
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("UNKNOWN OPERATION: %s\n.", s);
				break;
		}
	}
}

/* End main loop */

/* Defining push/pop */

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if(sp < MAXVAL)
	{
		val[sp++] = f;
	}
	else
	{
		printf("ERROR: Stack overflow. %f\n", f);
	}
}

double pop(void)
{
	if(sp > 0)
	{
		return val[--sp];
	}
	else
	{
		printf("ERROR: Stack empty.\n");
		return 0.0;
	}
}

/* End push/pop */

/* Defining getop */

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
	int i, c;
	while((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = '\0';
	if(!isdigit(c) && c != '.')
	{
		return c;
	}
	i = 0;
	if(isdigit(c))
	{
		while(isdigit(s[++i] = c = getch()));
	}	
	if(c == '.')
	{
		while(isdigit(s[++i] = c = getch()));
	}
	s[i] = '\0';
	if(c != EOF)
	{
		ungetch(c);
	}
	return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	if(bufp > 0)
		return buf[--bufp];
	else
		return getchar();
}

void ungetch(int c)
{
	if(bufp >= 100)
	{
		printf("ERROR: Buffer overflow, ungetch has too many characters\n");

	}
	else
	{
		buf[bufp++] = c;
	}
}

/* End getop */









