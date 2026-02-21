/* 8. Write a C program to implement a Doubly Circular Linked List. The program should perform all basic operations on the list. The program must support the following operations:
->	Creation of a Doubly Circular Linked List, display and counting the number of nodes
->	Insertion of a node (At the beginning, At the end)
->	Deletion of a node (From the beginning, From the end)
*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

void insertBeg(struct node **start)
{
    int val;
    printf("Enter value: ");
    scanf("%d",&val);

    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;

    if(*start == NULL)
    {
        newnode->next = newnode;
        newnode->prev = newnode;
        *start = newnode;
        return;
    }

    struct node *last = (*start)->prev;

    newnode->next = *start;
    newnode->prev = last;

    last->next = newnode;
    (*start)->prev = newnode;

    *start = newnode;
}

void insertEnd(struct node **start)
{
    int val;
    printf("Enter value: ");
    scanf("%d",&val);

    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;

    if(*start == NULL)
    {
        newnode->next = newnode;
        newnode->prev = newnode;
        *start = newnode;
        return;
    }

    struct node *last = (*start)->prev;

    newnode->next = *start;
    newnode->prev = last;

    last->next = newnode;
    (*start)->prev = newnode;
}

void deleteBeg(struct node **start)
{
    if(*start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if((*start)->next == *start)
    {
        free(*start);
        *start = NULL;
        return;
    }

    struct node *last = (*start)->prev;
    struct node *temp = *start;

    *start = temp->next;

    last->next = *start;
    (*start)->prev = last;

    free(temp);
}

void deleteEnd(struct node **start)
{
    if(*start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if((*start)->next == *start)
    {
        free(*start);
        *start = NULL;
        return;
    }

    struct node *last = (*start)->prev;
    struct node *newLast = last->prev;

    newLast->next = *start;
    (*start)->prev = newLast;

    free(last);
}

void display(struct node *start)
{
    if(start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *ptr = start;

    do
    {
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    } while(ptr != start);

    printf("(Back to Start)\n");
}

void countNodes(struct node *start)
{
    if(start == NULL)
    {
        printf("Total nodes: 0\n");
        return;
    }

    int count = 0;
    struct node *ptr = start;

    do
    {
        count++;
        ptr = ptr->next;
    } while(ptr != start);

    printf("Total nodes: %d\n",count);
}

int main()
{
    struct node *start = NULL;
    int choice;

    while(choice != 7)
    {
        printf("--- Doubly Circular Linked List ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Count Nodes\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: 
				insertBeg(&start); 
				break;
            case 2: 
				insertEnd(&start); 
				break;
            case 3: 
				deleteBeg(&start);
				break;
            case 4: 
				deleteEnd(&start); 
				break;
            case 5: 
				display(start); 
				break;
            case 6: 
				countNodes(start); 
				break;
            case 7: 
				break;
            default: 
				printf("Invalid choice\n");
        }
         printf("\n");
    }
    return 0;
}
