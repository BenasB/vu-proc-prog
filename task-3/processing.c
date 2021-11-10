#include <stdlib.h>
#include <string.h>
#include "processing.h"

int isDigit(Symbol c)
{
    return (c >= '0') && (c <= '9');
}

int isWhitespace(Symbol c)
{
    return (c == ' ') || (c == '\n');
}

Symbol *processLine(Line line)
{
    Symbol *processedLine = calloc(MAX_LINE_LENGTH, sizeof(Symbol));

    int wordStart = 0;
    int wordEnd = -1;
    for (int i = 0; i < strlen(line); i++)
    {
        if (isWhitespace(line[i]) || i == strlen(line) - 1)
        {
            if (!isWhitespace(line[i]))
                wordEnd = i;

            if (wordEnd >= wordStart) // Found a word
            {
                int wordLength = wordEnd - wordStart + 1;

                // Decide if we need to add the word or not
                if (wordLength % 2 == 0 || !isDigit(line[wordStart + wordLength / 2]))
                {
                    strncat(processedLine, &line[wordStart], wordLength);
                }
            }

            // Add spaces since the number of spaces should not change
            if (line[i] == ' ')
            {
                strncat(processedLine, &line[i], 1);
                wordStart = i + 1;
            }
        }
        else
        {
            // We're finding a word, keep looking for it's end
            wordEnd = i;
        }
    }

    return processedLine;
}