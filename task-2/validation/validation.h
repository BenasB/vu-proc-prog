#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

/**
* @brief Gets integer with validation (ignores spaces and new lines)
* @param number the number retrieved from the input. Can be passed in uninitialized
* @return 0 if validation was successful, !0 if it failed
*/
int getInteger(int *number);

#endif