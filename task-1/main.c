// 2110541, benas.budrys@mif.stud.vu.lt, 1 užduotis, 6 variantas

#include <stdio.h>

#define NUMBER_OFFSET 48
#define DIGIT_COUNT 10

int isSquare(int number){
    // int i = 0 below if you want to include 0 in the sequence
    for (int i = 1; i*i <= number; i++)
    {
        if (number == i*i) return 1;
    }

    return 0;
}

int isDigit(char c){
    return (c >= NUMBER_OFFSET) && (c < NUMBER_OFFSET + DIGIT_COUNT);
}

int main() {
    int number = -1, squareCount = 0;

    do
    {
        char c;
        do{
            c = getchar();
        }while(c == ' ' || c == '\n');

        int sign = 1;
        if (c == '-'){
            sign = -1;

            // Check if the following char is a digit (negative int)
            c = getchar();
            if (!isDigit(c)){

                printf("Bad input. Please try again and enter an integer.\n");
                
                // Skip until the end of string
                while(!(c == ' ' || c == '\n')){
                    c = getchar();
                }

                continue;
            }
        }
        
        number = 0;

        do
        {
            if (!isDigit(c))
            {
                printf("Bad input. Please try again and enter an integer.\n");

                // Skip until the end of string
                do{
                    c = getchar();
                }while(!(c == ' ' || c == '\n'));

                number = -1;
                break;
            }

            number = number * DIGIT_COUNT + (c - NUMBER_OFFSET) * sign;
            c = getchar();
        }while (!(c == ' ' || c == '\n'));

        if (isSquare(number)) squareCount++;
    } while (number != 0);
    
    printf("%d\n", squareCount);
}