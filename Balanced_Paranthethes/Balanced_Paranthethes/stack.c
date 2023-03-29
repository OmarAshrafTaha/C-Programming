#include "stack.h"
#include <stdio.h>


/*Creates an Empty Stack
*@param takes the address of Type "ST_Stack_t" and intializes the Stack with 0 and sets the stack top to -1
*/
void createEmptyStack(ST_stack_t *stack)
{
	for (int i = 0; i < STACK_SIZE; i++)
	{
		stack->elements[i] = 0;
	}

	stack->top = -1;
}

/*Pushes Values to the top of the Stack
*@param Takes the address of Type "ST_Stack_t" and a value 
*/
int8_t push(ST_stack_t* stack, uint8_t data)
{
	if (isFull(stack) == -1)
	{
		return -1;
	}
	stack->elements[++(stack->top)]=data;
	return 0;
}
/*Pops Values from the top of the Stack
*@param Takes the address of Type "ST_Stack_t" and the address of the variable that will store the popped slot into
*/
int8_t pop(ST_stack_t* stack, uint8_t *data)
{
	if (isEmpty(stack) == -2)
	{
		return -2;
	}

	getStackTop(stack, data);
	stack->elements[(stack->top)]=0;
	stack->top--;
	return 0;
}

/*Gets the Value at the top of the Stack
*@param Takes the address of Type "ST_Stack_t" and the address of the variable that will store the data found at the top of the stack into it
*/
int8_t getStackTop(ST_stack_t* stack, uint8_t *topData)
{
	if (isEmpty(stack) == -2)
	{
		*topData = NULL;
		return -2;
	}
	*topData = stack->elements[stack->top];
	return 0;
}
/*Checks if Stack is Full
*@param Takes the address of Type "ST_Stack_t" and the address of the variable that will store the popped slot into
*/
int8_t isFull(ST_stack_t* stack)
{
	if ((stack->top) == (STACK_SIZE - 1))
	{

		return -1;
	}
	return 0;
}
/*Checks if Stack is Empty
*@param Takes the address of Type "ST_Stack_t" and the address of the variable that will store the popped slot into
*/
int8_t isEmpty(ST_stack_t* stack)
{
	if ((stack->top) == -1)
	{

		return -2;
	}
	return 0;
}
/*Prints the stack
*@param Takes the address of Type "ST_Stack_t" 
*/
int8_t printStack(ST_stack_t* stack)
{
	
	if (isEmpty(stack) == -2)
	{
		return -2;
	}
	uint8_t temp = 0;
	pop(stack, &temp);
	printf("-----");
	printf("\n| %c |\n", temp);
	printStack(stack);
	push(stack, temp);

	return 0;

}


