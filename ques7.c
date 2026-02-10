#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
struct Student
{
    int roll;
    char name[50];
    int marks;
};
int main()
{
   struct Student *s=NULL;
   int choice, count = 0, i,j, roll, found;
   clrscr();
   while (1)
   {
    printf("\n----- MENU -----\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Delete Record\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
     case 1:   // Add record
     count++;
     s = (struct Student *)realloc(s, count * sizeof(struct Student));
     if (s == NULL)
     {
      printf("Memory allocation failed!\n");
      return 1;
     }
      printf("Enter Roll No: ");
      scanf("%d", &s[count - 1].roll);
      printf("Enter Name: ");
      scanf(" %s", s[count - 1].name);
      printf("Enter Marks: ");
      scanf("%d", &s[count - 1].marks);
      break;
      case 2:   // Display records
      if (count == 0)
      {
	printf("No records to display.\n");
      }
      else
      {
	printf("\nStudent Records:\n");
	for (i = 0; i < count; i++)
	{
	 printf("Roll: %d, Name: %s, Marks: %d\n",s[i].roll, s[i].name, s[i].marks);
	}
       }
	break;
	case 3:   // Delete record
	if (count == 0)
	{
	 printf("No records to delete.\n");
	 break;
	}
	 printf("Enter Roll No to delete: ");
	 scanf("%d", &roll);
	 found = 0;
	 for (i = 0; i < count; i++)
	 {
	   if (s[i].roll == roll)
	   {
	     found = 1;
	     for (j = i; j < count - 1; j++)
	     {
	      s[j] = s[j + 1];
	     }
	     count--;
	     s = (struct Student *)realloc(s, count * sizeof(struct Student));
	     printf("Record deleted successfully.\n");
	     break;
	    }
	  }
	    if (!found)
	    {
	     printf("Record not found.\n");
	    }
	     break;
	     case 4:   // Exit
	      free(s);
	      printf("Memory freed. Program exited.\n");
	      getch();
	      return 0;
	      default:
		printf("Invalid choice! Try again.\n");
    }
   }
}
