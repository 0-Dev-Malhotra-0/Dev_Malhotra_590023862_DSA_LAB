/* 5.Write a C program to implement a Stack using two Queues.
	 The queues must be implemented using arrays, and all operations should be performed using functions.
	(i)	Push: Insert an element into the stack.
	(ii) Pop: Remove the top element from the stack.
	(iii) Peek: Display the top element without removing it.
	(iv) isEmpty: Check whether the stack is empty.
	(v)	Display: Print all elements of the stack.
*/	

#include<stdio.h>

#define MAX 100

int q1[MAX], q2[MAX];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

void enqueue1(int val)
{
    if (rear1 == MAX-1)
        return;

    if (front1 == -1)
        front1 = 0;

    q1[++rear1] = val;
}

int dequeue1()
{
    int val = q1[front1];

    if (front1 == rear1)
        front1 = rear1 = -1;
    else
        front1++;

    return val;
}

void enqueue2(int val)
{
    if (rear2 == MAX-1)
        return;

    if (front2 == -1)
        front2 = 0;

    q2[++rear2] = val;
}

int dequeue2()
{
    int val = q2[front2];

    if (front2 == rear2)
        front2 = rear2 = -1;
    else
        front2++;

    return val;
}


void push()
{
    int val, i;

    printf("Enter value: ");
    scanf("%d",&val);

    enqueue2(val);

    while (front1 != -1)
        enqueue2(dequeue1());

    for (i = front2; i <= rear2; i++)
        q1[i] = q2[i];

    front1 = front2;
    rear1 = rear2;

    front2 = rear2 = -1;
}

void pop()
{
    if (front1 == -1)
    {
        printf("Stack empty\n");
        return;
    }

    printf("Element popped: %d\n", dequeue1());
}

void peek()
{
    if (front1 == -1)
        printf("Stack empty\n");
        
    else
        printf("Top element: %d\n", q1[front1]);
}

void isEmpty()
{
    if (front1 == -1)
        printf("Stack is empty\n");
        
    else
        printf("Stack not empty\n");
}

void display()
{
    int i;

    if (front1 == -1)
    {
        printf("Stack empty\n");
        return;
    }

    printf("Stack elements:\n");

    for (i = front1; i <= rear1; i++)
        printf("%d ", q1[i]);

    printf("\n");
}


int main()
{
    int ch;

    while (1)
    {
        printf("\n1 Push");
        printf("\n2 Pop");
        printf("\n3 Peek");
        printf("\n4 isEmpty");
        printf("\n5 Display");
        printf("\n6 Exit");

        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: 
				push(); 
				break;
            
			case 2: 
				pop(); 
				break;
            
			case 3: 
				peek(); 
				break;
            
			case 4: 
				isEmpty(); 
				break;
            
			case 5: 
				display(); 
				break;
            
			case 6: 
				return 0;
            
			default: 
				printf("Invalid\n");
        }
    }
}
