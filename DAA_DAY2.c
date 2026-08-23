#include <stdio.h>
#include <string.h>

int main() {
    char password[50];

    while (1) {
        printf("Enter password: ");
        scanf("%s", password);

        if (strcmp(password, "12345") == 0) {
            break;
        }

        printf("Incorrect password. Try again.\n");
    }

    printf("Login successful!");

    return 0;
}