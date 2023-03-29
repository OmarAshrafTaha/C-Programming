#include "MyLibrary.h"


uint8_t board[9] = { '1','2','3','4','5','6','7','8','9' }; 
uint8_t configArray[2];

//Prints the board to the console
//@param board array that stores the board positions and symbols

void drawBoard(uint8_t* board) 
{	
	printf("\n------------- \n");
	for (int i = 0;i < 9;i++)
	{
		printf("| %c ", board[i]);

		if ((i + 1) % 3 == 0) 
		{
			printf("| \n");
			printf("------------- \n");
		}
	}
}

//Update the board positions with symbols which the player chose
//@param board,position and value

void updateBoard(uint8_t* board, uint8_t position, uint8_t value) // This function will take the board, position to update and value to set in this position.
{
	board[position-1] = value;
}

//Checks the Player input data before storing it into the configArray
//@param 

uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t* symbol)
{	
	printf("\nPlease Choose a Symbol for player %d : ", playerNumber);
	scanf_s(" %c", & symbol);
	
	
	symbol = toupper(symbol);


	if (symbol != 'X' && symbol != 'O')
	{
		printf("Chosen Symbol Is Wrong, Please Try Again \n");
		return 1;
	}
	else if (playerNumber == 1 || symbol != configArray[0])
	{
		configArray[playerNumber - 1] = symbol;
		return 0;
	}
	
	printf("Chosen Symbol Is Already Picked, Please Try Again \n");
	return 1;
	
	
}

//Sets the preffered symbol for each player and saves it in configArray
void setPlayerConfig(uint8_t* configArray)
{
	while (getPlayerSymbol(1, configArray[0]) == 1)
	{

	}

	while (getPlayerSymbol(2, configArray[1]) == 1)
	{

	}
	
}

//Takes and Checks player input position for symbol placement and updates the board with the new ipnuts
void loadAndUpdate(uint8_t playerNumber)
{
	uint8_t position =0 ;
	
	printf("\nPlease Enter A Position To Place Your Symbol At : ");
	scanf_s(" %hhu", &position);
	getchar();


	while ( (position > 9) || (position < 1) || (board[position - 1] == 'X') || (board[position - 1] == 'O') )
	{
		//printf("\nPosition = %hhu : ",position);
		printf("\nInvalid Entry, Please Enter A Correct Position : ");
		scanf_s(" %hhu", &position);
		fflush(stdin);
		getchar();
		
	}

	
	updateBoard(board, position, configArray[playerNumber-1]);
}

//Keep Checking if there's any win or draw conditions every iteration
void getGameState(uint8_t* board, uint8_t* gameState)
{

	if ((board[0]) == (board[1]) && (board[0]) == (board[2])) //check first row
	{
		*gameState = 0;
		return 0;
	}
	if ((board[3]) == (board[4]) && (board[3]) == (board[5])) //check 2nd row
	{
		*gameState = 0;
		return;
	}
	if ((board[6]) == (board[7]) && (board[6]) == (board[8])) //check 3rd row
	{
		*gameState = 0;
		return;
	}

	if ((board[0]) == (board[3]) && (board[0]) == (board[6])) //check first coloumn
	{
		*gameState = 0;
		return;
	}
	if ((board[1]) == (board[4]) && (board[1]) == (board[7])) //check 2nd coloumn
	{
		*gameState = 0;
		return;
	}
	if ((board[2]) == (board[5]) && (board[2]) == (board[8])) //check 3rd coloumn
	{
		*gameState = 0;
		return;
	}

	if ((board[0]) == (board[4]) && (board[0]) == (board[8])) //check Diagonal ( \ )
	{
		*gameState = 0;
		return;
	}
	if ((board[2]) == (board[4]) && (board[2]) == (board[6])) //check Diagonal ( / )
	{
		*gameState = 0;
		return;
	}


	
		for (int i = 0;i < 9;i++)
		{
			if (board[i] != 'X' && board[i] != 'O')
			{
				*gameState = 2;
				return;
			}
		}
		*gameState = 1;
		return;

}

//intialization function that calls all the above in the appropriate order
void start()
{
	uint8_t gameState = 2;
	uint8_t currentPlayer = 0;

	setPlayerConfig(configArray);


	while (gameState ==2 )
	{
		drawBoard(board);
		loadAndUpdate(currentPlayer + 1);
		getGameState(board,&gameState);
		currentPlayer ^= 1;
	}
	drawBoard(board);
	if (gameState == 1)
	{
		printf("\nResult is a Draw !!\n");
	}
	else
	{
		printf("\nPlayer %d Won !!\n",(currentPlayer^1)+1);
	}
}