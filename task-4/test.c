#include <stdio.h>
#include <assert.h>
#include "list.h"

int countElements(struct Node *nextNode)
{
    if (nextNode == NULL)
        return 0;
    else
        return 1 + countElements(nextNode->next);
}

int valueExists(int value, struct Node *nextNode)
{
    if (nextNode == NULL)
        return 0;
    else if (nextNode->data == value)
        return 1;
    else
        return valueExists(value, nextNode->next);
}

void CREATE_LIST_GOOD_FILE_1()
{
    struct Node *startingNode = NULL;
    int failed = createList(fopen("input/file1.txt", "r+"), &startingNode);
    freeList(startingNode);
    assert(!failed);
}

void CREATE_LIST_GOOD_FILE_2()
{
    struct Node *startingNode = NULL;
    int failed = createList(fopen("input/file2.txt", "r+"), &startingNode);
    freeList(startingNode);
    assert(!failed);
}

void CREATE_LIST_GOOD_FILE_3()
{
    struct Node *startingNode = NULL;
    int failed = createList(fopen("input/file3.txt", "r+"), &startingNode);
    freeList(startingNode);
    assert(!failed);
}

void CREATE_LIST_PARSE_ERROR()
{
    struct Node *startingNode = NULL;
    int failed = createList(fopen("input/file4.txt", "r+"), &startingNode);
    freeList(startingNode);
    assert(failed);
}

void CREATE_LIST_GOOD_ELEMENT_COUNT()
{
    struct Node *startingNode = NULL;
    int failed = createList(fopen("input/file1.txt", "r+"), &startingNode);
    assert(!failed);

    assert(countElements(startingNode) == 9);
    freeList(startingNode);
}

void REMOVE_SMALLEST()
{
    struct Node *startingNode = NULL;
    int failed = createList(fopen("input/file3.txt", "r+"), &startingNode);
    assert(!failed);

    assert(countElements(startingNode) == 12);

    startingNode = removeSmallest(startingNode);

    assert(!valueExists(-5, startingNode));
    assert(valueExists(-2, startingNode));

    startingNode = removeSmallest(startingNode);

    assert(!valueExists(-2, startingNode));
    freeList(startingNode);
}

void REMOVE_ALL()
{
    struct Node *startingNode = NULL;
    int failed = createList(fopen("input/file1.txt", "r+"), &startingNode);
    assert(!failed);

    assert(countElements(startingNode) == 9);

    for (int i = 0; i < 9; i++)
    {
        startingNode = removeSmallest(startingNode);
    }

    assert(startingNode == NULL);
}

#define TEST_COUNT 7

int main()
{
    void (*tests[TEST_COUNT])() = {CREATE_LIST_GOOD_FILE_1, CREATE_LIST_GOOD_FILE_2, CREATE_LIST_GOOD_FILE_3, CREATE_LIST_PARSE_ERROR, CREATE_LIST_GOOD_ELEMENT_COUNT, REMOVE_SMALLEST, REMOVE_ALL};

    for (int i = 0; i < TEST_COUNT; i++)
    {
        tests[i]();
    }

    printf("All %d tests passed successfully\n", TEST_COUNT);
    return 0;
}
