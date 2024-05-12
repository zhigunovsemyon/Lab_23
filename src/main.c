#include "Stack.h" //включает stdio, stdint, malloc

//Конвертирует символ, являющийся цифрой, в эту цифру
uint8_t CharToNum(char c)
{
	return c - '0';
}

//Проверяет, принадлежит ли данный символ к цифрам
uint8_t CharIsNum(char c)
{
	return (c >= '0' && c <='9');
}

int main(void)
{
	Stack //Стек чисел
		NumStack = InitStack();

	char //Символ, в который записывается число
		c;

	/* Цикл ввода чисел, пока не нажат Enter */
	while('\n' != (c = getchar()))
		if(CharIsNum(c))	//Если символ является числом, он записывается в стек
			if(PushInStack(&NumStack, CharToNum(c)))
				return ERR_MALLOC;//Возврат кода ошибки, если malloc не выделил память

	//Если в стек были записаны элементы, они будут выведены
	if(StackSize(&NumStack))
	{
		//Вывод стека, вместе с его уничтожением, проверка malloc
		if(PrintStack(&NumStack, "%hhu "))
			return ERR_MALLOC;
	}
	else //В противном случае предупреждение
		puts("Стек пустой!");
	
	//Завершение работы
	return ERR_NO;
}
