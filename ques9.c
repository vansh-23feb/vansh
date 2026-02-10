#include<stdio.h>
#include<conio.h>

/* Define a structure */
struct MyStruct
{
    int i;
    float f;
    char c;
};

/* Define a union */
union MyUnion
{
    int i;
    float f;
    char c;
};

int main()
{
    struct MyStruct s;
    union MyUnion u;
    printf("Memory allocation:\n");
    printf("Size of struct MyStruct  = %lu bytes\n", sizeof(s));
    printf("Size of union MyUnion  = %lu bytes\n", sizeof(u));
    getch();
    return 0;
}
