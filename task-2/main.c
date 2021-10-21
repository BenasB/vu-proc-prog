// 2110541, benas.budrys@mif.stud.vu.lt, 2 užduotis, 10 variantas

#include <stdio.h>
#include <stdlib.h>
#include "validation.h" // Compiler sees it from /usr/local/include (installed separately, see ./readme.md)

int* filter(int array[], int arraySize, int *filteredSize, int condition(int)){
    // Based on: https://stackoverflow.com/a/11656585
    int *filtered = malloc(sizeof(int) * arraySize);
    *filteredSize = 0;

    if(!filtered)
        return NULL;

    for (int i = 0; i < arraySize; i++)
    {
        if (condition(array[i]))
        {
            filtered[*filteredSize] = array[i];
            (*filteredSize)++;
        }
    }

    return filtered;
}

int isNegative(int element)
{
    return element < 0;
}

int isNonNegative(int element)
{
    return !isNegative(element);
}

void printArray(int array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ", array[i]);
    }
}

int main()
{
    int arraySize;

    printf("Enter array size: ");

    while (getInteger(&arraySize) || arraySize <= 0)
    {
        printf("Bad input\n");
    }

    printf("Enter array elements: ");

    int mixedArray[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        while (getInteger(&mixedArray[i]))
        {
            printf("Bad input\n");
        }
    }

    int filteredSize;
    int *negatives = filter(mixedArray, arraySize, &filteredSize, isNegative);
    if (negatives)
    {
        printArray(negatives, filteredSize);
        free(negatives);
    }

    int *nonNegatives = filter(mixedArray, arraySize, &filteredSize, isNonNegative);
    if (nonNegatives)
    {
        printArray(nonNegatives, filteredSize);
        free(nonNegatives);
    }

    printf("\n");
}
