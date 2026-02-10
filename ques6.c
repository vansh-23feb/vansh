#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
struct Employee
{
    int id;
    char name[20];
    int salary;
};
int main()
{
    int n, i,maxsalary=0;
    struct  Employee *e;
    clrscr();
    printf("Enter number of employees: ");
    scanf("%d", &n);
    e = (struct Employee *)malloc(n * sizeof(struct Employee));
    if (e == NULL)
    {
      printf("Memory allocation failed!\n");
      return 1;
    }
     for (i = 0; i < n; i++)
    {
     printf("\nEnter details for employee %d\n", i + 1);
     printf("Employee Id: ");
     scanf("%d", &e[i].id);
     printf("Name: ");
     scanf("%s", e[i].name);
     printf("Salary: ");
     scanf("%d", &e[i].salary);
    }
    for(i=1;i<n;i++)
    {
     if(e[i].salary>e[maxsalary].salary)
     {
      maxsalary=i;
     }
    }
     printf("\n--- Employee Detail with highest salary ---\n");
     printf("Employee id: %d\n", e[maxsalary].id);
     printf("Name: %s\n", e[maxsalary].name);
     printf("Salary: %d\n", e[maxsalary].salary);
     free(e);
     getch();
     return 0;
}
