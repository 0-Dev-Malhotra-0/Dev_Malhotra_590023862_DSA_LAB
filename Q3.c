/* 3. Write a C program to implement insertion operations in a singly linked list. The program 
should perform the following operations: 
-> Insert a new element at the beginning of the linked list. 
-> Insert a new element at the end of the linked list. 
-> Insert a new element after a given node(specified by value) in the linked list.*/

#include<stdio.h>
#include<stdlib.h>

struct node {
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
	newnode->next = *start;
	*start = newnode;
}

void InsAtEnd(struct node **start) 
{
	int val;
	
	printf("Enter element to add : ");
	scanf("%d",&val);
	
	struct node *newnode = malloc(sizeof(struct node));
	struct node *ptr = *start;
	
	newnode->data = val;
	newnode->next = NULL;
	
	if(*start == NULL) 
	{
		*start = newnode;
		return;
	}
	
	while (ptr->next != NULL) 
		ptr = ptr->next;
		
	ptr->next = newnode;
}

void InsAfterValue(struct node **start) 
{
	int val, key;
    printf("Enter element to add : ");
	scanf("%d",&val);
	
	printf("Enter key after you want to add : ");
	scanf("%d",&key);
	
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

    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = ptr->next;
    ptr->next = newnode;
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
    struct node *start = NULL;
	
	int option = 0;
	
	while(option != 4)
	{
		printf("1. Insert at beginning");
		printf("\n2. Insert at end");
		printf("\n3. Insert after value");
		printf("\n4. Exit\n");
		
		printf("\nEnter Choice : ");
		scanf("%d",&option);
		
		switch (option)
		{
			case 1:
				InsAtBegn(&start);
    			Display(start);
    			break;
			
			case 2:
				InsAtEnd(&start);
    			Display(start);
    			break;
    		
			case 3:
				InsAfterValue(&start);   
    			Display(start);
    			break;
    		
			case 4:
				break;
					
    		default:
    			printf("Enter between 1 and 4");
    	}
    	
    	printf("\n");
	}
    

    return 0;
}
