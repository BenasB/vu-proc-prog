#ifndef LIST_H
#define LIST_H

#define MAX_FILE_NAME 64

struct Node
{
    int data;
    struct Node *next;
    struct Node *previous;
};

int createList(FILE *stream, struct Node **startingNode);
void printList(struct Node *startingNode);
struct Node *removeSmallest(struct Node *startingNode);
void freeList(struct Node *startingNode);

#endif