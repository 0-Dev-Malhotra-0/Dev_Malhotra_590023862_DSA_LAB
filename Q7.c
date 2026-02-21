/* 7. Write a C program to implement a Doubly Linked List. The program should perform all basic operations on the list. The program must support the following operations:
->	Creation of a Doubly Linked List, display and counting the number of nodes
->	Insertion of a node (At the beginning, At the end, After a given node)
->	Deletion of a node (From the beginning, From the end, of a given node)
->	Traversal of the list (Forward traversal and Backward traversal)
*/

#include<stdio.h>
#include<stdlib.h>

struct node {
	struct node *prev;
    int data;
    struct node *next;
};

void InsAtBegn(struct node **start) 
{
	int val;
	printf("Enter element to add : ");
	scanf("%d",&val);
	
	struct node *newnode = malloc(sizeof(struct node));
	newnode->data = val;
	newnode->prev = NULL;
	newnode->next = *start;
	
	if(*start != NULL)
        (*start)->prev = newnode;

	*start = newnode;
}

void InsAtEnd(struct node **start)
{
    int val;
    printf("Enter element: ");
    scanf("%d",&val);

    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;

    if(*start == NULL)
    {
        newnode->prev = NULL;
        *start = newnode;
        return;
    }

    struct node *ptr = *start;
    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = newnode;
    newnode->prev = ptr;
}

void InsAfterValue(struct node **start)
{
    int val, key;
    printf("Enter element: ");
    scanf("%d",&val);
    printf("Enter key: ");
    scanf("%d",&key);

    struct node *ptr = *start;

    while(ptr != NULL && ptr->data != key)
        ptr = ptr->next;

    if(ptr == NULL)
    {
        printf("Key not found\n");
        return;
    }

    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;

    newnode->next = ptr->next;
    newnode->prev = ptr;

    if(ptr->next != NULL)
        ptr->next->prev = newnode;

    ptr->next = newnode;
}

void DeleteFromBeg(struct node **start)
{
    if(*start == NULL)
    {
        printf("List empty\n");
        return;
    }

    struct node *temp = *start;
    *start = temp->next;

    if(*start != NULL)
        (*start)->prev = NULL;

    free(temp);
}

void DeleteFromEnd(struct node **start)
{
    if(*start == NULL)
    {
        printf("List empty\n");
        return;
    }

    struct node *ptr = *start;

    if(ptr->next == NULL)
    {
        free(ptr);
        *start = NULL;
        return;
    }

    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->prev->next = NULL;
    free(ptr);
}

void DeleteAfterValue(struct node **start)
{
    int key;
    printf("Enter key: ");
    scanf("%d",&key);

    struct node *ptr = *start;

    while(ptr != NULL && ptr->data != key)
        ptr = ptr->next;

    if(ptr == NULL || ptr->next == NULL)
    {
        printf("Deletion not possible\n");
        return;
    }

    struct node *temp = ptr->next;

    ptr->next = temp->next;

    if(temp->next != NULL)
        temp->next->prev = ptr;

    free(temp);
}

void Forward_Traversal(struct node *start)
{
    while(start != NULL)
    {
        printf("%d <-> ", start->data);
        start = start->next;
    }
    printf("NULL\n");
}

void Backward_Traversal(struct node *start)
{
    if(start == NULL)
        return;

    while(start->next != NULL)
        start = start->next;

    while(start != NULL)
    {
        printf("%d <-> ", start->data);
        start = start->prev;
    }
    printf("NULL\n");
}

int main()
{
    struct node *start = NULL;
    int choice = 1;

    while(choice != 9)
    {
        printf("--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After Value\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete After Value\n");
        printf("7. Forward Traversal\n");
        printf("8. Backward Traversal\n");
        printf("9. Exit\n");
        
        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: 
				InsAtBegn(&start); 
				break;
            case 2: 
				InsAtEnd(&start); 
				break;
            case 3: 
				InsAfterValue(&start); 
				break;
            case 4: 
				DeleteFromBeg(&start); 
				break;
            case 5: 
				DeleteFromEnd(&start); 
				break;
            case 6: 
				DeleteAfterValue(&start); 
				break;
            case 7: 	
				Forward_Traversal(start); 
				break;
            case 8: 
				Backward_Traversal(start); 
				break;
            case 9: 
				break;
            default: 
				printf("Invalid choice\n");
        }
        printf("\n");
    }
    
    return 0;
}

