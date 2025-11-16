#include <stdio.h>
#include <string.h>
#include <ctype.h>

char st[1000];
int top = -1;

void push(char c)
{
    st[++top] = c;
}

char pop()
{
    if (top == -1)
        return 0;

    return st[top--];
}

char peek()
{
    if (top == -1)
        return 0;

    return st[top];
}

int prec(char c)
{
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

int main()
{
    char in[1000], out[1000];
    int i, j = 0;
    char c;

    scanf("%s", in);

    for (i = 0; in[i]; i++)
    {
        if (isalnum(in[i]))
        {
            out[j++] = in[i];
        }
        else if (in[i] == '(')
        {
            push('(');
        }
        else if (in[i] == ')')
        {
            while ((c = pop()) && c != '(')
            {
                out[j++] = c;
            }
        }
        else
        {
            while (top != -1 &&
                   ((prec(peek()) > prec(in[i])) ||
                    (prec(peek()) == prec(in[i]) && in[i] != '^')))
            {
                out[j++] = pop();
            }

            push(in[i]);
        }
    }

    while (top != -1)
    {
        out[j++] = pop();
    }

    out[j] = '\0';

    printf("%s\n", out);

    return 0;
}

