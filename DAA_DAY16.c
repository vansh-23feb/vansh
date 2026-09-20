#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        char s[1000];
        scanf("%s", s);

        int n = strlen(s);

        int lower = 0;
        int upper = 0;
        int digit = 0;
        int special = 0;

        // Check lowercase letter
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                lower = 1;
            }
        }

        // Check uppercase, digit and special character
        // strictly inside the string
        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                upper = 1;
            }

            if (s[i] >= '0' && s[i] <= '9')
            {
                digit = 1;
            }

            if (s[i] == '@' || s[i] == '#' || 
                s[i] == '%' || s[i] == '&' || s[i] == '?')
            {
                special = 1;
            }
        }

        if (n >= 10 && lower && upper && digit && special)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}