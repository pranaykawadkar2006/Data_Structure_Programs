#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char *revstr(char *s)
{
    int i;
    int j = strlen(s) - 1;

    for (i = 0; i < j; i++, j--)
    {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }

    return s;
}

int prec(char c)
{
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

char *infixToPostfix(char *in)
{
    int n = strlen(in);
    char *out = malloc(n + 1);
    char st[1000];
    int top = -1;
    int i, j = 0;

    for (i = 0; in[i]; i++)
    {
        if (isalnum(in[i]))
        {
            out[j++] = in[i];
        }
        else if (in[i] == '(')
        {
            st[++top] = '(';
        }
        else if (in[i] == ')')
        {
            while (top != -1 && st[top] != '(')
            {
                out[j++] = st[top--];
            }

            if (top != -1)
                top--;
        }
        else
        {
            while (top != -1 &&
                   ((prec(st[top]) > prec(in[i])) ||
                    (prec(st[top]) == prec(in[i]) && in[i] != '^')))
            {
                out[j++] = st[top--];
            }

            st[++top] = in[i];
        }
    }

    while (top != -1)
    {
        out[j++] = st[top--];
    }

    out[j] = '\0';
    return out;
}

int main()
{
    char in[1000];

    scanf("%s", in);

    revstr(in);

    int i;
    for (i = 0; in[i]; i++)
    {
        if (in[i] == '(')
            in[i] = ')';
        else if (in[i] == ')')
            in[i] = '(';
    }

    char *post = infixToPostfix(in);
    revstr(post);

    printf("%s\n", post);

    free(post);

    return 0;
}

