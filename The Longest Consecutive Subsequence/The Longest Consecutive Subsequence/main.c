#define _CRT_SECURE_NO_WARNINGS
#include "MyLibrary.h"

void main()
{

    int32_t arr[MaxarraySize] = { 0 };
    char input[MaxarraySize] = { '\0' };
    uint8_t x = 0;
    uint8_t n = 0;
    uint8_t cont = 'y';

    while(cont == 'y')
    {
        printf("\nPlease enter an array of elements to check : ");
        getExpression(input, arr, &n);
        //insertionSort(arr, n);
        lcsGetSize(arr, n, &x);
        printf("\n----------------------------------------------------------------------------------------------------------\n");
        printf("\nPress Any Key to Exit or Y to continue \n");
        cont = getch();
        cont = tolower(cont);
    }

}
