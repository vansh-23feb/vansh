#include <stdio.h>
# define MAX 100
// Function to print array
void printArray(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
	printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort function
void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    int comparisons = 0, swaps = 0;
    for(i = 0; i < n - 1; i++)
    {
	for(j = 0; j < n - i - 1; j++)
	{
	    comparisons++;

	    if(arr[j] > arr[j + 1])
	    {
		// Swap elements
		temp = arr[j];
		arr[j] = arr[j + 1];
		arr[j + 1] = temp;
		swaps++;
	    }
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
    int i,n;
    int arr[MAX];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++)
    {
	scanf("%d", &arr[i]);
    }


    printf("\nOriginal array: ");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("\nSorted array: ");
    printArray(arr, n);
    getch();
    return 0;
}
