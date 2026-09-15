#include <stdio.h>

int main() {
    int nums1[] = {1, 3};
    int nums2[] = {2};

    int m = 2;
    int n = 1;

    int arr[m + n];

    int i = 0, j = 0, k = 0;

    // Merge both sorted arrays
    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            arr[k] = nums1[i];
            i++;
        }
        else {
            arr[k] = nums2[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of nums1
    while (i < m) {
        arr[k] = nums1[i];
        i++;
        k++;
    }

    // Copy remaining elements of nums2
    while (j < n) {
        arr[k] = nums2[j];
        j++;
        k++;
    }

    int total = m + n;
    double median;

    if (total % 2 == 1) {
        median = arr[total / 2];
    }
    else {
        median = (arr[total / 2 - 1] + arr[total / 2]) / 2.0;
    }

    printf("Median = %.2f", median);

    return 0;
}