#include "Stack.h"

uint8_t StackSize(Stack *S)
{
	return S->num;
}

Stack InitStack(void)
{
	Stack ret = {0, NULL};
	return ret;
}

uint8_t PushInStack(Stack *S, uint8_t num)
{
	S->num++;//Увеличение размера стека
	
	//Выделение памяти под элементы, проверка
	uint8_t *newstack = (uint8_t*)realloc(S->stack, S->num);
	if(!newstack)
	{	//освобождение прошлой памяти, возврат ошибки
		free(S->stack);
		return ERR_MALLOC;
	}
	//Новая память записывается в стек
	S->stack = newstack;

	//Запись нового числа в вершину
	S->stack[S->num - 1] = num;
	return ERR_NO;
}

uint8_t ReadTopFromStack(Stack *S)
{	//Чтение вершины
	return S->stack[S->num - 1];
}

uint8_t PullFromStack(Stack *S, uint8_t *num)
{	//Возврат числа из вершины стека
	*num = ReadTopFromStack(S);
	S->num--;//Уменьшение размеров стека

	//Если после уменьшения стек не обратился в 0
	if(S->num /*!= 0*/)
	{	//Выделение памяти под динамическую область, проверка
		uint8_t *newstack = (uint8_t*)realloc(S->stack, S->num);
		if(!newstack)
		{
			free(S->stack);
			return ERR_MALLOC;
		}
		//Запись новой памяти обратно в стек
		S->stack = newstack;
	}
	//Если же стек опустел
	else 
	{	//Динамическая область освобождается
		free(S->stack);
		//Записывается признак свободной памяти NULL
		S->stack = NULL;
	}
	//Возврат кода отсутствия ошибок
	return ERR_NO;
}

uint8_t PrintStack(Stack *S, const char *fmt)
{	
	uint8_t el;//элемент, в который будет записыватся число
	
	//Цикл перебора, пока в стеке есть число
	while (S->num)
	{	//Осуществляется исключающее чтение
		if(PullFromStack(S, &el))
			return ERR_MALLOC;

		//Вывод каждого элемента в соответствии с форматом
		printf(fmt,el);
	}
	//Перенос строки в конце
	putchar('\n');
	return ERR_NO;
}

void SilentfreeStack(Stack *S)
{	//Освобождение памяти, запись признаков
	free(S->stack);
	S->stack = NULL;
	S->num = 0;
}
