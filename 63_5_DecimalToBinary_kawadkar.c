#include <stdio.h>
#include <string.h>

int top = -1;
char st[1000];

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

int match(char a, char b)
{
    if (a == '(' && b == ')') return 1;
    if (a == '[' && b == ']') return 1;
    if (a == '{' && b == '}') return 1;
    return 0;
}

int main()
{
    char s[1000];
    int i;
    char c;

    scanf("%s", s);

    for (i = 0; s[i]; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            push(s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            c = pop();

            if (!match(c, s[i]))
            {
                printf("Not Balanced\n");
                return 0;
            }
        }
    }

    if (top == -1)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
