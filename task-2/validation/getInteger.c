// ADD DELIMITER
// ADD BAD INPUT CALLBACK
#include <stdio.h>
#include "validation.h"

int isDigit(char c)
{
    return (c >= '0') && (c <= '9');
}

int getInteger(int *number)
{

    char c = getchar();
    while (c == ' ' || c == '\n')
    {
        c = getchar();
    }

    int sign = 1;
    if (c == '-')
    {
        sign = -1;
        c = getchar();
    }

    *number = 0;
    int failedValidation = 0;

    do
    {
        if (!isDigit(c))
        {
            // Skip until the end of string
            while (!(c == ' ' || c == '\n'))
            {
                c = getchar();
            }

            failedValidation = 1;

            // Number until the bad character will be returned
            // Setting number = X here can change this behaviour to return an arbitrary number if validation failed
            break;
        }

        *number = *number * ('9' - '0' + 1) + (c - '0') * sign;
        c = getchar();
    } while (!(c == ' ' || c == '\n'));

    return failedValidation;
}