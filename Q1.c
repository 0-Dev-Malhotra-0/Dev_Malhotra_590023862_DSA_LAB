/*1.Write a C program to implement a Stack data structure using an array.
 The program should be modular and use separate functions for each operation.
	(i)	Insert (Push): Add an element to the top of the stack.
	(ii) Delete (Pop): Remove an element from the top of the stack.
	(iii) Display: Display all elements of the stack from top to bottom.
*/

#include<stdio.h>

int top = -1;

void push(int stack[], int max);
void pop();
void display(int stack[]);

int main()
{
    int max;

    printf("Enter max size : ");
    scanf("%d",&max);

    int stack[max];   

    while (1)
    {
        int ch;

        printf("\nStack operations");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit\n");

        printf("Enter choice : ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1:
                push(stack, max);
                break;

            case 2:
                pop(stack);
                break;

            case 3:
                display(stack);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice");
        }
    }
}

void push(int stack[], int max)
{
    int val;

    if (top == max - 1)
        printf("Stack overflow\n");

    else
    {
        printf("Enter value: ");
        scanf("%d",&val);

        stack[++top] = val;
    }
}

void pop(int stack[])
{
    if (top == -1)
        printf("Stack underflow\n");
    else
    	printf("Element popped : %d\n",stack[top--]);
    	
}

void display(int stack[])
{
    int i;

    if (top == -1)
        printf("NULL");

    else
    {
        for (i = top; i >= 0; i--)
            printf("%d ", stack[i]);
    }
    
    printf("\n");
}
