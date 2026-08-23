#include <stdio.h>

int main() {
    int n, sum = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Sum of digits present in the number
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    // Sum of digits from 0 to 9 = 45
    printf("Missing digit = %d\n", 45 - sum);

    return 0;
}