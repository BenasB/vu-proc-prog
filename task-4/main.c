#include <stdio.h>
#include <stdlib.h>
#include "list.h"

FILE *openFile()
{
    char inputFileName[MAX_FILE_NAME];
    printf("Enter input file name: ");

    // Dynamically limit file name length so that it doesn't go out of bounds
    // https://stackoverflow.com/a/28460098
    char fileNameFormat[8];
    snprintf(fileNameFormat, sizeof(fileNameFormat), "%%%ds", MAX_FILE_NAME - 1);
    scanf(fileNameFormat, inputFileName);

    return fopen(inputFileName, "r+");
}

int main()
{
    printf("Options:\n0. Create the list from input file\n1. Print list\n2. Remove smallest element from list\nAny other number - quit\n\nSelect option: ");

    int selectedOption;
    struct Node *startingNode = NULL;
    while (1)
    {
        int scannedOptionCount = scanf("%d", &selectedOption);

        if (scannedOptionCount == 0)
        {
            printf("I don't know this option, try again: ");
            scanf("%*[^\n]");
            continue;
        }

        switch (selectedOption)
        {
        case 0:
            if (startingNode == NULL)
            {
                FILE *inputFile = openFile();
                if (inputFile == NULL)
                {
                    printf("Error while opening the input file\n");
                }
                else
                {
                    int failed = createList(inputFile, &startingNode);

                    if (failed)
                    {
                        if (startingNode != NULL)
                        {
                            freeList(startingNode);
                            startingNode = NULL;
                        }
                    }
                    else
                    {
                        printf("The list was created successfully\n");
                    }
                }
            }
            else
            {
                printf("A list already exists\n");
            }
            break;

        case 1:
            if (startingNode != NULL)
            {
                printList(startingNode);
                printf("\n");
            }
            else
            {
                printf("Create the list first.\n");
            }
            break;

        case 2:
            if (startingNode != NULL)
            {
                startingNode = removeSmallest(startingNode);
                printf("Element removed.\n");
            }
            else
            {
                printf("Create the list first.\n");
            }
            break;

        default:
            if (startingNode != NULL)
                freeList(startingNode);

            return 0;
        }

        printf("Select option: ");
    }
}
