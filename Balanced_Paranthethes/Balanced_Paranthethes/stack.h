#pragma once

#include "stdint.h"
#define STACK_SIZE 10

//typedef to make a datatype that has consecutive slots allocated for it depending on the stack size chosen and has a variable which keeps the index of the top value in the stack
typedef struct stack
{
	uint8_t elements[STACK_SIZE];
	int8_t top;

}ST_stack_t;

//Creates an Empty Stack and initalizes it with zeros
void createEmptyStack(ST_stack_t* stack);

//Push a value to the stack which are both passed to the function on call
int8_t push(ST_stack_t* stack, uint8_t data);

//Pops a value from the stack and 
int8_t pop(ST_stack_t* stack, uint8_t *data);

//Print the stack
int8_t printStack(ST_stack_t* stack);

//Saves the value at the top of the stack
int8_t getStackTop(ST_stack_t* stack, uint8_t *topData);

//checks if stack is full
int8_t isFull(ST_stack_t* stack);

//checks if stack is empty
int8_t isEmpty(ST_stack_t* stack);
