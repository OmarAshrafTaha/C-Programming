#include "main.h"


void main()
{
	ST_stack_t input_stack;
	ST_stack_t user_stack;
	uint8_t data;
	uint8_t	stack_top;

	createEmptyStack(&input_stack);
	push(&input_stack, '(');
	push(&input_stack, '{');
	push(&input_stack, '2');
	push(&input_stack, '4');
	push(&input_stack, ')');
	printStack(&input_stack);
	printf("\n----------Test 3-----------\n\n");
	pop(&input_stack, &data);
	getStackTop(&input_stack, &stack_top);
	printf("Stack Top is : %c \n", stack_top);
	printf("\n----------Test 5-----------\n\n");
	printStack(&input_stack);
	printf("\n----------Test 6-----------\n\n");
	push(&input_stack, '5');
	push(&input_stack, '6');
	push(&input_stack, '7');
	push(&input_stack, '8');
	push(&input_stack, '9');
	push(&input_stack, '+');
	push(&input_stack, '-');
	getStackTop(&input_stack, &stack_top);
	printf("Stack Top is : %c \n", stack_top);
	printf("\n----------Test 8-----------\n\n");
	printStack(&input_stack);
	printf("\n----------Test 9-----------\n\n");
	pop(&input_stack, &data);
	pop(&input_stack, &data);
	pop(&input_stack, &data);
	pop(&input_stack, &data);
	getStackTop(&input_stack, &stack_top);
	printf("Stack Top is : %c \n", stack_top);
	printf("\n----------Test 11-----------\n\n");
	printStack(&input_stack);
	printf("\n----------Test 12-----------\n\n");
	pop(&input_stack, &data);
	pop(&input_stack, &data);
	pop(&input_stack, &data);
	pop(&input_stack, &data);
	pop(&input_stack, &data);
	pop(&input_stack, &data);
	pop(&input_stack, &data);
	getStackTop(&input_stack, &stack_top);
	printf("Stack Top is : %c \n", stack_top);
	printf("\n----------Test 14-----------\n\n");
	printStack(&input_stack);
	printf("\n----------Test 15-----------\n\n");

	while (1)
	{	
		printf("\nPlease Enter an Expression to Check : ");

		char expression[50] = "\0";
		gets(expression);
		isBalancedParanthethes(expression);

	}
	



}
