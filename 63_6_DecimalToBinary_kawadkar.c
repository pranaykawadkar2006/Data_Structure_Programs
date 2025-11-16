#include <stdio.h>

int main()
{
    int n;
    int b[32];
    int i = 0;

    scanf("%d", &n);

    if (n == 0)
    {
        printf("0\n");
        return 0;
    }

    while (n)
    {
        b[i++] = n % 2;
        n /= 2;
    }

    while (i--)
    {
        printf("%d", b[i]);
    }

    printf("\n");

    return 0;
}

