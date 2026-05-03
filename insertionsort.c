#include <stdio.h>
#define MAX 100   // to avoid constant expression error
// Function to print array
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Insertion Sort function
void insertionSort(int arr[], int n)
{
    int i, j, key;

    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        // Shift elements greater than key
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        // Display array after each insertion
        printf("After inserting element %d: ", key);
        printArray(arr, n);
    }
}



int main()
{
    int n, arr[MAX];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nOriginal array: ");
    printArray(arr, n);
    insertionSort(arr, n);
    printf("\nSorted array: ");
    printArray(arr, n);
    getch();     
    return 0;
}
