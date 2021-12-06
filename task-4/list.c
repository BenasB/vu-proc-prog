#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct Node *createNode(int data, struct Node *previousNode)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->previous = previousNode;
    newNode->next = NULL;

    if (previousNode != NULL)
    {
        previousNode->next = newNode;
    }

    return newNode;
}

int createList(FILE *stream, struct Node **startingNode)
{
    int currentNumber;
    struct Node *previousNode = NULL;
    int scanResult = fscanf(stream, "%d", &currentNumber);
    while (scanResult != EOF)
    {
        if (scanResult == 0)
        {
            printf("Error while parsing the input file.\n");
            fclose(stream);
            return 1;
        }

        struct Node *newNode = createNode(currentNumber, previousNode);
        previousNode = newNode;

        if (*startingNode == NULL)
            *startingNode = newNode;

        scanResult = fscanf(stream, "%d", &currentNumber);
    }

    fclose(stream);
    return 0;
}

void printList(struct Node *startingNode)
{
    printf("%d ", startingNode->data);

    if (startingNode->next != NULL)
        printList(startingNode->next);
}

struct Node *removeSmallest(struct Node *startingNode)
{
    // Determine smallest node
    struct Node *currentNode = startingNode;
    struct Node *smallestNode = currentNode;
    while (currentNode != NULL)
    {
        if (currentNode->data < smallestNode->data)
            smallestNode = currentNode;

        currentNode = currentNode->next;
    }

    // Adjust list links
    if (smallestNode->previous != NULL && smallestNode->next != NULL)
    {
        smallestNode->previous->next = smallestNode->next;
        smallestNode->next->previous = smallestNode->previous;
    }
    else if (smallestNode->previous != NULL)
    {
        smallestNode->previous->next = NULL;
    }
    else if (smallestNode->next != NULL)
    {
        smallestNode->next->previous = NULL;
        startingNode = smallestNode->next;
    }
    else
    {
        startingNode = NULL;
    }

    free(smallestNode);

    return startingNode;
}

void freeList(struct Node *startingNode)
{
    if (startingNode->next != NULL)
        freeList(startingNode->next);

    free(startingNode);
}