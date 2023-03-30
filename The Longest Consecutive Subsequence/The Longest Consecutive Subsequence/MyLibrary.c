#include "MyLibrary.h"

int8_t insertionSort(int32_t* array, uint8_t arraySize)
{
	for (int i = 1; i < arraySize ; i++)
	{
		int8_t temp = array[i];
		int j=i - 1;
		while (j >= 0 && array[j] > temp)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = temp;
	}
	if (array[arraySize - 1] == 0 && array[0] == 0)
	{
		printf("\nArray Size is 0 \n");
		return -2;
	}
	else if(arraySize > 10)
	{
		printf("\nData entered exceeds the limit !!\n");
		return -2;

	}
	printArray(array, arraySize);
	return 0;

}

void printArray(int32_t* array, uint8_t arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		printf("arr[%d] = %hhd \n", i, array[i]);
	}
}

int8_t lcsGetSize(int32_t* array, uint8_t arraySize, uint8_t* sizeofLCS)
{		
	if(insertionSort(array, arraySize)==-2)
	{
		return -2;
	}
	uint8_t count = 0;
	uint8_t	max_count = 0;
	for (int i = 0; i < arraySize;i++)
	{
		if (array[i + 1] - array[i] == 1)
		{
			count = (count == 0) ? 1 :(count=count) ;
			count++;
		}
		else
		{
			if(count > max_count)
			{
				max_count = count;
			}
			count = 0;
		}
	}
	*sizeofLCS = max_count;
	if (max_count == 0)
	{
		printf("\nNo Consecutive Subsequence\n");
		return -3;
	}

	printf("\nLongest Consecutive Subsequence is %d\n",max_count);
	return 0;
}

int8_t getExpression(char* inputArray, int32_t* array, uint8_t* n)
{
	*n = 0;
	fgets(inputArray, MaxarraySize, stdin);
	//printf("\n%d\n", strlen(inputArray));

	if (inputArray[0]== '\n')
	{

		printf("\nNo Data Entered, Array is Empty\n");
		return -1;
	}

	int index = -1; //index for 2nd array
	int startIndex = -1; //index
	for (int i = 0; i < MaxarraySize && inputArray[i] != '\0'; i++)
	{
		if (inputArray[i] == '[')
		{
			if (inputArray[i + 1] == ']')
			{
				printf("\nNo Data Entered, Array is Empty\n");
				return -1;
			}
			index = 0;
		}
		else if (index == -1)
		{
			continue;
		}
		else if ((inputArray[i] == ',' || inputArray[i] == ']'))
		{
			char str[4] = { '\0' };
			for (int j = startIndex; j < i && (j - startIndex) < 4;j++)
			{
				str[j - startIndex] = inputArray[j];
			}
			char* endPtr;
			*n+=1;
			array[index++] = strtol(str, &endPtr, 10);
			startIndex = -1;
			if (inputArray[i] == ']')
				break;
		}
		else if (startIndex == -1)
		{
			startIndex = i;
		}
	}
	return 0;
}
