#include <stdio.h>
#include<conio.h>

/* Define a union */
union Data
{
    int i;
    float f;
    char c;
};
int main()
 {
    union Data data;
    clrscr();
    /* Store integer value */
    data.i = 10;
    printf("After storing integer:\n");
    printf("data.i = %d\n", data.i);
    printf("data.f = %f\n", data.f);
    printf("data.c = %c\n", data.c);

    /* Store float value */
    data.f = 220.5;
    printf("After storing float:\n");
    printf("data.i = %d\n", data.i);
    printf("data.f = %f\n", data.f);
    printf("data.c = %c\n", data.c);

    /* Store character value */
    data.c = 'A';
    printf("\nAfter storing character:\n");
    printf("data.i = %d\n", data.i);
    printf("data.f = %f\n", data.f);
    printf("data.c = %c\n", data.c);

    /* Size of union */
    printf("\nSize of union Data = %lu bytes\n", sizeof(data));
    getch();
    return 0;
}
