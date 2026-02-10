#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
struct Student
{
    int rollNo;
    char name[20];
    int marks;
};
int main()
{
    int n, i;
    struct Student *s;
    clrscr();
    printf("Enter number of students: ");
    scanf("%d", &n);
    s = (struct Student *)malloc(n * sizeof(struct Student));
    if (s == NULL)
    {
	printf("Memory allocation failed!\n");
	return 1;
    }
    for (i = 0; i < n; i++)
    {
	printf("\nEnter details for student %d\n", i + 1);
	printf("Roll No: ");
	scanf("%d", &s[i].rollNo);
	printf("Name: ");
	scanf("%s", s[i].name);
	printf("Marks: ");
	scanf("%d", &s[i].marks);
    }
    printf("\n--- Student Details ---\n");
    for (i = 0; i < n; i++)
    {
	printf("\nStudent %d\n", i + 1);
	printf("Roll No : %d\n", s[i].rollNo);
	printf("Name    : %s\n", s[i].name);
	printf("Marks   : %d\n", s[i].marks);
    }
    free(s);
    getch();
    return 0;
}
