/* 2.Write a C program to implement a Queue using a Linked List. 
     The program should support the following operations using separate functions:
	(i)	Enqueue (Insert): Insert an element into the Queue.
	(ii) Dequeue (Delete): Remove an element from the Queue.
	(iii) Display: Display all elements of the Queue.
	(iv) Peek: Display the front element of the Queue.
*/

#include<stdio.h>
#include<stdlib.h>

struct queue{
    int data;
    struct queue *next;
};

struct queue *front = NULL, *rear = NULL;

void enqueue()
{
    int val;
    struct queue *newnode;

    newnode = (struct queue*)malloc(sizeof(struct queue));

    printf("Enter value: ");
    scanf("%d",&val);

    newnode->data = val;
    newnode->next = NULL;

    if (front == NULL)
    {
        front = newnode;
        rear = front;
    }
    
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
    
    printf("\n");
}

void dequeue()
{
    struct queue *temp;

    if (front == NULL)
        printf("Queue underflow\n");

    else
    {
        temp = front;
        printf("Element deleted : %d\n", front->data);

        front = front->next;
        free(temp);

        if (front == NULL)
            rear = NULL;
    }
    
    printf("\n");
}

void display()
{
    struct queue *temp = front;

    if (front == NULL)
        printf("NULL\n");

    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    
    printf("\n");
}

void peek()
{
    if (front == NULL)
        printf("NULL\n");

    else
        printf("Front element = %d\n", front->data);

	printf("\n");
}

int main()
{
    while (1)
    {
        int ch;

        printf("Queue operations");
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
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                peek();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}

