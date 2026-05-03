#include <stdio.h>
#define MAX 100   // to avoid "constant expression required" error
// Function to print array
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Selection Sort function
void selectionSort(int arr[], int n)
{
    int i, j, min_index, temp;
    int comparisons = 0, swaps = 0;
    for(i = 0; i < n - 1; i++)
    {
        min_index = i;

        for(j = i + 1; j < n; j++)
        {
            comparisons++;
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        // Swap only if needed
        if(min_index != i)
        {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
            swaps++;
        }

        // Display array after each pass
        printf("After pass %d: ", i + 1);
        printArray(arr, n);
    }

    // Display counts
    printf("\nTotal comparisons = %d\n", comparisons);

    printf("Total swaps = %d\n", swaps);
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
    selectionSort(arr, n);
    printf("\nSorted array: ");
    printArray(arr, n);
    getch();
    return 0;
}
