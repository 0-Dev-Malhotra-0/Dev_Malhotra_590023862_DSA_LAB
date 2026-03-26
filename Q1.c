/* 1.Write a C program to implement a Queue data structure using an array. 
     The program should be modular and use separate functions for each operation.
	(i)Insert (Enqueue): Add an element to the Queue.
	(ii)Delete (Dequeue): Remove an element from the Queue.
	(iii)Display: Display all elements of the Queue.
	(iv)Peek: Display the front element of the Queue.
*/

#include<stdio.h>

int front = 0, rear = -1;

void enqueue(int queue[], int max)
{
    int val;

    if (rear == max - 1)
        printf("Queue overflow\n");

    else
    {
        printf("Enter value: ");
        scanf("%d",&val);

        queue[++rear] = val;
    }
}

void dequeue(int queue[])
{
    if (front > rear)
    {
    	printf("Queue underflow\n");
    	front = 0;
    	rear = -1;
	}
    
    else
        printf("Element popped : %d\n", queue[front++]);
}

void display(int queue[])
{
    int i;

    if (rear == -1 || front > rear)
        printf("NULL");

    else
    {
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }

    printf("\n");
}

void peek(int queue[])
{
    if (rear == -1 || front > rear)
        printf("NULL");

    else    
        printf("First element is : %d ", queue[front]);

    printf("\n");
}

int main()
{
    int max;

    printf("Enter max size : ");
    scanf("%d",&max);

    int queue[max];

    while (1)
    {
        int ch;

        printf("\nQueue operations");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Peek");
        printf("\n5. Exit\n");

        printf("Enter choice : ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1:
                enqueue(queue, max);
                break;

            case 2:
                dequeue(queue);
                break;

            case 3:
                display(queue);
                break;

            case 4:
                peek(queue);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice");
        }
    }
}

