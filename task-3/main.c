// 2110541, benas.budrys@mif.stud.vu.lt, 3 užduotis, 9 variantas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processing.h"

int main()
{
    FileName inputName;
    printf("Enter input file name: ");

    // Dynamically limit file name length so that it doesn't go out of bounds
    // https://stackoverflow.com/a/28460098
    char fileNameFormat[8];
    snprintf(fileNameFormat, sizeof(fileNameFormat), "%%%ds", MAX_FILE_NAME - 1);
    scanf(fileNameFormat, inputName);

    FILE *inputFile = fopen(inputName, "r");
    if (inputFile == NULL)
    {
        printf("Error while opening the input file: %s\n", inputName);
        return 1;
    }

    FileName outputName;
    printf("Enter output file name: ");
    scanf(fileNameFormat, outputName);

    FILE *outputFile = fopen(outputName, "w");
    if (outputFile == NULL)
    {
        printf("Error while opening/creating the output file: %s\n", outputName);
        return 1;
    }

    // Iterate through all lines
    Line line;
    int newLine = 0;
    while (fgets(line, sizeof line, inputFile) != NULL)
    {
        if (newLine)
            fprintf(outputFile, "\n");
        newLine = 1;

        // Skip until new line if the line length goes above MAX_LINE_LENGTH - 1
        if (strlen(line) == MAX_LINE_LENGTH - 1 && line[MAX_LINE_LENGTH - 2] != '\n')
        {
            fscanf(inputFile, "%*[^\n]%*c");
        }

        Symbol *processedLine = processLine(line);
        fprintf(outputFile, "%s", processedLine);
        free(processedLine);
    }

    fclose(inputFile);
    fclose(outputFile);
}