#include <stdio.h>

int main() {
    int arr[100], n, target;
    int i, j;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter target value: ");
    scanf("%d", &target);

    printf("\nPairs whose sum is %d:\n", target);

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {

            if (arr[i] + arr[j] == target) {
                printf("(%d, %d)\n", arr[i], arr[j]);
            }

        }
    }

    return 0;
}