#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
int *arr;
int n,i,sum=0;
float avg=0;
clrscr();
printf("Enter the number of elements=");
scanf("%d",&n);
//Dynamic memory allocation
arr=(int *)malloc(n * sizeof(int));
if(arr==NULL)
{
   printf("Memory allocation failed\n");
   return 1;
}
//Input elements in array
printf("Enter %d elements in array\n",n);

for(i=0;i<n;i++)
{
 scanf("%d",&arr[i]);
}
//Dispaly elements of array
printf("Array elements are=");
for(i=0;i<n;i++)
{
 printf("%d",arr[i]);
}
//Sum of elements of array
for(i=0;i<n;i++)
{
 sum=sum+arr[i];
}
printf("\nSum of elements of an array=%d\n",sum);
//average of elements of array
for(i=0;i<n;i++)
{
 avg=sum/n;
}
printf("Average of elements of an array=%f",avg);
//Free allocate memeory
free(arr);
getch();
return 0;
}
