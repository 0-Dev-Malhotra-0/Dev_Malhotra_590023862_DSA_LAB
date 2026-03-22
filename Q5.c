/* 5. Write a C program to convert a given infix expression (A+B*(C^D-E)^(F+G*H)-I) 
into its corresponding postfix expression (ABCD^E-FGH*+^*+I-) using a stack implemented with arrays
*/

/* Infix to Postfix using stack (array) */

#include<stdio.h>
#include<ctype.h>

#define MAX 100

int precedence(char c) 
{
    if (c == '^') 
        return 3;
    if (c == '*' || c == '/' || c == '%') 
        return 2;
    if (c == '+' || c == '-') 
        return 1;
    
    return 0; 
}

int main() 
{
    char exp[MAX], postfix[MAX], stack[MAX];
    int top_stack = -1, top_postfix = -1;
    int i;

    printf("Enter infix expression: ");
    fgets(exp, sizeof(exp), stdin);

    for (i = 0; exp[i] != '\0'; i++) 
    {
        char c = exp[i];

        if (isspace(c)) 
            continue;

        if (isalnum(c)) 
            postfix[++top_postfix] = c;
    
        else if (c == '(' || c == '[' || c == '{') 
            stack[++top_stack] = c;
        
    
        else if (c == ')' || c == ']' || c == '}') 
        {
            char target = (c == ')') ? '(' : (c == ']' ? '[' : '{');
            
            while (top_stack != -1 && stack[top_stack] != target) 
                postfix[++top_postfix] = stack[top_stack--];
            
            if (top_stack != -1) 
                top_stack--; 
        }
        
        else 
        {
            while (top_stack != -1 &&
                  ((precedence(stack[top_stack]) > precedence(c)) ||
                   (precedence(stack[top_stack]) == precedence(c) && c != '^')))
                postfix[++top_postfix] = stack[top_stack--];
    
            stack[++top_stack] = c; 
        }
    }

    while (top_stack != -1) 
        postfix[++top_postfix] = stack[top_stack--];
    

    postfix[++top_postfix] = '\0';
    printf("Postfix Result: %s", postfix);

    return 0;
}
