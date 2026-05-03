#include <stdio.h>
#define MAX 100

// Function to print array
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// ----------- MERGE STEP -----------
void merge(int arr[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = 0;
    int temp[MAX];

    // Merge the two halves into temp[]
    while(i <= mid && j <= right)
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // Copy remaining elements of left half
    while(i <= mid)
        temp[k++] = arr[i++];

    // Copy remaining elements of right half
    while(j <= right)
        temp[k++] = arr[j++];

    // Copy back to original array
    for(i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

// ----------- DIVIDE STEP (RECURSION) -----------
void mergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;

        // Divide: sort left half
        mergeSort(arr, left, mid);

        // Divide: sort right half
        mergeSort(arr, mid + 1, right);

        // Merge both halves
        merge(arr, left, mid, right);
    }
}

// ----------- MAIN FUNCTION -----------
int main()
{
    int n, arr[MAX];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("\nOriginal array: ");
    printArray(arr, n);
    mergeSort(arr, 0, n - 1);
    printf("Sorted array: ");
    printArray(arr, n);
    getch();
    return 0;
}
