/* 4. Write a C program to implement deletion operations on a singly linked list. The program 
should support deleting an element from: 
-> The beginning of the linked list 
-> The end of the linked list 
-> After a given node (specified by its value)*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void DeleteFromBeg(struct node **start) 
{
    if (*start == NULL) 
	{
        printf("List is empty.\n");
        return;
    }

    struct node *temp = *start;
    *start = temp->next;
    free(temp);

    printf("First node deleted.\n");
}

void DeleteFromEnd(struct node **start) 
{	
    if (*start == NULL) 
	{
        printf("List is empty.\n");
        return;
    }

    if ((*start)->next == NULL) 
	{
        free(*start);
        *start = NULL;
        printf("Last node deleted.\n");
        return;
    }

    struct node *ptr = *start;

    while (ptr->next->next != NULL)
        ptr = ptr->next;

    free(ptr->next);
    ptr->next = NULL;

    printf("Last node deleted.\n");
}

void DeleteAfterValue(struct node **start) 
{
	int key;
	
	printf("Enter element to delete node after it: ");
    scanf("%d", &key);
    
    if (*start == NULL) 
	{
        printf("List is empty.\n");
        return;
    }

    struct node *ptr = *start;

    while (ptr != NULL && ptr->data != key)
        ptr = ptr->next;

    if (ptr == NULL) 
	{
        printf("Key not found.\n");
        return;
    }

    if (ptr->next == NULL) 
	{
        printf("No node exists after the given key.\n");
        return;
    }

    struct node *temp = ptr->next;
    ptr->next = temp->next;
    free(temp);

    printf("Node after %d deleted.\n", key);
}

void Display(struct node *start)
{
    while (start != NULL)
    {
        printf("%d -> ", start->data);
        start = start->next;
    }
    printf("NULL\n");
}

int main() 
{
    struct node *start = NULL, *ptr = NULL, *newnode = NULL;
    int i, n, key;
    
    printf("Enter number of nodes : ");
    scanf("%d",&n);

	for(i= 0; i < n; i++) 
    {
        newnode = malloc(sizeof(struct node));
        
        printf("Enter data : ");
        scanf("%d", &newnode->data);
        
		newnode->next = NULL;
        
		if (start == NULL) 
            start = ptr = newnode;
       
	    else 
		{
            ptr->next = newnode;
            ptr = newnode;
        }
    }
    
    printf("\n\tOrignal List\n");
    Display(start);
	
	int option = 0;
	
	while(option != 4)
	{
		printf("\n1. Delete at beginning");
		printf("\n2. Delete at end");
		printf("\n3. Delete after value");
		printf("\n4. Exit\n");
		
		printf("\nEnter Choice : ");
		scanf("%d",&option);
		
		switch (option)
		{
			case 1:
				DeleteFromBeg(&start);
    			Display(start);
    			break;
			
			case 2:
				DeleteFromEnd(&start);
    			Display(start);
    			break;
    		
			case 3:
				DeleteAfterValue(&start); 
    			Display(start);
    			break;
    		
			case 4:
				break;
					
    		default:
    			printf("Enter between 1 and 4");
    	}
	}
	
    return 0;
}

