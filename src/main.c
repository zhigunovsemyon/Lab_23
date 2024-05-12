#include <stdint.h>
#include <stdio.h>

uint8_t CharToNum(char c)
{
	return c - '0';
}

int main(void)
{
	char sss;
	int count = 0;
	while('\n' != (sss = getchar()))
	{
		if(sss >= '0' && sss <='9')
		{
			count++;
			printf("%hhd" ,CharToNum(sss));
		}
	}
	printf("\ncount = %d\n", count);
	return 0;
}
