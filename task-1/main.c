// 2110541, benas.budrys@mif.stud.vu.lt, 1 užduotis, 6 variantas

#include <stdio.h>

int isSquare(int number){
    // int i = 0 below if you want to include 0 in the sequence
    for (int i = 1; i*i <= number; i++)
    {
        if (number == i*i) return 1;
    }

    return 0;
}

int main() {
    int number, squareCount = 0;

    do
    {
        scanf("%d", &number);

        // Validate here

        if (isSquare(number)) squareCount++;
    } while (number != 0);
    
    printf("%d\n", squareCount);
}