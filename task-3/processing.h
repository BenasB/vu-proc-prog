#ifndef PROCESSING_H
#define PROCESSING_H

#define MAX_FILE_NAME 64
#define MAX_LINE_LENGTH 256

typedef unsigned char Symbol;
typedef Symbol FileName[MAX_FILE_NAME];
typedef Symbol Line[MAX_LINE_LENGTH];

/**
* @brief Removes words that have a digit in the middle from a line
* @param line the line which to process
* @return null terminated dynamic Symbol array with MAX_FILE_NAME elements
*/
Symbol *processLine(Line line);

#endif