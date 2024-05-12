#include <stdio.h>

int main(void)
{
	char sss;
	int count = 0;
	while('\n' != (sss = getchar()))
	{
		if(sss >= '0' && sss <='9')
		{
			count++;
			putchar(sss);
		}
	}
	printf("\ncount = %d\n", count);
	return 0;
}
