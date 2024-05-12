#include "Stack.h"
#include <stdio.h>

uint8_t CharToNum(char c)
{
	return c - '0';
}

int main(void)
{
	Stack NumStack = InitStack();
	char sss;
	// int count = 0;
	while('\n' != (sss = getchar()))
	{
		if(sss >= '0' && sss <='9')
		{
			// count++;
			PushInStack(&NumStack, CharToNum(sss));
			// printf("%hhd" ,);
		}
	}
	// printf("\ncount = %d\n", count);
	if(PrintStack(&NumStack, "%hhu "))
	{
		perror("err");
		return ERR_MALLOC;
	}
	return ERR_NO;
}
