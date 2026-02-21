/* 6. Write a C program to implement a Circular Singly Linked List and perform all basic operations on it. The program must support the following operations:
->	Creation of a Circular Linked List
->	Insertion of a node (At the beginning and at the end of the list)
->	Deletion of a node (From the beginning and from the end of the list)
->	Traversal and display of the circular linked list and counting the number of nodes in the list
*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void InsertAtBeg(struct node **start)
{
    int val;
    printf("Enter value: ");
    scanf("%d", &val);

    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;

    if(*start == NULL)
    {
        *start = newnode;
        newnode->next = *start;
        return;
    }

    struct node *ptr = *start;

    while(ptr->next != *start)
        ptr = ptr->next;

    newnode->next = *start;
    ptr->next = newnode;
    *start = newnode;
}

void InsertAtEnd(struct node **start)
{
    int val;
    printf("Enter value: ");
    scanf("%d", &val);

    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;

    if(*start == NULL)
    {
        *start = newnode;
        newnode->next = *start;
        return;
    }

    struct node *ptr = *start;

    while(ptr->next != *start)
        ptr = ptr->next;

    ptr->next = newnode;
    newnode->next = *start;
}

void DeleteFromBeg(struct node **start)
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

    struct node *ptr = *start;

    while(ptr->next != *start)
        ptr = ptr->next;

    struct node *temp = *start;
    ptr->next = temp->next;
    *start = temp->next;
    free(temp);
}

void DeleteFromEnd(struct node **start)
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

    struct node *ptr = *start;

    while(ptr->next->next != *start)
        ptr = ptr->next;

    free(ptr->next);
    ptr->next = *start;
}

void Display(struct node *start)
{
    if(start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *ptr = start;
    int count = 0;

    do
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
        count++;
    }
    
    while(ptr != start);

    printf("(back to start)\n");
    printf("Total nodes: %d\n", count);
}

int main()
{
    struct node *start = NULL, *newnode = NULL, *ptr = NULL;
    int choice = 0, n, i, val;

    printf("Enter number of nodes : ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d", &val);

        newnode->data = val;

        if(start == NULL)
        {
            start = newnode;
            newnode->next = start;
            ptr = start;
        }
        else
        {
            ptr->next = newnode;
            newnode->next = start;
            ptr = newnode;
        }
    }
    
    printf("\nOrignal List\n");
    Display(start);
    
    while(choice != 5)
    {
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Delete from Beginning");
        printf("\n4. Delete from End");
        printf("\n5. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: 
				InsertAtBeg(&start);
				Display(start); 
				break;
            case 2: 
				InsertAtEnd(&start);
				Display(start); 
				break;
            case 3: 
				DeleteFromBeg(&start);
				Display(start); 
				break;
            case 4: 
				DeleteFromEnd(&start); 
				Display(start);
				break;
            case 5: 
				break;
            default: 
				printf("Invalid choice\n");
        }
    }

    return 0;
}

