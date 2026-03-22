/* 6.Write a C program to evaluate a postfix expression using a stack implemented with an array. 
	(i)	Postfix Expression: 23*54*+9-
	(ii) Result = 17
*/

#include<stdio.h>
#include<ctype.h>
#include<math.h>

#define MAX 100

int main() 
{
    char exp[MAX];
    int operan[MAX];   
    int top_operan = -1;
    int i, a, b, n;

    printf("Enter postfix expression : ");
    fgets(exp, sizeof(exp), stdin);

    for (i = 0; exp[i] != '\0'; i++) 
    {
        char c = exp[i];

        if (isspace(c)) 
            continue;

        if (isdigit(c)) 
            operan[++top_operan] = c - '0';
    
        else 
        {
            if (c == '^' || c == '%' ||
                c == '*' || c == '/' ||
                c == '+' || c == '-' )
            {
                b = operan[top_operan--];
                a = operan[top_operan--];
                
            switch(c)
			{
			    case '+': 
					n = a + b; 
					break;
					
			    case '-': 
					n = a - b; 
					break;
					
			    case '*': 
					n = a * b; 
					break;
					
			    case '/': 
					n = a / b; 
					break;
					
			    case '%': 
					n = a % b; 
					break;
					
			    case '^': 
					n = pow(a,b); 
					break;
			}
                    
                operan[++top_operan] = n;
            }
        }
    }
    
    printf("Result: %d", operan[top_operan]);

    return 0;
}
