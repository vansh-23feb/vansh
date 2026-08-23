#include <stdio.h>

int main() {
    int n, bit;
    int count1 = 0, count0 = 0;
    int consecutive1 = 0, maxConsecutive1 = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    // Special case for 0
    if (n == 0) {
        printf("Binary representation: 0\n");
        printf("Number of 1s = 0\n");
        printf("Number of 0s = 1\n");
        printf("Maximum consecutive 1s = 0\n");
        return 0;
    }

    while (n > 0) {
        bit = n % 2;

        if (bit == 1) {
            count1++;
            consecutive1++;

            if (consecutive1 > maxConsecutive1) {
                maxConsecutive1 = consecutive1;
            }
        } else {
            count0++;
            consecutive1 = 0;
        }

        n = n / 2;
    }

    printf("Number of 1s = %d\n", count1);
    printf("Number of 0s = %d\n", count0);
    printf("Maximum consecutive 1s = %d\n", maxConsecutive1);

    return 0;
}