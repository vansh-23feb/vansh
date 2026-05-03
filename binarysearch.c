#include <stdio.h>
#define MAX 100

// Recursive Binary Search function
int binarySearch(int arr[], int low, int high, int key)
{
    if(low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] == key)
            return mid;   // element found

        else if(arr[mid] > key)
            return binarySearch(arr, low, mid - 1, key);
        else
            return binarySearch(arr, mid + 1, high, key);
    }

    return -1; // element not found
}
int main()
{
    int arr[MAX], n, key, result;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d sorted integers:\n", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, 0, n - 1, key);

    if(result != -1)
        printf("Element found at index: %d", result);
    else
        printf("Element not found in the array.");
    getch();
    return 0;
}
