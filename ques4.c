# include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    int **a,**b,**sum,**diff;
    int r,c,i,j;
    clrscr();
    printf("Enter row and column in matrix=");
    scanf("%d %d",&r,&c);
    //Dynamic memory allocation for rows
    a=(int **)malloc(r * sizeof(int *));
    b=(int **)malloc(r * sizeof(int *));
    sum=(int **)malloc(r * sizeof(int *));
    diff=(int **)malloc(r * sizeof(int *));
    if(a==NULL || b==NULL || sum==NULL || diff==NULL)
    {
      printf("Memory allocation failed\n");
      return 1;
    }
    //Dynamic memory allocation for columns
    for(i=0;i<r;i++)
    {
     a[i]=(int *)malloc(c * sizeof(int *));
     b[i]=(int *)malloc(c * sizeof(int *));
     sum[i]=(int *)malloc(c * sizeof(int *));
     diff[i]=(int *)malloc(c * sizeof(int *));
    }
    if(a[i]==NULL || b[i]==NULL || sum[i]==NULL || diff[i]==NULL)
    {
      printf("Memory allocation failed\n");
      return 1;
    }
    printf("Enter elements in first matrix \n");
    for(i=0;i<r;i++)
    {
	for(j=0;j<c;j++)
	{
	    scanf("%d",&a[i][j]);
	}
    }
    printf("First matrix is\n");
    for(i=0;i<r;i++)
    {
	for(j=0;j<c;j++)
	{
	    printf("%d\t",a[i][j]);
	}
	printf("\n");
    }
    printf("Enter elements in second matrix \n");
    for(i=0;i<r;i++)
    {
	for(j=0;j<c;j++)
	{
	    scanf("%d",&b[i][j]);
	}
    }
    printf("Second matrix is\n");
    for(i=0;i<r;i++)
    {
	for(j=0;j<c;j++)
	{
	    printf("%d\t",b[i][j]);
	}
	printf("\n");
    }
   // Matrix Addition and substraction
    for(i=0;i<r;i++)
    {
	for(j=0;j<c;j++)
	{
	    sum[i][j]=a[i][j]+b[i][j];
	    diff[i][j]=a[i][j]-b[i][j];
	}
    }
    printf(" \n sum of the two matrices:\n");
    for(i=0;i<r;i++)
    {
	for(j=0;j<c;j++)
	{
	    printf("%d\t",sum[i][j]);
	}
	printf("\n");
    }
    printf(" \n Difference of the two matrices:\n");
    for(i=0;i<r;i++)
    {
	for(j=0;j<c;j++)
	{
	    printf("%d\t",diff[i][j]);
	}
	printf("\n");
    }
    //Free allocate memeory
    for(i=0;i<r;i++)
    {
     free(a[i]);
     free(b[i]);
     free(sum[i]);
     free(diff[i]);
    }
    free(a);
    free(b);
    free(sum);
    free(diff);
    getch();
    return 0;
}
