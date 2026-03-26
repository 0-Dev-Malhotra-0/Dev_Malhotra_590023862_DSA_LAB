/* 4. Write a C program to implement a Circular Queue using an array 
	  of fixed size using the following functions for each operation.
	(i)	Insert (Enqueue): Add an element to the Circular Queue.
	(ii) Delete (Dequeue): Remove an element from the Circular Queue.
	(iii) Display: Display all elements of the Circular Queue.
	
*/

#include<stdio.h>

int front = -1, rear = -1;

void enqueue(int queue[], int max)
{
    int val;

    if ((rear == max - 1 && front == 0) || (rear + 1 == front))  
        printf("Queue overflow\n");
    
    else
    {
        printf("Enter value: ");
        scanf("%d",&val);
        
        if (front == -1)   
            front = 0;

        rear = (rear + 1) % max;
        queue[rear] = val;
    }
}

void dequeue(int queue[], int max)
{
    if (rear == -1)  
        printf("Queue underflow\n");
    

    else if (front == rear)   
    {
        printf("Element popped : %d\n", queue[front]);
        front = -1;
        rear = -1;
    }

    else
    {
        printf("Element popped : %d\n", queue[front]);
        front = (front + 1) % max;
    }
}

void display(int queue[], int max)
{
    int i;

    if (rear == -1)
        printf("NULL\n");


    else
    {
        if (front <= rear)
        {
            for (i = front; i <= rear; i++)
                printf("%d ", queue[i]);
        }
        
        else
        {
            for (i = front; i < max; i++)
                printf("%d ", queue[i]);

            for (i = 0; i <= rear; i++)
                printf("%d ", queue[i]);
        }

        printf("\n");
    }
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
        printf("\n4. Exit\n");

        printf("Enter choice : ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1:
                enqueue(queue, max);
                break;

            case 2:
                dequeue(queue, max);
                break;

            case 3:
                display(queue, max);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
