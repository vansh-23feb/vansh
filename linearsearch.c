#include <stdio.h>
#define MAX 100
int main()
{
    int arr[MAX], n, key;
    int found = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    printf("\nPositions of %d in the array: ", key);
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            printf("%d ", i + 1);  // 1-based indexing
            found = 1;
        }
    }
    if(!found)
    {
        printf("\nElement not found in the array.");
    }
    getch();
    return 0;
}
