#include <stdio.h>

int main() {
    int arr[] = {-4, -3, -5,1, 3, 3};
    int n = 5;

    int result[n];

    int left = 0;
    int right = n - 1;
    int pos = n - 1;

    while (left <= right) {
        int leftSquare = arr[left] * arr[left];
        int rightSquare = arr[right] * arr[right];

        if (leftSquare > rightSquare) {
            result[pos] = leftSquare;
            left++;
        }
        else {
            result[pos] = rightSquare;
            right--;
        }

        pos--;
    }

    printf("Sorted squares: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}