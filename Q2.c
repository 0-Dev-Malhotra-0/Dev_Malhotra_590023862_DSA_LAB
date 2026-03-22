/*2.Write a C program to implement a Stack using a Linked List. 
 The program should support the following operations using separate functions:
	(i)	Push (Insert): Insert an element into the stack.
	(ii) Pop (Delete): Remove an element from the stack.
	(iii) Display: Display all elements of the stack.
*/

#include<stdio.h>
#include<stdlib.h>

struct stack{
    int data;
    struct stack *next;
};

struct stack *top = NULL;

void push();
void pop();
void display();

int main()
{
    while (1)
    {
        int ch;

        printf("Stack operations");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit\n");

        printf("Enter choice : ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice");
        }
    }
}

void push()
{
    int val;
    struct stack *newnode;

    newnode = (struct stack*)malloc(sizeof(struct stack));

    printf("Enter value: ");
    scanf("%d",&val);

    newnode->data = val;
    newnode->next = top;
    top = newnode;
    
    printf("\n");
}

void pop()
{
    if (top == NULL)
        printf("Stack underflow\n");
    else
    {
        struct stack *temp = top;
        printf("Element popped : %d\n\n", top->data);
        top = top->next;
        free(temp);
    }
}

void display()
{
    struct stack *temp = top;

    if (top == NULL)
        printf("NULL\n\n");
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
