
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool b = false;
int a = 40;

void func (void);

int main (int argc, char** argv)
{
	func();
	return 0;
}


void func ()
{
	b = (a > 0);

	if (b)
	{
		b=1;
		printf ("b = 1\n");
	}
	else
	{
		b=0;
		printf ("b = 0\n");
	}
}


