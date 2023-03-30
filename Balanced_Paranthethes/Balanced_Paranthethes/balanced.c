#include "balanced.h"
#include "stack.h"

/*Description : Creates an Empty stack and then starts checking each character in the expression if it is '{' or '(' 
* then pushes it to the stack if it's true and if the condition is false it checks if it's '}' or ')' and compares it to the top value at the stack if it's the right pair 
* then expression is balanced if not then not balanced 
*@param takes an Expression entered by the user
*/
int8_t isBalancedParanthethes(uint8_t* expression)
{
	ST_stack_t input_stack;
	createEmptyStack(&input_stack);
	uint8_t bracket_count = 0;
	

	for (int i = 0;i < strlen(expression);i++)
	{
		if (expression[i] == '{' || expression[i] == '(' || expression[i] == ')' || expression[i] == '}')
		{
			bracket_count;
		}
		else if ((bracket_count == 0) && (i == strlen(expression) - 1))
		{
			printf("\nNo Brackets Detected\n");
			return -2;
		}

		if (expression[i] == '{' || expression[i] == '(')
		{

			push(&input_stack, expression[i]);

		}
		else 
		{
			uint8_t top;
			getStackTop(&input_stack, &top);
			if (expression[i] == '}' && top == '{') 
			{
				pop(&input_stack, &top);
			}
			else if (expression[i] == ')' && top == '(')
			{
				pop(&input_stack, &top);
			}
			else if(expression[i] == '}' || expression[i] == ')' )
			{
				printf("\nExpression is not Balanced\n");
				return -1;

			}
		}
	}

	if(isEmpty(&input_stack))
	{
		printf("\nExpression is Balanced\n");
	
		return 0;

	}
	printf("\nExpression is not Balanced\n");
	return -1;

}
