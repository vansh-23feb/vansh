#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    int i, j, flag = 1;

    printf("Enter string: ");
    gets(str);

    i = 0;
    j = strlen(str) - 1;

    while (i < j) {
        if (str[i] == ' ')
            i++;
        else if (str[j] == ' ')
            j--;
        else {
            if (tolower(str[i]) != tolower(str[j])) {
                flag = 0;
                break;
            }
            i++;
            j--;
        }
    }

    if (flag)
        printf("Palindrome");
    else
        printf("Not Palindrome");

    return 0;
}