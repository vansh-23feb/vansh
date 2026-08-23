#include <stdio.h>

int main() {
    int nums[] = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    int n = 9;

    int low = 0;
    int high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        // Make mid even
        if (mid % 2 == 1)
            mid--;

        if (nums[mid] == nums[mid + 1]) {
            // Single element is on the right
            low = mid + 2;
        } else {
            // Single element is on the left or at mid
            high = mid;
        }
    }

    printf("Single element = %d", nums[low]);

    return 0;
}