#include <stdio.h>
#include <limits.h>

int main() {
    int n, i;
    int arr[100];
    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    if (secondLargest == INT_MIN) {
        printf("Second-largest distinct element does not exist.\n");
    }
    else {
        printf("Second-largest distinct element = %d\n", secondLargest);
    }

    return 0;
}