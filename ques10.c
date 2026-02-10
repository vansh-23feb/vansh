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
    int n, i,j;
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
     // Sort students by marks in descending order using bubble sort
    for (i = 0; i < n - 1; i++)
     {
	for (j = 0; j < n - i - 1; j++)
	 {
	    if (s[j].marks < s[j + 1].marks)
	    {
		struct Student temp = s[j];
		s[j] = s[j + 1];
		s[j + 1] = temp;
	    }
	 }
      }
	// Display sorted student records
      printf("\n--- Student Records Sorted by Marks (Descending) ---\n");
      printf("%s %s %s\n", "Name", "Roll No", "Marks");
      for (i = 0; i < n; i++)
      {
	printf("%s %d %d\n", s[i].name, s[i].rollNo, s[i].marks);
      }
      // Free dynamically allocated memory
      free(s);
      getch();
      return 0;
}
