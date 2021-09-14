// 2110541, benas.budrys@mif.stud.vu.lt, 1 užduotis, 6 variantas

#include <stdio.h>

int main() {
    int number;
    printf("Enter number #1:\n");
    scanf("%d", &number);

    printf("Padvigubintas skaicius:\n%d\n", number*2);

    printf("Enter number #2:\n");
    scanf("%d", &number);

    printf("Patrigubintas skaicius:\n%d\n", number*3);
}