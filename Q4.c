/* 4. Write a program to check whether a given expression is balanced or not
   using a stack implemented with an array.
*/

#include<stdio.h>

#define MAX 100

int main()
{
    char exp[MAX];
    char stack[MAX];
    int top = -1;
    int i;

    printf("Enter expression : ");
    fgets(exp, sizeof(exp), stdin);

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
        {
            top++;
            stack[top] = exp[i];
        }

        else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
        {
            if (top == -1)
            {
                printf("Not balanced");
                return 0;
            }

            if ((exp[i] == '}' && stack[top] != '{') ||
                (exp[i] == ']' && stack[top] != '[') ||
                (exp[i] == ')' && stack[top] != '('))
            {
                printf("Not balanced");
                return 0;
            }

            top--;
        }
        
        else
        	continue;
    }

    if (top == -1)
        printf("Balanced expression");
    else
        printf("Not balanced");

    return 0;
}
